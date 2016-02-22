//
//  API.swift
//  SwiftCompanions
//
//  Created by Bruno GANTELMI on 2/21/16.
//  Copyright © 2016 Bruno GANTELMI. All rights reserved.
//

import Foundation
import JSONJoy
import SwiftHTTP

class API
{
    static weak var dashDelegate : DashViewController?
    static var uid = "95b30248aca965ce575a516da38059a4de5196542da8389db4b7a8c04091d2ff"
    static var secret = "772571e2c702d7473c4092e7ede5b0253c20c1ea8d23e3c84020ba5ba120d4a7"
    
    static var APIURL = "https://api.intra.42.fr"
    static var API_TOKEN = APIURL + "/oauth/token"
    static var API_USER = APIURL + "/v2/users/"
    
    
    static func getToken(user : String?)
    {
        let params = ["grant_type": "client_credentials", "client_id": self.uid, "client_secret" : self.secret]
        do
        {
            let opt = try HTTP.POST(self.API_TOKEN, parameters: params)
            opt.start
            {
                response in
                print(Globals.token?.access_token)
                if let error = response.error
                {
                    print("got an error: \(error)")
                    return
                }
                
                do
                {
                    Globals.token = try Token(JSONDecoder(response.data))
                    dispatch_async(dispatch_get_main_queue(),
                    {
//                        self.dashDelegate?.gotUser()
                    })
                    self.getUser(user)
                }
                catch
                {
                    print("unable to parse the JSON")
                }
            }
        }
        catch let error
        {
            print("got an error creating the request: \(error)")
        }
    }
    
    static func getUser(user : String?)
    {
        print("salut")
        do
        {
         print(user)
            print(API_USER + user!)
            let opt = try HTTP.GET(self.API_USER + user!, parameters: nil, headers: ["Authorization" : (Globals.token?.token_type ?? "") + " " + (Globals.token?.access_token ?? "")])
            opt.start
                {
                    response in
                    if let error = response.error
                    {
                        print("got an error: \(error)")
                        return
                    }
                    do
                    {
                        Globals.usr = try User(JSONDecoder(response.data))
                        print("bybye")
                        print(Globals.usr?.login)
                       // print(Globals.usr?.mobile)
                        print(Globals.usr?.image_url)
                        dispatch_async(dispatch_get_main_queue(),
                        {
                            self.dashDelegate?.gotUser()
                        })

                    }
                    catch
                    {
                        print("unable to parse the JSON")
                    }
            }
        }
        catch let error
        {
            print("got an error creating the request: \(error)")
        }
    }
}
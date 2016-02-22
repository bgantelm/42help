//
//  User.swift
//  SwiftCompanions
//
//  Created by Bruno GANTELMI on 2/20/16.
//  Copyright © 2016 Bruno GANTELMI. All rights reserved.
//

import Foundation
import JSONJoy

class User
{
    var login: String?
    var phone: String?
    var image_url: String?
    var location: String?
    var wallet: Int?
    var displayname: String?
    var cursus: [Cursus]?

    init(_ decoder: JSONDecoder)
    {
        login =  decoder["login"].string
        phone =  decoder["phone"].string
        image_url =  decoder["image_url"].string
        location =  decoder["location"].string
        wallet =  decoder["wallet"].integer
        displayname =  decoder["displayname"].string
        
        if let crs = decoder["cursus"].array
        {
            print("lolilol")
            self.cursus = [Cursus]()
            for crsDecoder in crs
            {
                self.cursus?.append(Cursus(crsDecoder))
            }
        }
    }
}
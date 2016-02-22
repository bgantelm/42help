//
//  Token.swift
//  SwiftCompanions
//
//  Created by Bruno GANTELMI on 2/21/16.
//  Copyright © 2016 Bruno GANTELMI. All rights reserved.
//

import Foundation
import JSONJoy

class Token
{
    var access_token: String?
    var token_type: String?
    var expires_in : Int?
    var scope : String?
    var created_at : Int?
    
    init(_ decoder: JSONDecoder) throws
    {
        access_token = try decoder["access_token"].getString()
        token_type = try decoder["token_type"].getString()
        expires_in = try decoder["expires_in"].getInt()
        scope = try decoder["scope"].getString()
        created_at = try decoder["created_at"].getInt()
    }
}
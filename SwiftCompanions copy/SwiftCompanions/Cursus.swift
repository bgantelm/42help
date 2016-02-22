//
//  Cursus.swift
//  SwiftCompanions
//
//  Created by Bruno GANTELMI on 2/22/16.
//  Copyright © 2016 Bruno GANTELMI. All rights reserved.
//

import Foundation
import JSONJoy

class Cursus
{
    var level: Float?
    var grade: String?
    init(_ decoder: JSONDecoder)
    {
        level =  decoder["level"].float
        grade =  decoder["grade"].string
    }
}
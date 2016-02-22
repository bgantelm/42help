//
//  ViewController.swift
//  SwiftCompanions
//
//  Created by Bruno GANTELMI on 2/20/16.
//  Copyright © 2016 Bruno GANTELMI. All rights reserved.
//

import UIKit

class DashViewController: UIViewController
{
    // IB Outlets
    @IBOutlet weak var SearchLogin: UITextField!

    // Override
    override func viewDidLoad()
    {
        super.viewDidLoad()
        API.dashDelegate = self
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue!, sender: AnyObject!)
    {
        if (segue.identifier == "ProfileSegue")
        {
            let PVC : UIViewController = segue!.destinationViewController as! ProfileViewController
        }
    }
    // Actions
    @IBAction func ButtonSend(sender: AnyObject)
    {
        Globals.input = SearchLogin.text
        API.getToken(Globals.input)
        //performSegueWithIdentifier("ProfileSegue", sender: nil)
    }
    
    func gotUser()
    {
        performSegueWithIdentifier("ProfileSegue", sender: nil)
    }
    //performSegueWithIdentifier("ProfileSegue", sender: nil)
}


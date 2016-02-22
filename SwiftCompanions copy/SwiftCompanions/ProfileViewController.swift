//
//  ProfileViewController.swift
//  SwiftCompanions
//
//  Created by Bruno GANTELMI on 2/21/16.
//  Copyright © 2016 Bruno GANTELMI. All rights reserved.
//

import UIKit

class ProfileViewController: UIViewController
{
    // IB Outlets

    @IBOutlet weak var Scroll: UIScrollView!

    @IBOutlet weak var ImageProfile: UIImageView!

    @IBOutlet weak var LabelProgress: UIProgressView!
    @IBOutlet weak var LabelPhone: UILabel!
    @IBOutlet weak var LabelLogin: UILabel!
    @IBOutlet weak var LabelLocation: UILabel!

    @IBOutlet weak var LabelGrade: UILabel!
    @IBOutlet weak var LabelLevel: UILabel!
    @IBOutlet weak var LabelWallet: UILabel!

    @IBOutlet weak var LabelDisplayname: UILabel!
    
    //Variables
    var usr : User?

    func downloadImage(url: NSURL)
    {
        getDataFromUrl(url)
            {
                (data, response, error)  in
                dispatch_async(dispatch_get_main_queue())
                    {() -> Void in
                        guard let data = data where error == nil else { return }
                        self.ImageProfile.image = UIImage(data: data)
                        
                        
                }
        }
    }
    func getDataFromUrl(url:NSURL, completion: ((data: NSData?, response: NSURLResponse?, error: NSError? ) -> Void))
    {
        NSURLSession.sharedSession().dataTaskWithURL(url)
            {
                (data, response, error) in
                completion(data: data, response: response, error: error)
            }
            .resume()
    }

    override func viewDidLoad()
    {
        super.viewDidLoad()
        Scroll.contentSize.height = 1000
        
let f = Globals.usr?.cursus![1].level!
        LabelLogin.text = (Globals.usr?.login)!
        LabelProgress.progress = f! - floor(f!)
        LabelPhone.text = (Globals.usr?.phone)!
        LabelGrade.text = "Grade : " + (Globals.usr?.cursus![1].grade)!
        LabelLevel.text = "Level : " + String((Globals.usr?.cursus![1].level)!)
        LabelDisplayname.text = (Globals.usr?.displayname)!
        LabelLocation.text = "Location : " + (Globals.usr?.location)!
        LabelWallet.text = "Wallet : " + String((Globals.usr!.wallet)!)
        if let checkedUrl = NSURL(string: (Globals.usr?.image_url)!) {
            ImageProfile.contentMode = UIViewContentMode.ScaleAspectFill
            self.downloadImage(checkedUrl)
            self.ImageProfile.layer.cornerRadius = self.ImageProfile.frame.size.width/2
            self.ImageProfile.clipsToBounds = true

        }
    }
}

---------------------------------------------------------------------------
Mobile by Mobify 
---------------------------------------------------------------------------
Author: Peter McLachlan  (peter@mobify.me)

(c) Copyright 2009 - Mobify Inc. - All Rights Reserved

http://mobify.me/

To install this module, follow these steps: 

1) Place this folder ('mobify') in the appropriate 'modules' directory.  If you are running a single Drupal site, this directory is: 'DRUPAL_FOLDER/sites/all/modules'.  If you have multiple Drupal sites you should place the Mobify plugin in the specific modules directory for the site or sites running Mobify.  For example 'DRUPAL_FOLDER/sites/widgetco/modules'.  

2) Enable the Mobile by Mobify module in the Modules control panel.  (admin -> Administer -> Site building -> Modules).  See the included screenshot setup1.png.  

3) Configure the Mobile by Mobify plugin.  (admin -> Administer -> Site configuration -> Mobile by Mobify).  Enter your CNAME here.  (Do not put http or any other slashes.  For example, if your site was acmewidgetco.com and you have created a cname m.acmewidgetco.com to point to acmewidgetco.mobify.me, you would enter simply m.acmewidgetco.com.)  See the included screenshot setup2.png.  

4) To confirm the plugin is working, when you visit your site in a standard desktop browser, you should be able to look in your cookies and see a cookie being set with the key 'mobify' and a value of '0'.  If you visit your site with a mobile browser, it should automatically redirect to the mobile view of that page at m.yoursite.com.
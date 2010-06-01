<?php
// $Id: fb_social.admin.inc,v 1.2.2.3 2010/05/29 03:19:19 ferdi Exp $

/**
 * Settings form for choosing the operating mode of purl
 */
function fb_social_settings_form(){
  $form = array();

  $form['fb_social_appid'] = array(
      '#title' => t('Facebook application id'), 
      '#type' => 'textfield', 
      '#description' => t('
      <p>
      Register your application on Facebook to get a Facebook App Id: !url.
      </p>
      <p>
      Go on your facebook app page (Applications > Developer > My Applications)
      click "Edit Settings". Then click "Connect". Make sure that the "Connect
      URL" matches your domain exactly.</p>',
      array('!url' => l('register here', 'http://developers.facebook.com/setup/'))
    ),
      '#default_value' => variable_get('fb_social_appid', ''),
  );
  
  $form['fb_social_locale'] = array(
      '#title' => t('Facebook application locale'), 
      '#type' => 'textfield', 
      '#default_value' => variable_get('fb_social_locale', 'en_US'),
      '#description' => t('Your facebook application locale. List of all locales at http://www.facebook.com/translations/FacebookLocales.xml'),
  );
  
  $form = system_settings_form($form);
  return $form;
}
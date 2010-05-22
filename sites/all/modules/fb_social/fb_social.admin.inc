<?php
// $Id: fb_social.admin.inc,v 1.2.2.2 2010/05/04 14:16:31 ferdi Exp $

/**
 * Settings form for choosing the operating mode of purl
 */
function fb_social_settings_form(){
  $form = array();

  $form['fb_social_appid'] = array(
      '#title' => t('Facebook application id'), 
      '#type' => 'textfield', 
      '#description' => t('Your facebook application id'),
      '#default_value' => variable_get('fb_social_appid', ''),
      '#required' => TRUE,
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
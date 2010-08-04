<?php
// $Id$

/**
 * @file
 * Pdf2SwfField widget hooks and callbacks.
 */

/**
 * Implementation of CCK's hook_widget_settings($op = 'form').
 */
function pdf2swffield_widget_settings_form($widget) {
  $form = module_invoke('filefield', 'widget_settings', 'form', $widget);

  if ($form['file_extensions']['#default_value'] == 'txt') {
    $form['file_extensions']['#default_value'] = 'pdf';
  }
  
  $form['viewer_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Viewer width'),
    '#default_value' => !empty($widget['viewer_width']) ? $widget['viewer_width'] : 800,
    '#size' => 15,
    '#weight' => 20,
  );
  $form['viewer_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Viewer height'),
    '#default_value' => !empty($widget['viewer_height']) ? $widget['viewer_height'] : 600,
    '#size' => 15,
    '#maxlength' => 10,    
    '#weight' => 30,
  );
  $form['path_to_pdf2swf'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to pdf2swf'),
    '#default_value' => !empty($widget['path_to_pdf2swf']) ? $widget['path_to_pdf2swf'] : '/usr/local/bin/pdf2swf',
    '#size' => 50,
    '#maxlength' => 100,    
    '#weight' => 40,
  );
  
  $form['pdf2swf_commandline'] = array(
    '#type' => 'textfield',
    '#title' => t('pdf2swf command line parameters'),
    '#default_value' => !empty($widget['pdf2swf_commandline']) ? $widget['pdf2swf_commandline'] : '--zlib -t --flashversion 9',
    '#size' => 50,
    '#maxlength' => 100,    
    '#weight' => 50,
  );

  return $form;
}

/**
 * Implementation of CCK's hook_widget_settings($op = 'validate').
 */
function pdf2swffield_widget_settings_validate($widget) {
	variable_set($widget["field_name"] . "_width", $widget["viewer_width"]);
	variable_set($widget["field_name"] . "_height", $widget["viewer_height"]);
  // Check that only pdf are specified in the callback.
  $extensions = array_filter(explode(' ', $widget['file_extensions']));
  $web_extensions = array('pdf');
  if (count(array_diff($extensions, $web_extensions))) {
    form_set_error('file_extensions', t('Only pdf are supported through the pdf2swf widget.'));
  }
}

/**
 * Implementation of CCK's hook_widget_settings($op = 'save').
 */
function pdf2swffield_widget_settings_save($widget) {
  $filefield_settings = module_invoke('filefield', 'widget_settings', 'save', $widget);
  return array_merge($filefield_settings, array('viewer_width', 'viewer_height', 'path_to_pdf2swf', 'pdf2swf_commandline'));
}

/**
 * FormAPI theme function. Theme the output of an pdf2swf field.
 */
function theme_pdf2swffield_widget(&$element) {
  //drupal_add_css(drupal_get_path('module', 'pdf2swffield') .'/pdf2swffield.css');
  return theme('form_element', $element, $element['#children']);
}

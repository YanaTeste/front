<?php
// $Id$

/**
 * @file
 * Pdf2SwfField formatter hooks and callbacks.
 */

function theme_pdf2swffield_formatter_swf_plain($element) {
  if (empty($element['#item']['fid'])) {
    return '';
  }

  $field = content_fields($element['#field_name']);
  $item = $element['#item'];

  return  theme('pdf2swffield', $item, array('width' => variable_get($element['#field_name'] . "_width", 800), 'height' => variable_get($element['#field_name'] . "_height", 600)));
}
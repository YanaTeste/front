<?php
// $Id: openlayers_behavior_panzoombar.inc,v 1.1.2.3 2009/09/28 01:11:41 zzolo Exp $

/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Pan Zoom Bar Behavior
 */
class openlayers_behavior_panzoombar extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'panzoombar' => '',
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .'/includes/behaviors/js/openlayers_behavior_panzoombar.js');
    return $this->options;
  }
}

<?php

/**
 * Implementation of hook_content_default_fields().
 */
function maps_content_default_fields() {
  module_load_include('inc', 'maps', 'maps.defaults');
  $args = func_get_args();
  return call_user_func_array('_maps_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function maps_ctools_plugin_api() {
  module_load_include('inc', 'maps', 'maps.defaults');
  $args = func_get_args();
  return call_user_func_array('_maps_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function maps_node_info() {
  module_load_include('inc', 'maps', 'maps.features.node');
  $args = func_get_args();
  return call_user_func_array('_maps_node_info', $args);
}

/**
 * Implementation of hook_openlayers_presets().
 */
function maps_openlayers_presets() {
  module_load_include('inc', 'maps', 'maps.defaults');
  $args = func_get_args();
  return call_user_func_array('_maps_openlayers_presets', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function maps_views_default_views() {
  module_load_include('inc', 'maps', 'maps.features.views');
  $args = func_get_args();
  return call_user_func_array('_maps_views_default_views', $args);
}

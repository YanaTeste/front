<?php

/**
 * Implementation of hook_content_default_fields().
 */
function blogg_content_default_fields() {
  module_load_include('inc', 'blogg', 'blogg.defaults');
  $args = func_get_args();
  return call_user_func_array('_blogg_content_default_fields', $args);
}

/**
 * Implementation of hook_context_default_contexts().
 */
function blogg_context_default_contexts() {
  module_load_include('inc', 'blogg', 'blogg.defaults');
  $args = func_get_args();
  return call_user_func_array('_blogg_context_default_contexts', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function blogg_ctools_plugin_api() {
  module_load_include('inc', 'blogg', 'blogg.defaults');
  $args = func_get_args();
  return call_user_func_array('_blogg_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_ds_default_settings().
 */
function blogg_ds_default_settings() {
  module_load_include('inc', 'blogg', 'blogg.features.ds');
  $args = func_get_args();
  return call_user_func_array('_blogg_ds_default_settings', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function blogg_imagecache_default_presets() {
  module_load_include('inc', 'blogg', 'blogg.defaults');
  $args = func_get_args();
  return call_user_func_array('_blogg_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function blogg_node_info() {
  module_load_include('inc', 'blogg', 'blogg.features.node');
  $args = func_get_args();
  return call_user_func_array('_blogg_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function blogg_views_default_views() {
  module_load_include('inc', 'blogg', 'blogg.features.views');
  $args = func_get_args();
  return call_user_func_array('_blogg_views_default_views', $args);
}

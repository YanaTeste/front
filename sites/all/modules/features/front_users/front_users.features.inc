<?php
/**
 * @file
 * front_users.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function front_users_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_profile2_type().
 */
function front_users_default_profile2_type() {
  $items = array();
  $items['profile'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "profile",
    "label" : "Profile",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 0 },
    "metatags" : [],
    "microdata" : { "#attributes" : { "itemscope" : "" } },
    "rdf_mapping" : []
  }');
  return $items;
}

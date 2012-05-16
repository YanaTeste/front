<?php
/**
 * @file
 * front_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function front_users_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social|profile2|profile|form';
  $field_group->group_name = 'group_social';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social links',
    'weight' => '4',
    'children' => array(
      0 => 'field_twitter',
      1 => 'field_facebook',
      2 => 'field_linkedin',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social links',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Please copy and paste the url for your public profile or page for each service you would like to display.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_social|profile2|profile|form'] = $field_group;

  return $export;
}

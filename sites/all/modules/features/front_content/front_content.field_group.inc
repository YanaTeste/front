<?php
/**
 * @file
 * front_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function front_content_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|video|form';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata og SEO',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_date',
      2 => 'field_tags',
      3 => 'field_dato_iso_',
      4 => 'field_lengde_iso',
      5 => 'field_thumbnail',
      6 => 'metatags',
      7 => 'title',
      8 => 'path',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_meta|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video|node|video|form';
  $field_group->group_name = 'group_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '0',
    'children' => array(
      0 => 'field_vimeo_video_id',
      1 => 'field_youtube_video_id',
      2 => 'field_embed_field',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_video|node|video|form'] = $field_group;

  return $export;
}

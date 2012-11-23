<?php
/**
 * @file
 * front_display_suite.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function front_display_suite_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|kurs|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'kurs';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'date_with_icon' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Dato',
        'lb-el' => 'h4',
      ),
    ),
    'field_location' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Sted',
        'lb-el' => 'h4',
      ),
    ),
    'field_instructor' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb' => 'Kursholder',
        'lb-el' => 'h4',
      ),
    ),
  );
  $export['node|kurs|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|kurs|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'kurs';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'date_with_icon' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'field_location' => array(
      'ft' => array(
        'lb' => 'Sted',
      ),
    ),
  );
  $export['node|kurs|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => 'list-title',
      ),
    ),
  );
  $export['node|page|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'video_620px' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|video|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|preview';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'preview';
  $ds_fieldsetting->settings = array(
    'video_300px' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|video|preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'video_620px' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|video|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function front_display_suite_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vimeo_video';
  $ds_field->label = 'Vimeo Video';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<iframe src="http://player.vimeo.com/video/[node:field_vimeo_video_id]" width="500" height="334" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>',
      'format' => 'full_html',
    ),
    'use_token' => 1,
  );
  $export['vimeo_video'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function front_display_suite_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|kurs|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'kurs';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'date_with_icon',
        1 => 'field_location',
        2 => 'field_instructor',
        3 => 'body',
        4 => 'field_date',
      ),
    ),
    'fields' => array(
      'date_with_icon' => 'ds_content',
      'field_location' => 'ds_content',
      'field_instructor' => 'ds_content',
      'body' => 'ds_content',
      'field_date' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|kurs|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|kurs|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'kurs';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'date_with_icon',
        2 => 'field_location',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'date_with_icon' => 'ds_content',
      'field_location' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|kurs|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|page|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'meta_description',
        1 => 'field_date',
        2 => 'body',
        3 => 'video_620px',
        4 => 'field_tags',
        5 => 'field_dato_iso_',
        6 => 'field_lengde_iso',
        7 => 'fb_social_Comments',
      ),
    ),
    'fields' => array(
      'meta_description' => 'ds_content',
      'field_date' => 'ds_content',
      'body' => 'ds_content',
      'video_620px' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_dato_iso_' => 'ds_content',
      'field_lengde_iso' => 'ds_content',
      'fb_social_Comments' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|video|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|preview';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'preview';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'video_300px',
      ),
    ),
    'fields' => array(
      'video_300px' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|video|preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_date',
        2 => 'video_620px',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_date' => 'ds_content',
      'video_620px' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|video|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function front_display_suite_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'preview';
  $ds_view_mode->label = 'Preview';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['preview'] = $ds_view_mode;

  return $export;
}

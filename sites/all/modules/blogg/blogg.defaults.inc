<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _blogg_content_default_fields() {
  $fields = array();

  // Exported field: field_files
  $fields[] = array(
    'field_name' => 'field_files',
    'type_name' => 'blog',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => '',
      'region' => 'disabled',
      'ds_weight' => '-43',
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'filefield',
        'parent_id' => '',
        'field_id' => 'field_files',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-43',
      ),
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'disabled',
        'type' => 'filefield',
        'parent_id' => '',
        'field_id' => 'field_files',
        'label_value' => '',
        'exclude' => 1,
        'weight' => '-39',
      ),
      'weight' => '-1',
      'parent' => '',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => '',
      'file_path' => 'media/vedlegg',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'filefield_sources' => array(
        'imce' => TRUE,
        'reference' => TRUE,
        'remote' => TRUE,
      ),
      'insert' => 1,
      'insert_styles' => array(
        'link' => 'link',
        'auto' => 0,
        'image' => 0,
      ),
      'insert_default' => 'auto',
      'insert_class' => 'file',
      'insert_width' => '',
      'label' => 'Filer',
      'weight' => '2',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_forfatter
  $fields[] = array(
    'field_name' => 'field_forfatter',
    'type_name' => 'blog',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => '',
      'region' => 'disabled',
      'ds_weight' => '-50',
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'plain',
        'css-class' => '',
        'region' => 'left',
        'type' => 'nodereference',
        'parent_id' => '',
        'field_id' => 'field_forfatter',
        'label_value' => 'Av',
        'exclude' => 0,
        'weight' => '-50',
      ),
      'teaser' => array(
        'label' => array(
          'format' => 'inline',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'left',
        'type' => 'nodereference',
        'parent_id' => '',
        'field_id' => 'field_forfatter',
        'label_value' => 'Av',
        'exclude' => 0,
        'weight' => '-50',
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'list' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'sticky' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'block' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'person' => 'person',
      'artikkel' => 0,
      'blog' => 0,
      'listevisning' => 0,
      'panel' => 0,
      'page' => 0,
      'webform' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_forfatter][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Skribent',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_image
  $fields[] = array(
    'field_name' => 'field_image',
    'type_name' => 'blog',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => '',
      'region' => 'disabled',
      'ds_weight' => '-48',
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'shadowbox___blog_medium___original',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'filefield',
        'parent_id' => '',
        'field_id' => 'field_image',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-48',
      ),
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'blog_medium_linked',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'filefield',
        'parent_id' => '',
        'field_id' => 'field_image',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-45',
      ),
      'weight' => '-4',
      'parent' => '',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'cck_blocks' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'media/images',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'filefield_sources' => array(
        'imce' => 0,
        'reference' => 0,
        'remote' => 0,
      ),
      'insert' => 0,
      'insert_styles' => array(
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_blog_medium' => 0,
      ),
      'insert_default' => 'auto',
      'insert_class' => 'inserted',
      'insert_width' => '600',
      'collapsible' => '2',
      'resolution' => '',
      'enforce_ratio' => 0,
      'croparea' => '500x500',
      'label' => 'Bilde',
      'weight' => '-3',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_teasertext
  $fields[] = array(
    'field_name' => 'field_teasertext',
    'type_name' => 'blog',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => '',
      'region' => 'disabled',
      'ds_weight' => '-45',
      'full' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_teasertext',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-45',
      ),
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'text',
        'parent_id' => '',
        'field_id' => 'field_teasertext',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-44',
      ),
      'weight' => '-3',
      'parent' => '',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_teasertext][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'filefield_sources' => array(
        'imce' => 'imce',
        'reference' => 'reference',
        'remote' => 'remote',
      ),
      'label' => 'Ingress',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_image
  $fields[] = array(
    'field_name' => 'field_image',
    'type_name' => 'person',
    'display_settings' => array(
      'label' => array(
        'format' => 'hidden',
      ),
      'format' => 'default',
      'css-class' => '',
      'region' => 'disabled',
      'ds_weight' => '-49',
      'teaser' => array(
        'label' => array(
          'format' => 'hidden',
        ),
        'format' => 'person_medium_default',
        'css-class' => '',
        'region' => 'middle',
        'type' => 'filefield',
        'parent_id' => '',
        'field_id' => 'field_image',
        'label_value' => '',
        'exclude' => 0,
        'weight' => '-49',
      ),
      'weight' => '-4',
      'parent' => '',
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'cck_blocks' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'media/images',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'filefield_sources' => array(
        '1' => 1,
        'imce' => FALSE,
        'reference' => FALSE,
        'remote' => FALSE,
      ),
      'insert' => FALSE,
      'insert_styles' => array(
        '1' => 1,
        '0' => 1,
        'auto' => FALSE,
        'link' => FALSE,
        'image' => FALSE,
        'imagecache_wide' => FALSE,
        'imagecache_mini' => FALSE,
        'imagecache_blog_medium' => FALSE,
      ),
      'insert_default' => array(
        '0' => 'auto',
      ),
      'insert_class' => 'inserted',
      'insert_width' => '600',
      'collapsible' => '2',
      'resolution' => '',
      'enforce_ratio' => 0,
      'croparea' => '500x500',
      'label' => 'Bilde',
      'weight' => '-4',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  array(
    t('Bilde'),
    t('Filer'),
    t('Ingress'),
    t('Skribent'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _blogg_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blogg';
  $context->description = 'Den komplette blogg';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'views' => array(
      'values' => array(
        'blog' => 'blog',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => 1,
          'region' => 'right',
          'weight' => 0,
        ),
        'views-Emner-block_1' => array(
          'module' => 'views',
          'delta' => 'Emner-block_1',
          'region' => 'right',
          'weight' => 1,
        ),
        'views-persons-block_1' => array(
          'module' => 'views',
          'delta' => 'persons-block_1',
          'region' => 'right',
          'weight' => 2,
        ),
        'comment-0' => array(
          'module' => 'comment',
          'delta' => 0,
          'region' => 'right',
          'weight' => 3,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  $translatables['blogg'] = array(
    t('Den komplette blogg'),
  );

  $export['blogg'] = $context;
  return $export;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _blogg_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _blogg_imagecache_default_presets() {
  $items = array(
    'blog_medium' => array(
      'presetname' => 'blog_medium',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '240',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'person_medium' => array(
      'presetname' => 'person_medium',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '70',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

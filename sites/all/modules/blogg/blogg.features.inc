<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function blogg_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function blogg_imagecache_default_presets() {
  $items = array(
    '214w' => array(
      'presetname' => '214w',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '214',
            'height' => '224',
          ),
        ),
      ),
    ),
    'blog_medium' => array(
      'presetname' => 'blog_medium',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '614',
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

/**
 * Implementation of hook_node_info().
 */
function blogg_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blogginnlegg'),
      'module' => 'features',
      'description' => t('Et standard innlegg i Löplabbetbloggen'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'has_body' => '1',
      'body_label' => t('Tekst'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'person' => array(
      'name' => t('Person'),
      'module' => 'features',
      'description' => t('En medarbeider'),
      'has_title' => '1',
      'title_label' => t('Navn'),
      'has_body' => '1',
      'body_label' => t('Tekst'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function blogg_views_api() {
  return array(
    'api' => '2',
  );
}

<?php
/**
 * @file
 * front_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function front_content_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function front_content_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Artikkel'),
      'base' => 'node_content',
      'description' => t('Not in use'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => '',
    ),
    'banner' => array(
      'name' => t('Banner'),
      'base' => 'node_content',
      'description' => t('Banners to promote or hightlight site content.'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => '',
    ),
    'blog' => array(
      'name' => t('Blogginnlegg'),
      'base' => 'node_content',
      'description' => t('Et standard innlegg i Löplabbetbloggen.'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => '',
    ),
    'kurs' => array(
      'name' => t('Kurs'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Side'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static & structural content.'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Prosjekt'),
      'base' => 'node_content',
      'description' => t('Use <em>Prosjekt</em> for portfolio and case studies of projects.'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => '',
    ),
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Last opp en ny opplæringsvideo'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Tittel'),
      'help' => '',
    ),
  );
  return $items;
}

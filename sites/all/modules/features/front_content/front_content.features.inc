<?php
/**
 * @file
 * front_content.features.inc
 */

/**
 * Implements hook_node_info().
 */
function front_content_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Artikkel'),
      'base' => 'node_content',
      'description' => t('Opprett en nyhetssak, featureartikkel, kunngjøring, e.l.'),
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
  );
  return $items;
}

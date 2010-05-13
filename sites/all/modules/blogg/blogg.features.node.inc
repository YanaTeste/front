<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _blogg_node_info() {
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

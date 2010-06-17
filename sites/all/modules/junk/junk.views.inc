<?php
// $Id: junk.views.inc,v 1.1 2010/01/28 13:37:45 alirasirin Exp $

/**
 * @file
 * Views integration.
 */

/*
 * Implementation of hook_views_handlers()
 */
function junk_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'junk') . '/includes',
    ),
    'handlers' => array(
      'junk_views_handler_restore_link' => array(
        'parent' => 'views_handler_field'
      ),
      'junk_views_handler_delete_link' => array(
        'parent' => 'views_handler_field'
      ),
      'junk_views_handler_junk_link' => array(
        'parent' => 'views_handler_field'
      ),
    ),
  );
}

/*
 * Implementation of hook_views_data()
 */
function junk_views_data() {
  return array(
    'junk_node' => array(
      'table' => array(
        'group' => t('Junk'),
        'join'  => array(
          'node'  => array('left_field' => 'nid', 'field' => 'nid'),
          'users' => array('left_field' => 'uid', 'field' => 'uid'),
        ),
      ),
      'nid' => array(
        'title'    => t('Node'),
        'help'     => t('The junked node.'),
        'relationship' => array(
          'base'    => 'node',
          'field'   => 'nid',
          'handler' => 'views_handler_relationship',
          'label'   => t('Node'),
        ),
      ),
      'uid' => array(
        'title'    => t('User'),
        'help'     => t('The user who junked the node.'),
        'field'    => array('handler' => 'views_handler_field_user_name', 'click sortable' => TRUE),
        'argument' => array('handler' => 'views_handler_argument_user_uid'),
        'filter'   => array('handler' => 'views_handler_filter_user_name', 'title' => t('Name')),
        'sort'     => array('handler' => 'views_handler_sort'),
        'relationship' => array(
          'base'    => 'users',
          'field'   => 'uid',
          'handler' => 'views_handler_relationship',
          'label'   => t('User'),
        ),
      ),
      'timestamp' => array(
        'title'    => t('Date'),
        'help'     => t('The date when the node was junked.'),
        'field'    => array('handler' => 'views_handler_field_date'),
        'sort'     => array('handler' => 'views_handler_sort_date'),
        'filter'   => array('handler' => 'views_handler_filter_date'),
      ),
      'restore_link' => array(
        'title'    => t('Restore link'),
        'help'     => t('Link to restoring node.'),
        'field'    => array('handler' => 'junk_views_handler_restore_link')
      ),
      'delete_link' => array(
        'title'    => t('Delete link'),
        'help'     => t('Link to permanently delete node.'),
        'field'    => array('handler' => 'junk_views_handler_delete_link')
      ),
      'junk_link' => array(
        'title'    => t('Move to junk link'),
        'help'     => t('Link to junk node.'),
        'field'    => array('handler' => 'junk_views_handler_delete_link')
      ),
    ),
  );
}


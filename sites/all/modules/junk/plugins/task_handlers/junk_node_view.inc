<?php
// $Id: junk_node_view.inc,v 1.1 2010/03/12 16:58:24 alirasirin Exp $

/**
 * @file
 * This is the task handler plugin to handle attaching junk page variant to viewing junked nodes.
 *
 */

/**
 * Specialized implementation of hook_page_manager_task_handlers().
 */
function junk_junk_node_view_page_manager_task_handlers() {
  return array(
    'handler type' => 'node_view',
    'title' => t('Junk Node View'),
    'admin summary' => 'junk_junk_node_view_admin_summary',
    'render' => 'junk_junk_node_view_render',
    'visible' => TRUE,
    'add features' => array(
      'criteria' => t('Selection rules'),
    ),
    'edit forms' => array(
      'criteria' => t('Selection rules'),
    ),
    'operations' => array(
      'criteria' => array(
        'title' => t('Selection rules'),
        'description' => t('Control the criteria used to decide whether or not this variant is used.'),
        'form' => array(
          'order' => array(
            'form' => t('Selection rules'),
          ),
          'forms' => array(
            'form' => array(
              'include' => drupal_get_path('module', 'ctools') . '/includes/context-task-handler.inc',
              'form id' => 'ctools_context_handler_edit_criteria',
            ),
          ),
        ),
      ),
    ),
    'forms' => array(
      'criteria' => array(
        'include' => drupal_get_path('module', 'ctools') . '/includes/context-task-handler.inc',
        'form id' => 'ctools_context_handler_edit_criteria',
      ),
    ),
    'default conf' => array(
      'autogenerate_title' => FALSE,
      'title' => t('Junk Node View'),
    ),
  );
}

/**
 * Check selection rules and, if passed, render the contexts.
 *
 * We must first check to ensure the node is of a type we're allowed
 * to render. If not, decline to render it by returning NULL.
 */
function junk_junk_node_view_render($handler, $base_contexts, $args, $test = TRUE) {
  $node = $base_contexts['argument_nid_1']->data;
  if (junk_is_junked($args[0])) {
  	$link = '';
  	if (junk_can_junk($base_contexts["argument_nid_1"]->data) || user_access('clear junk'))  
  	  $link = '<br/>' . l(t('Restore'), "junk/$node->nid/restore");
  	$content = '';
  	if ((user_access('administer junk') || user_access('clear junk')) && variable_get('junk_show_contents', 0)) {
  	  $node = node_build_content($node, FALSE, TRUE);
	  $node->body = drupal_render($node->content);
  	  $content = '<br/><br/>' . $node->body;
  	}
    $info = array(
      'title' => $node->title,
      'content' => '<span style="color:red">' . t('This node is deleted.') . '</span>' . $link . $content,
      'no_blocks' => FALSE,
    );
    return $info;
  }      
}


/**
 * Provide a nice little summary of this task handler.
 *
 */
function junk_junk_node_view_admin_summary($task, $subtaskd) {
  $output = '<h4>Junk Node View is installed.</h4>';
  return $output;
}

/**
 * General settings for the panel
 */
function junk_junk_node_view_edit_settings(&$form, &$form_state) {
  $conf = $form_state['handler']->conf;
  $form['conf']['title'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['title'],
    '#title' => t('Administrative title'),
    '#description' => t('Administrative title of this variant.'),
  );
  $form['conf']['no_blocks'] = array(
    '#type' => 'checkbox',
    '#default_value' => $conf['no_blocks'],
    '#title' => t('Disable Drupal blocks/regions'),
    '#description' => t('Check this to have the page disable all regions displayed in the theme. Note that some themes support this setting better than others. If in doubt, try with stock themes to see.'),
  );
  $form['conf']['css_id'] = array(
    '#type' => 'textfield',
    '#size' => 35,
    '#default_value' => $conf['css_id'],
    '#title' => t('CSS ID'),
    '#description' => t('The CSS ID to apply to this page'),
  );
  $form['conf']['css'] = array(
    '#type' => 'textarea',
    '#title' => t('CSS code'),
    '#description' => t('Enter well-formed CSS code here; this code will be embedded into the page, and should only be used for minor adjustments; it is usually better to try to put CSS for the page into the theme if possible. This CSS will be filtered for safety so some CSS may not work.'),
    '#default_value' => $conf['css'],
  );
}

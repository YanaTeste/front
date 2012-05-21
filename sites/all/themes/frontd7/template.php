<?php

/**
 * Implements hook_css_alter().
 */
function frontd7_css_alter(&$css) {
  // Remove SASSON files
  // TODO: make this configurable, choosing between TBS reset/grid and SASSON
  unset($css[drupal_get_path('theme', 'sasson') . '/styles/boilerplate.css']);
}

/**
 * Implements hook_js_alter().
 */
function frontd7_js_alter(&$javascript) {
  // Swap out jQuery to use an updated version of the library.
  $javascript['misc/jquery.js']['data'] = 'https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js';
}

/**
 * Implements hook_preprocess().
 */
function frontd7_preprocess_page(&$variables) {
  if (module_exists('search_api')) {
    $search_box = module_invoke('search_api_page', 'block_view', 'front_main_search');
    $variables['search_box'] = render($search_box);
  }
  else if (module_exists('search')) {
    $search_box = drupal_render(drupal_get_form('search_form'));
    $variables['search_box'] = $search_box;
  }
  if (isset($variables['tabs']['#primary']) && empty($variables['tabs']['#primary'])) {
    unset($variables['tabs']);
  }
}

/**
 * Return a themed breadcrumb trail
 */
function frontd7_breadcrumb($vars) {
  $breadcrumb = isset($vars['breadcrumb']) ? $vars['breadcrumb'] : array();

  if (theme_get_setting('sasson_breadcrumb_hideonlyfront')) {
    $condition = count($breadcrumb) > 1;
  }
  else {
    $condition = !empty($breadcrumb);
  }

  if(theme_get_setting('sasson_breadcrumb_showtitle')) {
    $title = drupal_get_title();
    if(!empty($title)) {
      $condition = true;
      $breadcrumb[] = $title;
    }
  }

  $separator = theme_get_setting('sasson_breadcrumb_separator');

  if (!$separator) {
    $separator = '<span class="divider">»</span>';
  }
  else {
    $separator = '<span class="divider">' . $separator . '</span>';
  }

  if ($condition) {
    return implode(" {$separator} ", $breadcrumb);
  }
}

/**
 * Implements theme_item_list().
 */
function frontd7_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  if (isset($attributes['class']) && $attributes['class'][0] === 'pager') {
    $output = '<div class="pagination pagination-centered">';
    unset($attributes['class'][0]);

    if (sizeof($attributes['class']) == 0) {
      unset($attributes['class']);
    }
  }
  else {
    $output = '<div class="item-list">';
  }
  if (isset($title)) {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 0) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items - 1) {
        $attributes['class'][] = 'last';
      }
      if ($attributes['class'][0] == 'pager-current' || $attributes['class'][0] == 'pager-ellipsis') {
        $data = '<span>' . $data . '</span>';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  $output .= '</div>';
  return $output;
}

/**
 * Implements hook_form_alter().
 */
function frontd7_form_alter(&$form, &$form_state, $form_id) {
  // Create placeholders attributes for form elements.
  if (isset($form['#node']) && $form['#node']->type == 'webform') {
    $types = array('textfield', 'webform_email', 'textarea');

    foreach ($form['submitted'] as $key => $component) {
      if (is_array($component)) {
        if (in_array($component['#type'], $types)) {
          $form['submitted'][$key]['#attributes']['placeholder'] = $component['#title'];
        }
        if ($component['#type'] == 'textarea') {
          $form['submitted'][$key]['#resizable'] = FALSE;
        }
      }
    }
  }
}

/**
 * Implements hook_form_search_api_page_search_form_front_main_search_alter().
 */
function frontd7_form_search_api_page_search_form_front_main_search_alter(&$form, &$form_state, $form_id) {
  $form['#attributes']['class'][] = 'search-form';
  $form['keys_1']['#attributes']['placeholder'] = t('Enter your keywords');
  
  $form['submit_1']['#type'] = 'image_button';
  $form['submit_1']['#src'] = drupal_get_path('theme', 'frontd7') . '/images/icon_search-submit.png';
}

/**
 * Implements hook_form_search_form_alter().
 */
function frontd7_form_search_form_alter(&$form, &$form_state, $form_id) {
  $form['#attributes']['role'] = 'search';

  $form['basic']['keys']['#attributes']['placeholder'] = $form['basic']['keys']['#title'];
  $form['basic']['keys']['#title'] = '';

  $form['basic']['submit']['#type'] = 'image_button';
  $form['basic']['submit']['#src'] = drupal_get_path('theme', 'frontd7') . '/images/icon_search-submit.png';
}

/**
 * Implements hook_preprocess_panels_pane().
 */
function frontd7_preprocess_panels_pane(&$vars) {
  if ($vars['pane']->type == 'custom' && $vars['pane']->subtype != 'custom') {
    // Use custom content machine name on classes.
    $vars['classes_array'][] = 'pane-custom-'. ctools_cleanstring($vars['pane']->subtype);
  }
  elseif (preg_match('/webform/i', $vars['pane']->subtype)) {
    // Generic webform class.
    $clean_subtype = str_replace(range(0,9), '', $vars['pane']->subtype);
    $vars['classes_array'][] = ctools_cleanstring($clean_subtype);
  }
  elseif (preg_match('/menu_block/i', $vars['pane']->subtype)) {
    // Generic menu block class.
    $clean_subtype = str_replace(range(0,9), '', $vars['pane']->subtype);
    $vars['classes_array'][] = 'pane-'. ctools_cleanstring($clean_subtype);
  }

  if (isset($vars['display']->css_id)) {
    $panel_id = str_replace('-', '_', $vars['display']->css_id);
    $vars['theme_hook_suggestions'][] = 'panels_pane__' . $panel_id;
  }
}


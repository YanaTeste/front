<?php

/**
 * Implements hook_css_alter().
 */
function frontstrap_css_alter(&$css) {
  // Remove SASSON files
  // TODO: make this configurable, choosing between TBS reset/grid and SASSON
  unset($css[drupal_get_path('theme', 'sasson') . '/styles/boilerplate.css']);
}

/**
 * Implements hook_js_alter().
 */
function frontstrap_js_alter(&$javascript) {
  // Swap out jQuery to use an updated version of the library.
  $javascript['misc/jquery.js']['data'] = 'https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js';
}


/**
 * Return a themed breadcrumb trail
 */
function frontstrap_breadcrumb($vars) {
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
function frontstrap_item_list($variables) {
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

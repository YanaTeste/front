<?php

// Plugin definition
$plugin = array(
  'title' => t('Column + sidebar'),
  'category' => t('Front'),
  'icon' => 'onecolsidebar.png',
  'theme' => 'panels_onecolsidebar',
  'admin css' => 'onecolsidebar.css',
  'regions' => array(
    'left' => t('Left side'),
    'right' => t('Right side')
  ),
);

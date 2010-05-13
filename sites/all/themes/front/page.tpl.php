<?php
?>
<!DOCTYPE HTML>
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>

<body class="<?php print $body_classes; ?>">
  <div id="header-top">
    <div id="header-top-inner">
      <?php print $secondary_menu_links; ?>
    </div>
  </div>
  <div id="site-header" class="clear-block">
    <div id="site-header-inner">
      <div id="branding" class="grid-3 clear-block">
        <span id="logo" class="grid-1 alpha"><?php print $linked_logo_img; ?></span>
      </div>
      <div id="nav">
        <div id="main-menu"><?php print $main_menu_links; ?></div>
        <div id="search-box"><?php print $search_box; ?></div>
      </div>
    </div>
  </div>
  <div id="status">
    <div id="status-inner">
      <?php print $breadcrumb; ?>
      <?php if ($status): ?>
        <div id="tweet">
          <?php print $status; ?>
        </div>
      <?php endif; ?>
      <div id="follow">
        <a href="http://twitter.com/frontkom">F&oslash;lg oss p&aring; Twitter</a>
      </div>
    </div>
  </div>
  <div id="page" class="container-12 clear-block">
    <?php if ($header): ?>
      <div id="header-region" class="region <?php print ns('grid-12', $mission, 7); ?> clear-block">
        <?php print $header; ?>
      </div>
    <?php endif; ?>
    <div id="main" class="column <?php print ns('grid-12', $left, 4, $right, 4) . ' ' . ns('push-4', !$left, 4); ?>">
      <?php if ($title): ?>
        <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php if ($content_top): ?>
        <div id="content-top" class="grid-12 alpha">
          <div id="content-top-inner">
            <?php print $content_top; ?>
          </div>  
        </div>
      <?php endif; ?>
      <?php if ($tabs): ?>
        <div class="tabs"><?php print $tabs; ?></div>
      <?php endif; ?>
      <?php print $messages; ?>
      <?php print $help; ?>
      <div id="main-content" class="region clear-block">
        <?php print $content; ?>
        <?php print $content_bottom; ?>
      </div>

    </div>

  <?php if ($left): ?>
    <div id="sidebar-left" class="column sidebar region grid-4 pull-8">
      <?php print $left; ?>
    </div>
  <?php endif; ?>

  <?php if ($right): ?>
    <div id="sidebar-right" class="column sidebar region grid-4">
      <?php print $right; ?>
    </div>
  <?php endif; ?>
  </div>
  <div id="footer" class="prefix-1 suffix-1">
    <div id="footer-top">
      <div id="footer-top-inner"><?php print $breadcrumb; ?></div>
    </div>
    <div id="footer-inner">
    <?php if ($footer): ?>
      <div id="footer-region" class="region grid-12 clear-block alpha">
        <?php print $footer; ?>
      </div>
    <?php endif; ?>

    <?php if ($footer_message): ?>
      <div id="footer-message" class="grid-12 alpha">
        <?php print $footer_message; ?>
      </div>
    <?php endif; ?>
    </div>
  </div>
  <?php print $closure; ?>
</body>
</html>

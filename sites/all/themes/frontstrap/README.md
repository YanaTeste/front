# Frontstrap: A nice starting theme

## Get started

1. $ drush dl sasson
2. Check out your theme settings page for layout and grid settings, development settings, SASS settings and more. Much more info in Sasson's README.txt
3. Here is a cute kitten: http://goo.gl/SVyem


## Style test
1. Make a basic page in Drupal using Full HTML, and paste the content of bootstrap-html.txt
2. Repeat with drupal-html.txt

## Todos
- Update messages style http://cl.ly/092f0j3d1Z3p180J2h3u
- Update buttons for node edit: http://cl.ly/2b2l1l0a0i1Y3t0F253a (delete = red)
- Add margin bottom to images in nodes + views: http://cl.ly/1c373N1Y2L1Z280j2C0H
- Bootstrap buttons cleanup: http://cl.ly/1x2T0u0U2R1T323A080W
- Change classes for paging, so it looks like this: http://cl.ly/3l241g3h021x0O290X3U
- Remove instructions on filters: http://cl.ly/0H3W26401T3A1c3y2j0k
- Replace ugly Drupal throbber with nice one: http://cl.ly/3M030i322b253v340K1K
- Implement jQuery UI bootstrap theme http://addyosmani.github.com/jquery-ui-bootstrap/ Scrap the non-jQuery bootstrap js.
- Make nice login
- ???

## How to update bootstrap libraries

Use Thomas McDonald's SASS port of Twitter Bootstrap

1. Download [Bootstrap for Sass][1]
2. Extract the archive and get the assets from the vendor/ directory
3. Copy assets:
  - Images from **images/** to **images/**
  - Javascript libraries from **javascripts/** to **scripts/**
  - **bootstrap/** directory from **stylesheets/** to **styles/partials/**



[1]: https://github.com/thomas-mcdonald/bootstrap-sass

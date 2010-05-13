<?php

/**
 * Helper to implementation of hook_ds_default_settings().
 */
function _blogg_ds_default_settings() {
  $data = array(
    'nd' => array(
      'blog' => array(
        'full' => array(
          'fields' => array(
            'field_forfatter' => array(
              'region' => 'left',
              'weight' => '-50',
              'format' => 'plain',
              'css-class' => '',
              'label_value' => 'Av',
              'labelformat' => 'hidden',
            ),
            'field_image' => array(
              'region' => 'middle',
              'weight' => '-48',
              'format' => 'shadowbox___blog_medium___original',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'field_teasertext' => array(
              'region' => 'middle',
              'weight' => '-45',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'field_files' => array(
              'region' => 'middle',
              'weight' => '-43',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'title' => array(
              'region' => 'middle',
              'weight' => '-49',
              'format' => 'nd_title_h1_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'disabled',
              'weight' => '-40',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'middle',
              'weight' => '-42',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-39',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'middle',
              'weight' => '-47',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'middle',
              'weight' => '-44',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'terms' => array(
              'region' => 'middle',
              'weight' => '-46',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'terms_1' => array(
              'region' => 'disabled',
              'weight' => '-41',
              'format' => 'nd_terms_per_vocabulary_space',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
        ),
        'teaser' => array(
          'fields' => array(
            'field_forfatter' => array(
              'region' => 'left',
              'weight' => '-50',
              'format' => 'default',
              'css-class' => '',
              'label_value' => 'Av',
              'labelformat' => 'inline',
            ),
            'field_image' => array(
              'region' => 'middle',
              'weight' => '-45',
              'format' => 'blog_medium_linked',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'field_teasertext' => array(
              'region' => 'middle',
              'weight' => '-44',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'field_files' => array(
              'region' => 'disabled',
              'weight' => '-39',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'title' => array(
              'region' => 'middle',
              'weight' => '-49',
              'format' => 'nd_title_h1_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'disabled',
              'weight' => '-41',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'middle',
              'weight' => '-46',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'middle',
              'weight' => '-43',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'middle',
              'weight' => '-48',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'disabled',
              'weight' => '-40',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'terms' => array(
              'region' => 'middle',
              'weight' => '-47',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'terms_1' => array(
              'region' => 'disabled',
              'weight' => '-42',
              'format' => 'nd_terms_per_vocabulary_space',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
        ),
      ),
      'person' => array(
        'teaser' => array(
          'fields' => array(
            'field_image' => array(
              'region' => 'middle',
              'weight' => '-49',
              'format' => 'person_medium_default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'title' => array(
              'region' => 'middle',
              'weight' => '-50',
              'format' => 'nd_title_h2_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'disabled',
              'weight' => '-43',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'disabled',
              'weight' => '-44',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-45',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'disabled',
              'weight' => '-48',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'disabled',
              'weight' => '-47',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'terms' => array(
              'region' => 'disabled',
              'weight' => '-46',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
        ),
      ),
    ),
  );
  return $data;
}

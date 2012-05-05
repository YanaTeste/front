<?php
/**
 * @file
 * Theme template for a list of tweets.
 *
 * Available variables in the theme include:
 *
 * 1) An array of $tweets, where each tweet object has:
 *   $tweet->id
 *   $tweet->username
 *   $tweet->userphoto
 *   $tweet->text
 *   $tweet->timestamp
 *
 * 2) $twitkey string containing initial keyword.
 *
 * 3) $title
 *
 */
?>

<?php if (is_array($tweets)): ?>
  <?php foreach ($tweets as $tweet_key => $tweet): ?>
    <h2 class="tweet-author">
      <?php print l($tweet->username, 'http://twitter.com/' . $tweet->username); ?>
    </h2>
    <blockquote class="twitter-tweet">
      <?php print twitter_pull_add_links($tweet->text); ?>

      <span class="tweet-meta">
        <?php
          $time_opts = array(
              'attributes' => array(
                'class' => 'tweet-time',
                'datetime' => date('Y-m-d\TH:i:sP', $tweet->timestamp),
              ),
          );

          print l($tweet->time_ago, 'http://twitter.com/' . $tweet->username . '/status/' . $tweet->id, $time_opts);
        ?>

        <?php
          $follow_opts = array(
              'attributes' => array(
                'class' => 'tweet-follow',
              ),
          );
          $follow_text = t('Follow @username on Twitter', array('@username' => $tweet->username));

          print l($follow_text, 'http://twitter.com/' . $tweet->username, $follow_opts);
        ?>
      </span>

    </blockquote>
  <?php endforeach; ?>
<?php endif; ?>

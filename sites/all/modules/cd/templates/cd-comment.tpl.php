<?php
// $Id: cd-comment.tpl.php,v 1.1.2.3 2010/03/31 08:05:09 swentel Exp $

/**
 * @file
 * cd-comment.tpl.php Optimized version for cd and ds.
 */
?>

<div class="clear-block comment<?php if (isset($comment->status) && $comment->status == COMMENT_NOT_PUBLISHED): print ' comment-unpublished'; endif; ?><?php if ($new != ''): ?> new <?php endif; ?>">
<div class="content"><?php print $content; ?></div></div>

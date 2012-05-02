/*
 * FrontD7 scripts.
 */

(function($) {

    Drupal.behaviors.frontSearch = {
        attach: function(context) {
            if ($('#header .search-form', context).length) {
                var searchForm = $('#header .search-form', context);

                $('input.form-submit', searchForm).click(function(e) {
                    if (searchForm.hasClass('form-open')) {
                        return true;
                    }
                    else {
                        searchForm.addClass('search-active');
                        $('#main-menu:visible', context).fadeOut();
                        e.preventDefault();
                        $('input.form-text', searchForm).focus();
                    }
                });

                $('*', searchForm).blur(function() {
                    searchForm.removeClass('search-active');
                    $('#main-menu:hidden', context).fadeIn();
                });
            }
        }
    };

})(jQuery);

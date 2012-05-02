/*
 * FrontD7 scripts.
 */

(function($) {

    Drupal.behaviors.frontSearch = {
        attach: function(context) {
            if ($('#header .search-form', context).length) {
                var searchForm = $('#header .search-form', context);

                $('input.form-submit', searchForm).live('click', function(e) {
                    e.preventDefault();
                    searchForm.toggleClass('search-active');
                    $('#main-menu', context).fadeToggle();
                });
            }
        }
    };

})(jQuery);

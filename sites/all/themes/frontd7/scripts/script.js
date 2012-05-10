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

    Drupal.behaviors.frontd7 = {
        attach: function(context) {
            // Set equalHeights on How We Work
            if ($('#panel-slikjobbervi').length) {
                var $hww_panel = $('#panel-slikjobbervi');

                $('.center-wrapper .pane-custom', $hww_panel).equalHeights();
                $('.center-wrapper .pane-node', $hww_panel).equalHeights();
            };
            
            // Move webforms select labels to 1st option.
            if ($('form.webform-client-form select').length) {
                $('form.webform-client-form select').each(function() {
                    // wip...
                });
            };
        }
    };

})(jQuery);

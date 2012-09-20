/*
 * FrontD7 scripts.
 */

(function($) {

    Drupal.behaviors.frontSearch = {
        attach: function(context) {
            if ($('#header .search-form', context).length) {
                var searchForm = $('#header .search-form', context);

                $('span.toggle', searchForm).live('click', function(e) {
                    e.preventDefault();
                    searchForm.toggleClass('search-active');
                    $('#main-menu', context).fadeToggle();
                    $('input.form-text', searchForm).focus();

                    window.setTimeout(function() {
                        $('input.form-text', searchForm).focus();
                    }, 800);
                });
            }
        }
    };

    Drupal.behaviors.frontd7 = {
        attach: function(context) {
            $(window).load(function() {
                $('input[placeholder], textarea[placeholder]').placeholder();

                // Set equalHeights on How We Work
                if ($('#panel-slikjobbervi', context).length) {
                    var $hww_panel = $('#panel-slikjobbervi', context);

                    $('.center-wrapper .pane-custom', $hww_panel).equalHeights();
                    $('.center-wrapper .pane-node', $hww_panel).equalHeights();
                }

                // Set equalHeights on How We Work
                if ($('#panel-medarbeidere', context).length) {
                    $('#panel-medarbeidere .view-employees .views-row', context).equalHeights();
                }
            });

            // Improve webforms select elements.
            if ($('form.webform-client-form select', context).length) {
                var $select = $('form.webform-client-form select', context);

                $('option:first', $select).each(function() {
                    var $this = $(this);
                    if (!$this.val().length) {
                        $this.text($this.parent().prev('label').text().replace('*',''));
                    };
                });
                $select.customSelect();
            }

            // Helper for image alignment
            // @todo: remove this after fix registry / theme override issue.
            $('.content img[style]').each(function() {
                if ($('[style*"float: right"]', this)) {
                    $(this).addClass('align-right');
                }
                else if ($('[style*"float: left"]', this)) {
                    $(this).addClass('align-left');
                }
            });

            // Responsive video players
            $('.node-video .field-name-video-620px .field-item').fitVids();
        }
    };

    Drupal.behaviors.frontMenu = {
        attach: function(context) {
            // Taxonomies menus.
            if ($('.view-taxonomy-menu', context).length) {
                $('.view-taxonomy-menu', context).each(function() {
                    var $menu = $('.view-content', this);

                    // Show children of the current active menu item.
                    $('h3 a.active', $menu).toggleClass('open').parent('h3').next('ul').show();
                    // Show siblings of the current active menu item
                    // and activate the parent term link.
                    $('ul a.active', $menu).parents('ul').show().prev('h3').find('a').toggleClass('open');

                    // Slide down/up on click.
                    /* Remove?
                    $('h3 a', $menu).each(function() {
                        var $this = $(this);

                        $this.click(function(e) {
                            if (!$this.hasClass('open')) {
                                e.preventDefault();
                                $('h3 a.open', $menu).toggleClass('open').parent('h3').next('ul').slideUp();
                                $this.toggleClass('open').parent('h3').next('ul').slideDown();
                            }
                        });
                    });
                    */
                });
            }
        }
    };

    // Prevents the form from submitting if the suggestions popup is open
    // and closes the suggestions popup when doing so.
    //
    // Changed: Only prevent form from submitting when an item in the autocomplete list is selected.
    Drupal.autocompleteSubmit = function () {
        if ($('#autocomplete .selected').length > 0) {
            return $('#autocomplete').each(function () {
                this.owner.hidePopup();
            }).size() == 0;
        }
        return true;
    };

})(jQuery);

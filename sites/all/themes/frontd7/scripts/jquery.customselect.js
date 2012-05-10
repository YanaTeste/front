/* Forked from https://github.com/adamcoulombe/jquery.customSelect */
(function($) {
    $.fn.extend({
        customSelect: function(options) {
            if (!$.browser.msie || ($.browser.msie && $.browser.version > 6)) {
                return this.each(function() {
                    var currentSelected = $(this).find(':selected');
                    var html = currentSelected.html();
                    if (!html) {
                        html = '&nbsp;';
                    }
                    $(this).before('<span class="customStyleSelectBox"><span class="customStyleSelectBoxInner">' + html + '</span></span>');
                    var selectBoxSpan = $(this).prev();
                    var selectBoxSpanInner = selectBoxSpan.find(':first-child');
                    selectBoxSpan.css({
                        display: 'inline-block'
                    });
                    selectBoxSpanInner.css({
                        display: 'inline-block'
                    });
                    var selectBoxHeight = parseInt(selectBoxSpan.height()) + parseInt(selectBoxSpan.css('padding-top')) + parseInt(selectBoxSpan.css('padding-bottom'));
                    $(this).height(selectBoxHeight).change(function() {
                        selectBoxSpanInner.text($(this).find(':selected').text()).parent().addClass('changed');
                    });
                });
            }
        }
    });
})(jQuery);

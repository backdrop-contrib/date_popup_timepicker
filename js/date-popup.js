/**
 * Overrides core file of the same name.
 * Attaches the calendar behavior to all required fields
 */
(function($) {
  function makeFocusHandler(e) {
    if (!$(this).hasClass('date-popup-init')) {
      var datePopup = e.data;
      // Explicitely filter the methods we accept.
      switch (datePopup.func) {
        case 'datepicker':
          $(this)
            .datepicker(datePopup.settings)
            .addClass('date-popup-init');
          $(this).click(function(){
            $(this).focus();
          });
          if (datePopup.settings.syncEndDate) {
            $('.start-date-wrapper').each(function(){
              var start_date_wrapper = this;
              $(this).find('input:eq(0)').change(function(){
                $(start_date_wrapper).next('.end-date-wrapper').find('input:eq(0)').val($(this).val());
              });
            });
          }
          break;

        case 'timeEntry':
          $(this)
            .timeEntry(datePopup.settings)
            .addClass('date-popup-init');
          $(this).click(function(){
            $(this).focus();
          });
          break;

        case 'timepicker':
          // Translate the PHP date format into the style the timepicker uses.
          datePopup.settings.timeFormat = datePopup.settings.timeFormat
            // 12-hour, leading zero,
            .replace('h', 'hh')
            // 12-hour, no leading zero.
            .replace('g', 'h')
            // 24-hour, leading zero.
            .replace('H', 'HH')
            // 24-hour, no leading zero.
            .replace('G', 'H')
            // AM/PM.
            .replace('A', 'p')
            // Minutes with leading zero.
            .replace('i', 'mm')
            // Seconds with leading zero.
            .replace('s', 'ss');

          datePopup.settings.startTime = new Date(datePopup.settings.startTime);
          $(this)
            .timepicker(datePopup.settings)
            .addClass('date-popup-init');
          $(this).click(function(){
            $(this).focus();
          });
          break;
      }
    }
  }

  Backdrop.behaviors.datePopup = {
    attach: function (context) {
      var $context = $(context);
      $context.find('[data-date-popup]').once('date-popup').each(function() {
        bindFocusHandler(this, 'date-popup', 'datepicker');
      });
      $context.find('[data-timeentry]').once('timeentry').each(function() {
        bindFocusHandler(this, 'timeentry', 'timeEntry');
      });
      for (var id in Backdrop.settings.datePopup) {
        $('#'+ id).bind('focus', Backdrop.settings.datePopup[id], makeFocusHandler);
      }
    }
  };

  /**
   * Bind a handler for doing a date or time picker on element focus.
   *
   * This function ensures that an element will not bind the picker twice to
   * the same element. By waiting until element focus, this speeds up the
   * initial page load and only creates the picker when the element is first
   * given focus.
   *
   * @param element
   *   The input element that will receive the picker.
   * @param data_attribute
   *   The data attribute on this element that contains the picker
   *   configuration. For example if the configuration were in a data-date-popup
   *   attribute, the parameter would be 'date-popup'.
   * @param method
   *   The jQuery method to be called on the input element.
   */
  function bindFocusHandler(element, data_attribute, method) {
    var $element = $(element);
    $element.bind('focus', function() {
      if (!$element.hasClass('date-popup-init')) {
        $element[method]($element.data(data_attribute)).addClass('date-popup-init').trigger('focus');
      }
    });
  }
})(jQuery);

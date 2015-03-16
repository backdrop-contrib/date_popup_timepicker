(function($) {
  Drupal.behaviors.DatePopupTimepicker = {
    attach: function(context, settings) {
      for (var id in Drupal.settings.datePopup) {
        if (Drupal.settings.datePopup[id].func == 'timepickerPopup') {
          // TODO convert Drupal.settings.datePopup[id].settings to array and use it in settings timepicker
            $('#'+ id).timepicker({
              showPeriod: Drupal.settings.datePopup[id].settings.showPeriod,
              hourText: Drupal.settings.datePopup[id].settings.hourText,
              minuteText: Drupal.settings.datePopup[id].settings.minuteText
            });
        }
      }
    }
  };
})(jQuery);

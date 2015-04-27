<?php

/**
 * @file
 * jQuery UI Timepicker plugin.
 */

$plugin = array(
  'title' => t('jQuery UI Timepicker'),
  'description' => t('Provides jQuery UI Timepicker integration'),
  'handler' => array(
    'class' => 'DatePopupTimepickerTimepicker',
  ),
);

/**
 * @todo Extend some base class or implement interface.
 */
class DatePopupTimepickerTimepicker {

  /**
   * Get default settings for the plugin.
   *
   * @return array
   *   Settings structured array.
   */
  public function settingsDefaults() {
    $settings = array(
      // The character to use to separate hours and minutes.
      'timeSeparator' => ':',
      // Define whether or not to show a leading zero for hours < 10.
      'showLeadingZero' => TRUE,
      // Define whether or not to show a leading zero for minutes < 10.
      'showMinutesLeadingZero' => TRUE,
      // Define whether or not to show AM/PM with selected time.
      'showPeriod' => FALSE,
      // Define if the AM/PM labels on the left are displayed.
      'showPeriodLabels' => TRUE,
      // The character to use to separate the time from the time period.
      'periodSeparator' => ' ',
      // Define an alternate input to parse selected time to.
      'altField' => '#alternate_input',
      // Used as default time when input field is empty or for inline timePicker.
      // Set to 'now' for the current time, '' for no highlighted time.
      'defaultTime' => 'now',
      // Trigger options.
      // Define when the timepicker is shown.
      // 'focus': when the input gets focus, 'button' when the button trigger element is clicked.
      // 'both': when the input gets focus and when the button is clicked.
      'showOn' => 'focus',
      // jQuery selector that acts as button trigger. ex: '#trigger_button'.
      'button' => NULL,
      // Localization.
      // Define the locale text for "Hours".
      'hourText' => 'Hour',
      // Define the locale text for "Minute".
      'minuteText' => 'Minute',
      // Define the locale text for periods.
      'amPmText' => array('AM', 'PM'),
      // Position.
      // Corner of the dialog to position, used with the jQuery UI Position utility if present.
      'myPosition' => 'left top',
      // Corner of the input to position.
      'atPosition' => 'left bottom',
      // Events.
      // Callback function executed before the timepicker is rendered and displayed.
      'beforeShow' => NULL,
      // Define a callback function when an hour / minutes is selected.
      'onSelect' => NULL,
      // Define a callback function when the timepicker is closed.
      'onClose' => NULL,
      // Define a callback to enable / disable certain hours. ex: function onHourShow(hour).
      'onHourShow' => NULL,
      // Define a callback to enable / disable certain minutes. ex: function onMinuteShow(hour, minute).
      'onMinuteShow' => NULL,
      // Custom hours and minutes.
      'hours' => array(
        // First displayed hour.
        'starts' => 0,
        // Last displayed hour.
        'ends' => 23,
      ),
      'minutes' => array(
        // First displayed minute.
        'starts' => 0,
        // Last displayed minute.
        'ends' => 55,
        // Interval of displayed minutes.
        'interval' => 5,
        // Optional extra entries for minutes.
        'manual' => array(),
      ),
      // Number of rows for the input tables, minimum 2, makes more sense if you use multiple of 2.
      'rows' => 4,
      // Define if the hours section is displayed or not. Set to false to get a minute only dialog.
      'showHours' => TRUE,
      // Define if the minutes section is displayed or not. Set to false to get an hour only dialog.
      'showMinutes' => TRUE,

      // Min and Max time.
      // Set the minimum time selectable by the user, disable hours and minutes
      // previous to min time.
      'minTime' => array(
        'hour' => NULL,
        'minute' => NULL,
      ),
      // Set the minimum time selectable by the user, disable hours and minutes
      // after max time.
      'maxTime' => array(
        'hour' => NULL,
        'minute' => NULL,
      ),
      // Buttons.
      // Shows an OK button to confirm the edit.
      'showCloseButton' => FALSE,
      // Text for the confirmation button (ok button).
      'closeButtonText' => 'Done',
      // Shows the 'now' button.
      'showNowButton' => FALSE,
      // Text for the now button.
      'nowButtonText' => 'Now',
      // Shows the deselect time button.
      'showDeselectButton' => FALSE,
      // Text for the deselect button.
      'deselectButtonText' => 'Deselect',
    );
    return $settings;
  }

  /**
   * Get field settings form.
   *
   * @param array $form
   *   Settings form definition.
   *
   * @param array $context
   *   Array containing 3 elements: field info, instance info and has_data flag.
   *
   * @param array $settings
   *   Currently saved settings in the field.
   *
   * @return array
   *   Timepicker settings form part definition.
   */
  public function fieldSettingsForm($form, $context, $settings = array()) {
    $element = array();
    $defaults = $this->settingsDefaults();
    // @todo drupal_array_merge_deep() will fail on amPmText... Think about.
    $settings = drupal_array_merge_deep($defaults, $settings);
    $element['timeSeparator'] = array(
      '#type' => 'textfield',
      '#title' => t('Time separator'),
      '#description' => t('The character to use to separate hours and minutes.'),
      '#default_value' => $settings['timeSeparator'],
    );
    $element['showLeadingZero'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show leading zero'),
      '#description' => t('Define whether or not to show a leading zero for hours < 10.'),
      '#default_value' => $settings['showLeadingZero'],
    );
    $element['showMinutesLeadingZero'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show minutes leading zero'),
      '#description' => t('Define whether or not to show a leading zero for minutes < 10.'),
      '#default_value' => $settings['showMinutesLeadingZero'],
    );
    $element['showPeriod'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show period'),
      '#description' => t('Define whether or not to show AM/PM with selected time.'),
      '#default_value' => $settings['showPeriod'],
    );
    $element['showPeriodLabels'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show period labels'),
      '#description' => t('Define if the AM/PM labels on the left are displayed.'),
      '#default_value' => $settings['showPeriodLabels'],
    );
    $element['periodSeparator'] = array(
      '#type' => 'textfield',
      '#title' => t('Period separator'),
      '#description' => t('The character to use to separate the time from the time period.'),
      '#default_value' => $settings['periodSeparator'],
    );
    // Define an alternate input to parse selected time to
//    $form['altField'] = array();
    // @todo Use date_popup element.
    $element['defaultTime'] = array(
      '#type' => 'textfield',
      '#title' => t('Default time'),
      '#description' => t("Used as default time when input field is empty or for inline timePicker. Set to 'now' for the current time, '' for no highlighted time"),
      '#default_value' => $settings['defaultTime'],
    );
    $element['showOn'] = array(
      '#type' => 'select',
      '#title' => t('Show on'),
      '#description' => t("Define when the timepicker is shown."),
      '#options' => array(
        'focus' => t('Focus'),
        'button' => t('Button'),
        'both' => t('Both'),
      ),
      '#default_value' => $settings['showOn'],
    );
    // jQuery selector that acts as button trigger. ex: '#trigger_button'
//    $element['button'] = array();
    $element['hourText'] = array(
      '#type' => 'textfield',
      '#title' => t('Hour text'),
      '#default_value' => $settings['hourText'],
    );
    $element['minuteText'] = array(
      '#type' => 'textfield',
      '#title' => t('Minute text'),
      '#default_value' => $settings['minuteText'],
    );
    $element['amPmText'] = array(
      '#type' => 'fieldset',
      '#title' => t('Periods text'),
      '#collapsible' => FALSE,
      0 => array(
        '#type' => 'textfield',
        '#title' => t('AM'),
        '#default_value' => $settings['amPmText'][0],
      ),
      1 => array(
        '#type' => 'textfield',
        '#title' => t('PM'),
        '#default_value' => $settings['amPmText'][1],
      ),
    );
    // Corner of the dialog to position, used with the jQuery UI Position utility if present.
//    $element['myPosition'] = array();
    // Corner of the input to position
//    $element['atPosition'] = array();
    $element['hours'] = array(
      '#type' => 'fieldset',
      '#title' => t('Hours'),
      '#collapsible' => FALSE,
      'starts' => array(
        '#type' => 'textfield',
        '#title' => t('Starts'),
        '#description' => t('First displayed hour'),
        '#default_value' => $settings['hours']['starts'],
      ),
      'ends' => array(
        '#type' => 'textfield',
        '#title' => t('Ends'),
        '#description' => t('Last displayed hour'),
        '#default_value' => $settings['hours']['starts'],
      ),
    );
    $element['minutes'] = array(
      '#type' => 'fieldset',
      '#title' => t('Minutes'),
      '#collapsible' => FALSE,
      'starts' => array(
        '#type' => 'textfield',
        '#title' => t('Starts'),
        '#description' => t('First displayed minute'),
        '#default_value' => $settings['minutes']['starts'],
      ),
      'ends' => array(
        '#type' => 'textfield',
        '#title' => t('Ends'),
        '#description' => t('Last displayed minute'),
        '#default_value' => $settings['minutes']['starts'],
      ),
      'interval' => array(
        '#type' => 'textfield',
        '#title' => t('Interval'),
        '#description' => t('Interval of displayed minutes'),
        '#default_value' => $settings['minutes']['interval'],
      ),
      // Optional extra entries for minutes
//      'manual' => array(),
    );
    $element['rows'] = array(
      '#type' => 'textfield',
      '#title' => t('Rows'),
      '#description' => t('Number of rows for the input tables, minimum 2, makes more sense if you use multiple of 2'),
      '#default_value' => $settings['rows'],
    );
    $element['showHours'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show hours'),
      '#description' => t('Define if the hours section is displayed or not. Set to false to get a minute only dialog'),
      '#default_value' => $settings['showHours'],
    );
    $element['showMinutes'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show minutes'),
      '#description' => t('Define if the minutes section is displayed or not. Set to false to get an hour only dialog'),
      '#default_value' => $settings['showMinutes'],
    );
    $element['minTime'] = array(
      '#type' => 'fieldset',
      '#title' => t('Min time'),
      '#description' => t('Set the minimum time selectable by the user, disable hours and minutes previous to min time'),
      '#collapsible' => FALSE,
      'hour' => array(
        '#type' => 'textfield',
        '#title' => t('Min hour'),
        '#default_value' => $settings['minTime']['hour'],
      ),
      'minute' => array(
        '#type' => 'textfield',
        '#title' => t('Min minute'),
        '#default_value' => $settings['minTime']['minute'],
      ),
    );
    $element['maxTime'] = array(
      '#type' => 'fieldset',
      '#title' => t('Max time'),
      '#description' => t('Set the minimum time selectable by the user, disable hours and minutes after max time'),
      '#collapsible' => FALSE,
      'hour' => array(
        '#type' => 'textfield',
        '#title' => t('Max hour'),
        '#default_value' => $settings['maxTime']['hour'],
      ),
      'minute' => array(
        '#type' => 'textfield',
        '#title' => t('Max minute'),
        '#default_value' => $settings['maxTime']['minute'],
      ),
    );
    $element['showCloseButton'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show close button'),
      '#description' => t('Shows an OK button to confirm the edit'),
      '#default_value' => $settings['showCloseButton'],
    );
    $element['closeButtonText'] = array(
      '#type' => 'textfield',
      '#title' => t('Close button text'),
      '#description' => t('Text for the confirmation button (ok button)'),
      '#default_value' => $settings['closeButtonText'],
    );
    $element['showNowButton'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show now button'),
      '#description' => t('Shows the "now" button'),
      '#default_value' => $settings['showNowButton'],
    );
    $element['nowButtonText'] = array(
      '#type' => 'textfield',
      '#title' => t('Now button text'),
      '#description' => t('Text for the now button'),
      '#default_value' => $settings['nowButtonText'],
    );
    $element['showDeselectButton'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show deselect button'),
      '#description' => t('Shows the deselect time button'),
      '#default_value' => $settings['showDeselectButton'],
    );
    $element['deselectButtonText'] = array(
      '#type' => 'textfield',
      '#title' => t('Deselect button text'),
      '#description' => t('Text for the deselect button'),
      '#default_value' => $settings['nowButtonText'],
    );
    return array(
      // timepicker_options elements must be always defined.
      // There is no need to define #tree => TRUE.
      'timepicker_options' => $element,
    );
  }

  /**
   * Element process callback.
   *
   * @param array $element
   *   Form element structure to process.
   *
   * @param array $form_state
   *   Form state.
   *
   * @param array $form
   *   The whole form definition structure.
   *
   * @return array
   *   Processed form element.
   */
  public function processElement($element, &$form_state, $form) {
    $granularity = date_popup_time_granularity($element);
    $settings_default = array(
      'showHours' => in_array('hour', $granularity),
      'showMinutes' => in_array('minute', $granularity),
    );
    $element['#timepicker_options'] = drupal_array_merge_deep($settings_default, $element['#timepicker_options']);
    $element['#attached']['library'][] = array('system', 'ui.core');
    $element['#attached']['library'][] = array('system', 'ui.widget');

    // Add Timepicker library.
    $element['#attached']['libraries_load'][] = array('timepicker');
    // @todo is it the best place for plugin specific .js?
    $element['#attached']['js'][] = drupal_get_path('module', 'date_popup_timepicker') . "/js/date_popup_timepicker.timepicker.js";

    return $element;
  }

  /**
   * Provide library definition for libraries module.
   *
   * @return array
   *   Library definition.
   *
   * @see hook_libraries_info()
   */
  public function librariesInfo() {
    $libraries = array();
    $libraries['timepicker'] = array(
      'name' => 'jQuery UI Timepicker',
      'vendor url' => 'https://fgelinas.com/code/timepicker',
      'download url' => 'https://fgelinas.com/code/timepicker/releases/jquery-ui-timepicker-0.3.3.zip',
      'version arguments' => array(
        'file' => 'jquery.ui.timepicker.js',
        'pattern' => '/version\: \"(\d\.\d.\d)\"/',
        'lines' => 43,
      ),
      'files' => array(
        'js' => array(
          'jquery.ui.timepicker.js',
        ),
        'css' => array(
          'jquery.ui.timepicker.css',
        ),
      ),
      'variants' => array(
        'source' => array(
          'files' => array(
            'js' => array(
              'jquery.ui.timepicker.js',
            ),
            'css' => array(
              'jquery.ui.timepicker.css',
            ),
          ),
        ),
      ),
    );

    return $libraries;
  }
}
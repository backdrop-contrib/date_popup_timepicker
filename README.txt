About Date Popup Timepicker for Drupal
--------------------------------------------------------------------------------
This module extends date_popup module and allows to use jQuery UI Timepicker
for "time" part of date_time field.
--------------------------------------------------------------------------------

Required Modules
--------------------------------------------------------------------------------
* Libraries           - http://drupal.org/project/libraries
* Date -> Date Popup  - http://drupal.org/project/date
--------------------------------------------------------------------------------

Installation and configuration
--------------------------------------------------------------------------------
1. Enable this module together required modules.
2. Download library from https://fgelinas.com/code/timepicker/releases/jquery-ui-timepicker-0.3.3.zip unzip it and put
into  /sites/all/libraries/timepicker
3. Enable timepicker on /admin/config/date/date_popup. In field "Timepicker" choose "jQuery UI Timepicker"
Now on all fields of type date_time in part "time" will call "jQuery UI Timepicker" plugin.

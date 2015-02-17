CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Maintainers


INTRODUCTION
------------

The Date Popup Timepicker module adds one more timepicker option for elements
of date_popup type and date_popup widgets for date fields provided by the Date
module (https://www.drupal.org/project/date). It uses jQuery UI Timepicker
(By François Gélinas) timepicker library, and provided widget looks very similar
to core's jQuery UI Datepicker widget shipped with Drupal core and utilized by
the Date module.


 * For a full description of the module, visit the project page:
   https://www.drupal.org/project/date_popup_timepicker


 * To submit bug reports and feature suggestions, or to track changes:
   https://www.drupal.org/project/issues/date_popup_timepicker


REQUIREMENTS
------------

This module requires the following modules:
 * Date Popup, part of the Date module (https://www.drupal.org/project/date)
 * Libraries (https://www.drupal.org/project/libraries)


INSTALLATION
------------
 * Dowload jQuery UI Timepicker (By François Gélinas) library
   https://fgelinas.com/code/timepicker/#get_timepicker and put its content to
   "timepicker" directory inside libraries directory
   (usually sites/all/libraries) so you should have
   sites/all/libraries/timepicker directory and jquery.ui.timepicker.js and
   jquery.ui.timepicker.css in it.
   See https://www.drupal.org/node/1440066 for more details.

 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.


CONFIGURATION
-------------

 * Choose "jQuery UI Timepicker" option in Configuration » Date API » Date Popup


MAINTAINERS
-----------
Current maintainers:
 * develnk - https://www.drupal.org/u/develnk
 * antongp - https://www.drupal.org/u/antongp


This project is created by ADCI Solutions team (http://drupal.org/node/1542952).

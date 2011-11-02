<?php
/**
 * @file
 */

/**
 * CTools Export UI required function for plugin definition.
 */
function tweaker_ui_tweaker_ui_ctools_export_ui() {
  return array(
    'schema' => 'tweaks',
    'access' => 'administer tweaks',

    'menu' => array(
      'menu prefix' => 'admin/structure',
      'menu item' => 'tweaker',
      'menu title' => 'Tweaker',
      'menu description' => 'Administer Tweaks.',
    ),

    'title singular' => t('tweak'),
    'title singular proper' => t('Tweak'),
    'title plural' => t('tweaks'),
    'title plural proper' => t('Tweaks'),

    'handler' => 'tweaker_ui',

    //'form' => array(
    //  'settings' => 'tweaker_ui_settings_form',
    //  'submit' => 'tweaker_ui_settings_form_submit',
    //),

    'export' => array(
      'admin_title' => 'label',
      'admin_description' => 'description',
    ),
  );
}

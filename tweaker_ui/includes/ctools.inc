<?php
/**
 * @file
 * Chaos Tools module integration.
 */

/**
 * Implements hook_ctools_plugin_directory().
 */
function tweaker_ui_ctools_plugin_directory($module, $plugin) {
  if ($module == 'ctools' && $plugin == 'export_ui') {
    return "plugins/{$plugin}";
  }
}

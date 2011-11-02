<?php
/**
 * @file
 * Chaos Tools module integration.
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tweaker_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == 'tweaker' && $api == 'tweaker') {
    return array('version' => 1);
  }
}

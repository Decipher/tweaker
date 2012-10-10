<?php
/**
 * @file
 * System module integration.
 */

/**
 * Implements hook_tweaker_rules_data_info_alter() on behalf of system.module.
 */
function system_tweaker_rules_data_info_alter(&$items) {
  $items['menu_item'] = array(
    'label' => t('menu item'),
    'wrap' => TRUE,
    'property info' => array(
      'title' => array(
        'type' => 'text',
        'label' => 'Title',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'title callback' => array(
        'type' => 'text',
        'label' => 'Title callback',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'title arguments' => array(
        'type' => 'list<text>',
        'label' => 'Title arguments',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'description' => array(
        'type' => 'text',
        'label' => 'Description',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'page callback' => array(
        'type' => 'text',
        'label' => 'Page callback',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'page arguments' => array(
        'type' => 'list<text>',
        'label' => 'Page arguments',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'delivery callback' => array(
        'type' => 'text',
        'label' => 'Delivery callback',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'access callback' => array(
        'type' => 'text',
        'label' => 'Access callback',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'access arguments' => array(
        'type' => 'list<text>',
        'label' => 'Access arguments',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'theme callback' => array(
        'type' => 'text',
        'label' => 'Theme callback',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'theme arguments' => array(
        'type' => 'list<text>',
        'label' => 'Theme arguments',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'file' => array(
        'type' => 'text',
        'label' => 'File',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'file path' => array(
        'type' => 'text',
        'label' => 'File path',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'load arguments' => array(
        'type' => 'list<text>',
        'label' => 'Load arguments',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'weight' => array(
        'type' => 'decimal',
        'label' => 'Weight',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'menu_name' => array(
        'type' => 'text',
        'label' => 'Menu name',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'context' => array(
        'type' => 'list<text>',
        'label' => 'Context',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'tab_parent' => array(
        'type' => 'text',
        'label' => 'Tab parent',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'tab_root' => array(
        'type' => 'text',
        'label' => 'Tab root',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'position' => array(
        'type' => 'text',
        'label' => 'Position',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'type' => array(
        'type' => 'list<text>',
        'label' => 'Type',
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'options' => array(
        'type' => 'list<text>',
        'label' => 'Options',
        'setter callback' => 'entity_property_verbatim_set',
      ),
    ),
    'module' => 'tweaker',
  );

  $items['reference<boolean>'] = array(
    'label' => t('a boolean reference'),
    'wrap' => TRUE,
    'property info' => array(
      'value' => array(
        'type' => 'boolean',
        'label' => t('Value'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
    ),
  );
}

/**
 * Implements hook_tweaker_rules_event_info_alter() on behalf of system.module.
 */
function system_tweaker_rules_event_info_alter(&$items) {
  $items['form_alter'] = array(
    'label' => t('Before a form is rendered'),
    'group' => t('System'),
    'variables' => array(
      'form' => array(
        'label' => t('Form'),
        'type' => 'array',
      ),
      'form_state' => array(
        'label' => t('Form state'),
        'type' => 'array',
      ),
      'form_id' => array(
        'label' => t('Form id'),
        'type' => 'text',
      ),
    ),
  );

  $items['menu_access_callback'] = array(
    'label' => t('Menu access callback is being executed'),
    'group' => t('System'),
    'variables' => array(
      'access' => array(
        'label' => t('Access'),
        'type' => 'reference<boolean>',
      ),
      'path' => array(
        'label' => t('Menu path'),
        'type' => 'text',
      ),
    ),
  );

  $items['menu_alter'] = array(
    'label' => t('The menu is being rebuilt'),
    'group' => t('System'),
    'variables' => array(
      'item' => array(
        'label' => t('Menu item'),
        'type' => 'menu_item',
      ),
      'path' => array(
        'label' => t('Menu path'),
        'type' => 'text',
      ),
    ),
  );

  $items['preprocess'] = array(
    'label' => t('Preprocess theme variables'),
    'group' => t('System'),
    'variables' => array(
      'variables' => array(
        'label' => t('Theme variables'),
        'type' => 'array',
      ),
      'hook' => array(
        'label' => t('Theme hook name'),
        'type' => 'text',
      ),
    ),
  );
}

/**
 * Implements hook_form_alter().
 */
function tweaker_form_alter(&$form, &$form_state, $form_id) {
  rules_invoke_event('form_alter', $form, $form_state, $form_id);
}

/**
 * Implements hook_preprocess().
 */
function tweaker_menu_alter(&$items) {
  foreach ($items as $path => &$item) {
    $item = (object) $item;
    rules_invoke_event('menu_alter', $item, $path);
    $item = (array) $item;

    // Inherit access arguments from parent.
    if (!isset($item['access callback']) && empty($item['access arguments'])) {
      $parts = explode('/', $path, MENU_MAX_PARTS);
      for ($i = count($parts) - 1; $i; $i--) {
        $parent_path = implode('/', array_slice($parts, 0, $i));
        if (isset($items[$parent_path])) {
          $parent = $items[$parent_path];
          if ($parent['access arguments'][0] == $parent_path) {
            array_shift($parent['access arguments']);
            array_shift($parent['access arguments']);
          }
          $item['access arguments'] = $parent['access arguments'];
          break;
        }
      }
    }

    // Add menu path and access callback to access arguments array.
    $access_callback = isset($item['access callback']) ? $item['access callback'] : 'user_access';
    if (!isset($item['access arguments'])) {
      $item['access arguments'] = array();
    }
    array_unshift($item['access arguments'], $access_callback);
    array_unshift($item['access arguments'], $path);
    $item['access callback'] = '_tweaker_menu_access_callback';
  }
}

/**
 * Access callback for hook_menu().
 */
function _tweaker_menu_access_callback() {
  $args = func_get_args();
  $path = array_shift($args);
  $access_callback = array_shift($args);

  // Invoke rules event.
  $access = new stdClass();
  $access->value = NULL;
  rules_invoke_event('menu_access_callback', $access, $path);
  if (!is_null($access->value)) {
    return $access->value;
  }

  // Pass back to the original access callback.
  if (function_exists($access_callback)) {
    return call_user_func_array($access_callback, $args);
  }
  return $access_callback;
}


/**
 * Implements hook_preprocess().
 */
function tweaker_preprocess(&$variables, $hook) {
  rules_invoke_event('preprocess', $variables, $hook);
}

function test_function() {
  return 'test123';
}

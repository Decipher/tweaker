<?php
/**
 * @file
 * System module integration.
 */


/**
 * Implements hook_tweaker_rules_data_info_alter() on behalf of system.module.
 */
function system_tweaker_rules_action_info_alter(&$items) {
  $items['form_set_error'] = array(
    'label' => t('File an error against a form element'),
    'parameter' => array(
      'name' => array(
        'type' => 'text',
        'label' => t('Form element name'),
        'allow null' => TRUE,
      ),
      'message' => array(
        'type' => 'text',
        'label' => t('Error message'),
        'optional' => TRUE,
      ),
    ),
    'group' => t('System'),
    'base' => 'tweaker_rules_action_form_set_error',
  );

  $items['querystring_get'] = array(
    'label' => t('Get query string'),
    'group' => t('System'),
    'parameter' => array(
      'key' => array(
        'type' => 'text',
        'label' => t('Key'),
      ),
    ),
    'provides' => array(
      'querystring' => array(
        'type' => 'text',
        'label' => t('Query string'),
      ),
    ),
    'base' => 'tweaker_rules_action_querystring_get',
  );

  $items['session_set'] = array(
    'label' => t('Set a session variable'),
    'group' => t('System'),
    'parameter' => array(
      'key' => array(
        'type' => 'text',
        'label' => t('Key'),
      ),
      'value' => array(
        'type' => '*',
        'label' => t('Value'),
      ),
    ),
    'base' => 'tweaker_rules_action_session_get',
  );
}

/**
 * Implements hook_tweaker_rules_condition_info_alter() on behalf of
 * system.module.
 */
function system_tweaker_rules_condition_info_alter(&$items) {
  $items['querystring_isset'] = array(
    'label' => t('Query string is set'),
    'group' => t('System'),
    'parameter' => array(
      'key' => array(
        'type' => 'text',
        'label' => t('Key'),
      ),
    ),
    'base' => 'system_tweaker_condition_querystring_isset',
  );
}

/**
 * Implements hook_tweaker_rules_data_info_alter() on behalf of system.module.
 */
function system_tweaker_rules_data_info_alter(&$items) {
  $items['form'] = array(
    'label' => t('form'),
    'wrap' => TRUE,
    'property info' => array(
      '#node_edit_form' => array(
        'type' => 'boolean',
        'label' => t('Node edit form'),
      ),
      '#attributes' => array(
        'type' => 'list<text>',
        'label' => t('Attributes'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      '#node' => array(
        'type' => 'node',
        'label' => t('Node'),
      ),
      '#submit' => array(
        'type' => 'list<text>',
        'label' => t('Submit callbacks'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      '#form_id' => array(
        'type' => 'text',
        'label' => t('Form ID'),
      ),
      '#type' => array(
        'type' => 'text',
        'label' => t('Type'),
      ),
      '#build_id' => array(
        'type' => 'text',
        'label' => t('Build ID'),
      ),
      '#token' => array(
        'type' => 'text',
        'label' => t('Token'),
      ),
      '#id' => array(
        'type' => 'text',
        'label' => t('ID'),
      ),
      '#method' => array(
        'type' => 'text',
        'label' => t('Method'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      '#action' => array(
        'type' => 'text',
        'label' => t('Action'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      '#theme_wrappers' => array(
        'type' => 'list<text>',
        'label' => t('Theme wrappers'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      '#tree' => array(
        'type' => 'boolean',
        'label' => t('Tree'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      '#parents' => array(
        'type' => 'list<text>',
        'label' => t('Parents'),
      ),
      '#entity' => array(
        'type' => 'entity',
        'label' => t('Entity'),
      ),
      '#validate' => array(
        'type' => 'list<text>',
        'label' => t('Validate callbacks'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      '#theme' => array(
        'type' => 'list<text>',
        'label' => t('Theme callbacks'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
    ),
  );

  $items['form_state'] = array(
    'label' => t('form state'),
    'wrap' => TRUE,
    'property info' => array(
      'rebuild' => array(
        'type' => 'boolean',
        'label' => t('Rebuild'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
    ),
  );

  $items['menu_item'] = array(
    'label' => t('menu item'),
    'wrap' => TRUE,
    'property info' => array(
      'title' => array(
        'type' => 'text',
        'label' => t('Title'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'title callback' => array(
        'type' => 'text',
        'label' => t('Title callback'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'title arguments' => array(
        'type' => 'list<text>',
        'label' => t('Title arguments'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'description' => array(
        'type' => 'text',
        'label' => t('Description'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'page callback' => array(
        'type' => 'text',
        'label' => t('Page callback'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'page arguments' => array(
        'type' => 'list<text>',
        'label' => t('Page arguments'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'delivery callback' => array(
        'type' => 'text',
        'label' => t('Delivery callback'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'access callback' => array(
        'type' => 'text',
        'label' => t('Access callback'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'access arguments' => array(
        'type' => 'list<text>',
        'label' => t('Access arguments'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'theme callback' => array(
        'type' => 'text',
        'label' => t('Theme callback'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'theme arguments' => array(
        'type' => 'list<text>',
        'label' => t('Theme arguments'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'file' => array(
        'type' => 'text',
        'label' => t('File'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'file path' => array(
        'type' => 'text',
        'label' => t('File path'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'load arguments' => array(
        'type' => 'list<text>',
        'label' => t('Load arguments'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'weight' => array(
        'type' => 'decimal',
        'label' => t('Weight'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'menu_name' => array(
        'type' => 'text',
        'label' => t('Menu name'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'context' => array(
        'type' => 'list<text>',
        'label' => t('Context'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'tab_parent' => array(
        'type' => 'text',
        'label' => t('Tab parent'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'tab_root' => array(
        'type' => 'text',
        'label' => t('Tab root'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'position' => array(
        'type' => 'text',
        'label' => t('Position'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'type' => array(
        'type' => 'list<text>',
        'label' => t('Type'),
        'setter callback' => 'entity_property_verbatim_set',
      ),
      'options' => array(
        'type' => 'list<text>',
        'label' => t('Options'),
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
        'type' => 'form',
        'label' => t('Form'),
      ),
      'form_state' => array(
        'type' => 'form_state',
        'label' => t('Form state'),
      ),
      'form_id' => array(
        'type' => 'text',
        'label' => t('Form id'),
      ),
    ),
  );

  $items['form_validate'] = array(
    'label' => t('A form is being validated'),
    'group' => t('System'),
    'variables' => array(
      'form' => array(
        'type' => 'form',
        'label' => t('Form'),
      ),
      'form_state' => array(
        'type' => 'form_state',
        'label' => t('Form state'),
      ),
    ),
  );

  $items['menu_access_callback'] = array(
    'label' => t('Menu access callback is being executed'),
    'group' => t('System'),
    'variables' => array(
      'access' => array(
        'type' => 'reference<boolean>',
        'label' => t('Access'),
      ),
      'path' => array(
        'type' => 'text',
        'label' => t('Menu path'),
      ),
    ),
  );

  $items['menu_alter'] = array(
    'label' => t('The menu is being rebuilt'),
    'group' => t('System'),
    'variables' => array(
      'item' => array(
        'type' => 'menu_item',
        'label' => t('Menu item'),
      ),
      'path' => array(
        'type' => 'text',
        'label' => t('Menu path'),
      ),
    ),
  );

  $items['preprocess'] = array(
    'label' => t('Preprocess theme variables'),
    'group' => t('System'),
    'variables' => array(
      'variables' => array(
        'type' => 'list<text>',
        'label' => t('Theme variables'),
      ),
      'hook' => array(
        'type' => 'text',
        'label' => t('Theme hook name'),
      ),
    ),
  );
}

/**
 * Implements hook_form_alter().
 */
function tweaker_form_alter(&$form, &$form_state, $form_id) {
  rules_invoke_event('form_alter', $form, $form_state, $form_id);

  $form['#validate'][] = '_tweaker_form_validate';
}

function _tweaker_form_validate(&$form, &$form_state) {
  rules_invoke_event('form_validate', $form, $form_state);
}

/**
 * Implements hook_preprocess().
 */
function tweaker_menu_alter(&$items) {
  drupal_alter('tweaker_menu', $items);

  foreach ($items as $path => &$item) {
    // Invoke rules event.
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
            $parent['access callback'] = array_shift($parent['access arguments']);
          }
          $item['access arguments'] = $parent['access arguments'];
          if (empty($item['access callback']) && !empty($parent['access callback'])) {
            $item['access callback'] = $parent['access callback'];
          }
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

/**
 * Rules action callback for 'form_set_error'.
 */
function tweaker_rules_action_form_set_error($name, $message) {
  form_set_error($name, $message);
}

/**
 * Rules action callback for 'querystring_get'.
 */
function tweaker_rules_action_querystring_get($key) {
  $querystring = NULL;
  if (system_tweaker_condition_querystring_isset($key)) {
    $querystring = $_GET[$key];
  }

  return array(
    'querystring' => $querystring,
  );
}

/**
 * Rules condition callback for 'querystring_isset'.
 */
function system_tweaker_condition_querystring_isset($key) {
  return isset($_GET[$key]);
}

/**
 * Rules action callback for 'session_set'.
 */
function tweaker_rules_action_session_get($key, $value) {
  $merge = array();
  drupal_array_set_nested_value($merge, explode('][', $key), $value);
  $_SESSION = array_merge_recursive($_SESSION, $merge);
}
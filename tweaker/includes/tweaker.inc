<?php
/**
 * @file
 */

/**
 * Implements hook_tweaker_deafults().
 */
function tweaker_default_tweaks() {
  $tweaks = array();

  $tweak = new stdClass;
  $tweak->disabled = TRUE; /* Edit this to true to make a default tweak disabled initially */
  $tweak->api_version = 1;
  $tweak->name = 'node_hide_options';
  $tweak->label = 'Node: Hide options';
  $tweak->description = 'Hides \'Promoted to front page\' and \'Sticky at top of lists\' options from Node forms.';
  $tweak->hook = 'form_alter';
  $tweak->conditions = array(
    'require_all' => TRUE,
    0 => array(
      'type' => 'callback',
      'function' => 'preg_match',
      'arguments' => array(
        0 => array(
          'type' => 'regex',
          'value' => '/(.*?)_node_form/',
        ),
        1 => array(
          'type' => 'variable',
          'value' => 'form_id',
        ),
      ),
    ),
    1 => array(
      'type' => 'callback',
      'function' => 'isset',
      'arguments' => array(
        0 => array(
          'type' => 'variable',
          'value' => 'form',
          'index' => 'options',
        ),
      ),
    ),
  );
  $tweak->reactions = array(
    0 => array(
      'type' => 'php',
      'value' => '$form[\'options\'][\'promote\'][\'#access\'] = FALSE;
$form[\'options\'][\'sticky\'][\'#access\'] = FALSE;',
    ),
  );
  $tweaks[$tweak->name] = $tweak;

  $tweak = new stdClass;
  $tweak->disabled = TRUE; /* Edit this to true to make a default tweak disabled initially */
  $tweak->api_version = 1;
  $tweak->name = 'test';
  $tweak->label = 'Test';
  $tweak->description = 'Test';
  $tweak->hook = 'form_alter';
  $tweak->conditions = array(
    'require_all' => TRUE,
    0 => array(
      'type' => 'php',
      'value' => '1 == 1',
    ),
  );
  $tweak->reactions = array(
    0 => array(
      'type' => 'form_callback',
      'arguments' => array(
        0 => array(
          'type' => 'string',
          'value' => 'submit',
        ),
        1 => array(
          'type' => 'variable',
          'value' => 'form',
        ),
      ),
      'value' => 'dpm($form_state);',
    ),
  );
  $tweaks[$tweak->name] = $tweak;

  return $tweaks;
}

/**
 *
 */
function tweaker_conditions_comparison($condition, &$tweak) {
  tweaker_prepare_arguments($condition['arguments']);

  return isset($condition['operator'])
    ? "{$condition['arguments'][0]} {$condition['operator']} {$condition['arguments'][1]}"
    : '1 == 2';
}

/**
 *
 */
function tweaker_conditions_callback($condition, &$tweak) {
  $constructs = array(
    "die", "echo", "empty", "exit", "eval", "include", "include_once",
    "isset", "list", "print", "require", "require_once", "unset"
  );

  if (isset($condition['function']) && (function_exists($condition['function']) || in_array($condition['function'], $constructs))) {
    tweaker_prepare_arguments($condition['arguments']);
    $arguments = implode(', ', $condition['arguments']);

    return "{$condition['function']}({$arguments})";
  }

  return '1 == 2';
}

/**
 *
 */
function tweaker_conditions_php($condition, &$tweak) {
  return isset($condition['value']) ? $condition['value'] : '';
}

/**
 *
 */
function tweaker_reactions_php($reaction, &$tweak) {
  return isset($reaction['value']) ? $reaction['value'] : '';
}

/**
 *
 */
function tweaker_reactions_php_callback($reaction, &$tweak) {
  tweaker_prepare_arguments($reaction['arguments']);

  $function = "_tweaker_reactions_php_callback_{$tweak->name}_" . md5(serialize($reaction));

  $tweak->assets['php'][] = array(
    'function' => $function,
    'arguments' => isset($reaction['callback arguments']) ? $reaction['callback arguments'] : '',
    'value' => $reaction['value'],
  );

  switch ($reaction['operator']) {
    case 'append':
      return "{$reaction['arguments'][0]}[] = '{$function}';";
      break;

    case 'assign':
      return "{$reaction['arguments'][0]} = '{$function}';";
      break;
  }
}

/**
 *
 */
//function tweaker_reactions_form_callback($reaction, &$tweak) {
//  tweaker_prepare_arguments($reaction['arguments']);
//  $reaction['arguments'][0] = str_replace("'", '', $reaction['arguments'][0]);
//
//  $function = "_tweaker_reactions_{$reaction['arguments'][0]}_{$tweak->name}_" . rand(1000, 9999);
//
//  $tweak->assets['php'][] = array(
//    'function' => $function,
//    'arguments' => '$form, &$form_state',
//    'value' => $reaction['value'],
//  );
//
//  return "{$reaction['arguments'][1]}['#{$reaction['arguments'][0]}'][] = '{$function}';";
//}

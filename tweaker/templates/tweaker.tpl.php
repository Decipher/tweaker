<<?php echo "?" ?>php
/**
 * @file
 * Tweaker module static cache file.
 */

<?php foreach ($hooks as $hook => $data) : ?>
/**
 * Implements hook_<?php echo $hook ?>().
 */
function tweaker_<?php echo $hook ?>(<?php echo $hooks[$hook]['arguments'] ?>) {
<?php foreach ($data['tweaks'] as $tweak) : ?>
  // <?php echo (!empty($tweak->description) ? $tweak->description : $tweak->label) . ".\n" ?>
  if (<?php echo $tweak->conditions ?>) {
    <?php echo $tweak->reactions . "\n" ?>
  }
<?php endforeach ?>
}

<?php if (isset($data['assets']['php'])) : ?>
<?php foreach ($data['assets']['php'] as $asset) : ?>
/**
 *
 */
function <?php echo $asset['function'] ?>(<?php echo $asset['arguments'] ?>) {
  <?php echo $asset['value'] . "\n" ?>
}
<?php endforeach ?>
<?php endif; ?>

<?php endforeach ?>

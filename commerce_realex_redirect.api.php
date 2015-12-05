<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * Allows modules to alter the payer reference sent to realex.
 */
function hook_commerce_realex_redirect_payer_ref_alter(&$payer_ref, $account, $order) {
  $payer_ref = $account->name;
}

/**
 * Allows modules to alter the payment reference sent to realex.
 */
function hook_commerce_realex_redirect_pmt_ref_alter(&$pmt_ref, $order) {
  $pmt_ref = $order->order_id . '-' . $order->uid;
}

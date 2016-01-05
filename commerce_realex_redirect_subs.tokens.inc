<?php

/**
 * @file
 * Builds placeholder replacement tokens for order-related data.
 */

/**
 * Implements hook_token_info().
 */
function commerce_realex_redirect_subs_token_info() {
  return array(
    'tokens' => array(
      'commerce-order' => array(
        'payer-ref' => array(
          'name' => t('Payer ref'),
          'description' => t('The payer ref to take the payment from.'),
        ),
        'pmt-ref' => array(
          'name' => t('PMT ref'),
          'description' => t('The payment method belonging to that payer ref.'),
        ),
        'pmt-expdate' => array(
          'name' => t('PMT exp. date'),
          'description' => t('The expiration date of the credit card used.'),
        ),
      )
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function commerce_realex_redirect_subs_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'commerce-order' && !empty($data['commerce-order'])) {
    $order = $data['commerce-order'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        // Simple key values on the order.
        case 'payer-ref':
          $replacements[$original] = empty($order->data['realex_token']['PAYER_REF']) ? '' : $order->data['realex_token']['PAYER_REF'];
          break;

        case 'pmt-ref':
          $replacements[$original] = empty($order->data['realex_token']['PMT_REF']) ? '' : $order->data['realex_token']['PMT_REF'];
          break;

        case 'pmt-expdate':
          $replacements[$original] = empty($order->data['realex_token']['PMT_EXPDATE']) ? '' : $order->data['realex_token']['PMT_EXPDATE'];
          break;
      }
    }
  }

  return $replacements;
}

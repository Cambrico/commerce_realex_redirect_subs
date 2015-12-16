<?php
/**
 * @file
 * Template to display when Realex payments have finished.
 */
?>
<style type="text/css">
  #response-page {
    text-align: center;
  }
  h2 {
    font-family: Georgia, "Times New Roman", "DejaVu Serif", serif;
    font-weight: normal;
    font-size: 42px;
    color: #2c2c2a;
  }
  a {
    position: relative;
    font-family: Georgia, "Times New Roman", "DejaVu Serif", serif;
    font-size: 28px;
    color: #df5954;
    text-decoration: none;
  }
  a:hover {
    text-decoration: underline;
  }
</style>
<div id="response-page">
  <h2>Order Number:<?php print $variables['order']->order_id ?><br>
  <?php print $message ?></h2>
  <p><?php print $link ?></p>
</div>

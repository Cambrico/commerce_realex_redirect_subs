Realex Payment Redirect
----------------------
A Payment gateway for realex redirect payments, which are payments that use the realex payment secure site, hence the word 'redirect'.  Use this in conjunction with the commerce_realex module at http://drupal.org/project/commerce_realex .  If you are after the remote payment method, in which credit card info is stored on your website and the information send to Realex, then use the commerce_realex module

Installation
------------
 - Download and enable the module
 - Go to the payment methods settings page at
 admin/commerce/config/payment-methods
 - Click the edit on the "Realex Redirect" Rule and then again on the action
 for the rule.
 - Insert secret/merchant and other settings.
 - The Realex gateway requires the url to the Instant Payment notification, which is as follows [your website domain]/commerce_realex/ipn. This has to be entered into the admin area of http://www.realexpayments.com/.
 - The url above is used for both i) sending the ipn to your website and ii) providing the content for the response page.
 - The response page is the page that is used after a payment is put through. The user is not directed there, rather the content of that page is scraped and displayed by Realex. The commerce_realex module uses the template commerce-realex-response-page.tpl.php for this purpose and a javascript redirect to the url set below under Response Page. This template can be overridden by the usual method of creating a namesake in your theme directory.
 - The module comes by default with a response page at commerce_realex/complete.  You should create a valid page and enter the url into settings
 - The Realex gateway also allows for an html template to be used to format both the Response Page and the Payment page. The Payment Page is the page that is presented allowing the purchaser to securely enter their credit card details.  However in the default module, the normal behaviour of Realex is overridden by redirecting the user back to your website.  To disable the module behaviour use YOUR_THEME_YOUR_THEME_commerce_realex_redirect_response_page($order, $success, $payment_method) in template.php to override the module theme template.

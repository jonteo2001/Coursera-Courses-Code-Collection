<html>
<head>
</head>
<body>
<p>Here is some awesome page content</p>
<script type="text/javascript" src="jquery.min.js">
</script>
<script type="text/javascript">//Ready is a function, that is
//technically calling a function as its argument (first class functions).
$(document).ready(function(){ //Document is an object - and .ready() is one of the methods to document. Ready() is a function, that is technically calling a function as its argument (first class functions).
  alert("Hello JQuery World!"); //This alert function is a JS function
  window.console && console.log('Hello JQuery..');//See your console
});
</script>
</body>

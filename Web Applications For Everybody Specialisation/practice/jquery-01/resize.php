<html>
<head>
</head>
<body>
<p>Here is some awesome page content</p>
<script type="text/javascript" src="jquery.min.js">//JQuery Library
</script>
<script type="text/javascript">
$(window).resize(function() {//This function will be called EVERYTIME UPON RESIZE. Here, window is an object, and resize() is one of its methods.
  window.console && console.log('.resize() called. width='+
    $(window).width()+' height='+$(window).height());
});
</script>
</body>

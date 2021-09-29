<html>
<head>
</head>
<body>
<p id="para">Where is the spinner?
  <img id="spinner" src="spinner.gif" height="25" 
      style="vertical-align: middle; display:none;">//The spinner is hidden when the page first shows up.
</p>
<a href="#" onclick="$('#spinner').toggle();
    return false;">Toggle</a>
<!--spinner means id == spinner. Toggle means to switch on and off. Toggle is a METHOD.-->
<a href="#" onclick="$('#para').css('background-color', 'red');
    return false;">Red</a>
    <!--Find the id == #para, call css METHOD.-->
<a href="#" onclick="$('#para').css('background-color', 'green');
    return false;">Green</a>
<script type="text/javascript" src="jquery.min.js">
<!-- none of this is a RRC! it is all in browswer stuff. -->
</script>
</body>

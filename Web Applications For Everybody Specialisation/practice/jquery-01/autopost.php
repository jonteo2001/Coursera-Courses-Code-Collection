<html>
<head>
</head>
<body>
<p>Change the contents of the text field and
then tab away from the field
to trigger the change event. Do not use
Enter or the form will get submitted.</p>
<form id="target">
  <input type="text" name="one" value="Hello there"
     style="vertical-align: middle;"/>
  <img id="spinner" src="spinner.gif" height="25"
      style="vertical-align: middle; display:none;"> <!-- Originally invisible -->
</form>
<hr/>
<div id="result"></div>
<hr/>
<script type="text/javascript" src="jquery.min.js">//Loads jquery
</script>
<script type="text/javascript">
  $('#target').change(function(event) {
    //Whenever the change event is triggered, call this code
    //Only can be called after a variable definition of the $window.
    $('#spinner').show(); // Find spinner and show it!
    var form = $('#target'); //
    var txt = form.find('input[name="one"]').val();
    window.console && console.log('Sending POST');
    $.post( 'autoecho.php', { 'val': txt }, //text that it is pulled out of a form field
    //send this text to autoecho.php. Request
    //So data is the response from the RRC.
      function( data ) {
          window.console && console.log(data);
          $('#result').empty().append(data); // empty the tag, then append() data acquired from
          //post response (autoecho.php)
          $('#spinner').hide(); //hide the spinner.
      }
    ).error( function() {
      $('#target').css('background-color', 'red');
      alert("Dang!");
	});
  });
</script>
</body>

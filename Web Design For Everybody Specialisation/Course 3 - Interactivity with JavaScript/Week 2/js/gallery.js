function upDate(previewPic){

  document.getElementById('image').innerHTML = previewPic.alt;
  //console.log(previewPic.src); //to debug
  document.getElementById('image').style.backgroundImage = "url('"+ previewPic.src +"')";
  //document.getElementById('image').style.backgroundImage = "url('previewPic.src')"
}

	function unDo(){

  document.getElementById('image').innerHTML = "Hover over an image below to display here";
  //to change alt text
  document.getElementById('image').style.backgroundImage = "None";
  //to change background background image
}

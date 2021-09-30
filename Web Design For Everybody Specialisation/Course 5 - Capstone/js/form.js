function validateName(){
  console.log("Running Function Validate Name!");
  var a = document.getElementById("fname");
  var a1 = document.getElementById("error_fname");
  var submit = document.getElementById("Submit");
  submit.disabled = false;

  if (a.value.match(/^[A-Za-z ]+$/)){
    a1.style.display = 'none';
    a1.innerHTML = "";
    submit.disabled = false;
    return true;
  }
  else{
    a1.style.display = "block";
    a1.innerHTML = "Enter a valid name.";
    submit.disabled = true;
    return false;
  }
}
  function validateMobile(){
    console.log("Running Function Validate Mobile!");
    var b = document.getElementById("number");
    var b1 = document.getElementById("error_number");
    var submit = document.getElementById("Submit");
    submit.disabled = false;

    if (b.value.match(/^[0-9]+$/) && b.value.length == 8 &&
      b.value.startsWith("9")==true || b.value.startsWith("8") == true){
        b1.style.display = 'none';
        b1.innerHTML = "";
        submit.disabled = false;
      }
    else{
      b1.style.display = "block";
      b1.innerHTML = "Enter a valid mobile.";
      submit.disabled = true;
      return false;
    }
  }
  function Parent(){
    console.log("Running Function Parent!");
    var c = document.getElementById("parent");
    var d = document.getElementById("child_name");
    var e = document.getElementById("parent-layer-two");
    if (c.checked == true){
      d.style.display = "inline-block"; d.required = true;
      e.style.display = "inline-block";
      return true;
    }
    else{
      d.style.display = "none"; d.required = false;
      e.style.display = "none";
      return true;
    }
  }
  function Group(){
    console.log ("Running Function Group!");
    var f = document.getElementById("group");
    var g = document.getElementById("group-layer-two");
    if(f.checked == true){
      g.style.display = "block";
      return true;
    }
    else{
      g.style.display = "none";
      return true;
    }
  }
  function Edu(){
    console.log("Running Function Edu!");
    var h = document.getElementById("edu-layer-one");
    var j = document.getElementsByClassName("JC-Math");
    var k = document.getElementsByClassName("Sec-Math");
    var l = document.getElementById("edu-layer-two");
    if (h.value == "SEC1"|| h.value == "SEC2"){
      l.style.display = "none";
      return true;
    }
    else if (h.value == "SEC3" || h.value == "SEC4"){
      l.style.display = "block";
      for (var i = 0; i < k.length; i++){
        k[i].style.display = "inline-block";
      }
      for (var i = 0; i < j.length; i++){
        j[i].style.display = "none";
      }
      return true;
    }
    else{
      l.style.display = "block";
      for (var i = 0; i < j.length; i++){
        j[i].style.display = "inline-block";
      }
      for (var i = 0; i < k.length; i++){
        k[i].style.display = "none";
      }
      return true;
    }
  }

function detailschange(){
    console.log("WindowWidth initiated!");
    // Get width of the window
    var w = document.documentElement.clientWidth;
    //console.log("w=", w);
    var a = document.getElementsByTagName("DETAILS");
    var b = document.getElementById("contact");
    //console.log("a =", a);
    if (w < 750){
      b.innerHTML = "<br>" + "Contact Me &" + "<br>"+ "Sign Up";
      //console.log("Window size is small!");
      for (var i = 0; i < a.length; i++){
        if (a[i].hasAttribute("open")){
          a[i].removeAttribute("open");
          //console.log("i = ", i, a[i]);
        }
        else{
          //console.log("i = ", i, a[i]);
          continue;
        }
      }
    }
    else{
      b.innerHTML = "  Sign Up!";
      //console.log("Window size is large!");
      for (var i = 0; i < a.length; i++){
        if (a[i].hasAttribute("open")){
          //console.log("i = ", i, a[i]);
          continue;
        }
        else{
          a[i].setAttribute("open", "open");
          //console.log("i = ", i, a[i]);
        }
      }
    }
}

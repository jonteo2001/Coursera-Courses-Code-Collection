function navBarchange(){
  const nav_small = ["navbar", "fixed-bottom", "navbar-dark", "bg-dark"];
  const nav_large = ["collapse","navbar-collapse", "justify-content-center", "navbar-dark"];
  console.log("Navbar change function activiated!");
  var w = document.documentElement.clientWidth;
  var a = document.getElementById("navbar");
  //console.log("w = ", w);
  //console.log("a = ", a);
  if (w < 750){
    //console.log("Screensize is small!");
    if (a.classList.contains('fixed-bottom')){
    //  console.log("Already a sticky footer nav bar!");
    }
    else{
      //console.log("Not a sticky footer nav bar!");
      a.className = "";
      a.classList.add(...nav_small);
      //console.log("a = ", a);
    }

  }
  else{
    //console.log("Screensize is large!");
    if (a.classList.contains('fixed-bottom')){
      //console.log("Nav bar not at the top!");
      a.className = "";
      a.classList.add(...nav_large);
    //  console.log("a = ", a);
    }
    else{
      //console.log("Navbar at the top!");
    }
  }

}

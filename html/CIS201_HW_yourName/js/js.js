window.onload = function(){
    var x = this.document.getElementsByClassName("menu-item");
    for(let i=0; i<x.length; i++){
        x[i].addEventListener("click",function(e){
            alert(e.target.innerHTML+" clicked");
        });
    }
}
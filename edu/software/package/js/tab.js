/*window.onload = init;

function init() {
    
    
    
    //document.writeln("size="+STYLE("article1","height"));
}

var STYLE = function (anElement, aCssProperty){
	var tElementId = document.getElementById(anElement);
	if(tElementId.currentStyle){
		return tElementId.currentStyle[aCssProperty]; //IE
	}
	else{
		var style =  document.defaultView.getComputedStyle(tElementId, null);
		return style.getPropertyValue(aCssProperty);
	}
}



function watchArticle() {
    
}
*/

var changeTab = function (selectedTabNumber) {
    var i;
    for (i = 1; i <= 3; i++) {
        document.getElementById("tab" + i).className = "tab";
        document.getElementById("article" + i).className = "noshow";
    }
    document.getElementById("tab" + selectedTabNumber).className="selected_tab";
    document.getElementById("article" + selectedTabNumber).className="show";
}











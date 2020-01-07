function addLoadEvent(func) {
  var oldonload = window.onload;
  if (typeof window.onload != 'function') {
    window.onload = func;
  } else {
    window.onload = function() {
      oldonload();
      func();
    }
  }
}

function getElementsByClassName(oElm, strTagName, strClassName){
	var arrElements = (strTagName == "*" && oElm.all)? oElm.all : oElm.getElementsByTagName(strTagName);
	var arrReturnElements = new Array();
	strClassName = strClassName.replace(/\-/g, "\\-");
	var oRegExp = new RegExp("(^|\\s)" + strClassName + "(\\s|$)");
	var oElement;
	for(var i=0; i<arrElements.length; i++){
		oElement = arrElements[i];		
		if(oRegExp.test(oElement.className)){
			arrReturnElements.push(oElement);
		}	
	}
	return (arrReturnElements)
}

function addClassName(oElm, strClassName){
	var strCurrentClass = oElm.className;
	if(!new RegExp(strClassName, "i").test(strCurrentClass)){
		oElm.className = strCurrentClass + ((strCurrentClass.length > 0)? " " : "") + strClassName;
	}
}


function removeClassName(oElm, strClassName){
	var oClassToRemove = new RegExp((strClassName + "\s?"), "i");
	oElm.className = oElm.className.replace(oClassToRemove, "").replace(/^\s?|\s?$/g, "");
}


function prepareBoxes() {
	var boxes = getElementsByClassName(document, "div", "lnavi_links");
	for (var i=0; i<boxes.length; i++){
		var fullstories = getElementsByClassName(document, "p", "fullstory");
		for (var k=0; k<fullstories.length; k++){
			fullstories[k].parentNode.tabIndex = k+1;
			fullstories[k].style.display = "none";
			fullstories[k].parentNode.onmouseover = function() {
				addClassName(this, "hovering");
			}
			fullstories[k].parentNode.onmouseout = function() {
				removeClassName(this, "hovering");
			}
			fullstories[k].parentNode.onclick = function() {
				var destin = this.getElementsByTagName("a");
				window.location = destin[0].href;
			}
			fullstories[k].parentNode.onkeypress = fullstories[k].parentNode.onclick;
		}
	}
}
addLoadEvent(prepareBoxes);

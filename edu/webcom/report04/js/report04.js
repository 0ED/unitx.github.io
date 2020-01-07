const MAX_MARK = 3;
const INTERVAL = 10; //ミリ秒
const DISTANCE = 36;
var markImage,timer;
var y,dy;


window.onload = init;

function init() {
    alert("スロットがそろっても何もおこりません。");
    markImage = new Array(MAX_MARK);
    markImage[0] = document.getElementById("markImage0");
    markImage[1] = document.getElementById("markImage1");
    markImage[2] = document.getElementById("markImage2");
    y = new Array(MAX_MARK);
    dy = new Array(MAX_MARK);
    document.getElementById("startButton").onclick = slot;
}


function slot() {
    document.getElementById("startButton").disabled = true;
    prepareSlot();
    startSlot();
}

function prepareSlot() {
    for(var i=0; i<MAX_MARK; i++) {
        y[i] = -205 * Math.floor(Math.random()*5);
        markImage[i].style.marginTop = y[i] + "px";
        dy[i]=DISTANCE;
    }
}

function startSlot() {
    for(var i=0; i<MAX_MARK; i++) {
        markImage[i].style.marginTop = y[i] + "px";
        if(y[i] < -205*4) y[i]=0;
        y[i]-= dy[i];
    }
    timer = setTimeout("startSlot()",INTERVAL);
}



function stopSlotMark() {
    dy[arguments[0]] = 0;
    if(dy[0]==0 && dy[1]==0 && dy[2]==0) {
        clearTimeout(timer);
        document.getElementById("startButton").disabled = false;
    }
}



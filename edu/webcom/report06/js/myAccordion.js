const INTERVAL = 20;
const DISTANCE = 5;
var open;
var headerHeight,timer; //アニメーション用

$(function()
{
  	$("#accordion-section").attr("class","openedAccordion");
  	open = false;
});

function myAccordion() 
{
	//アコーディオンが開いていたら
	if(open == true) 
	{
		open = false; //クローズする
		$("#accordion-section").css("height","0px");
	} else 
	{
		open = true; //オープンする
		$("#accordion-section").css("height","auto");
	}
}

function closeAnimation() {
	headerHeight-= DISTANCE;
	if(headerHeight < 0) {
		clearTimeout(timer);
	}
	$("#accordion-section").css("height",headerHeight+"px");
	timer = setTimeout("closeAnimation()",INTERVAL);
}

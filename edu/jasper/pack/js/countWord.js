$(function(){
	var countedWord = 0;
	for(var i=0; i < $("div#Q2 p").length; i++) {
		countedWord += $("div#Q2 p").eq(i).html().length;
	} 
	$('#resultCountedWord').text("文字数" + countedWord);
});
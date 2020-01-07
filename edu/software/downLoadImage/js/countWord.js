$(function(){
  var countedWord;
  var pWord0,pWord1,pWord2;
  var h1,h2,h4_0,h4_1,h4_2,h4_3,h4_4,h5;
  
  /*
   * なぜかfor文が使えないので、後で見直す。
   */
  
  h1 = $('body > div#contents > header h1').html().length;
  h2 = $('body > div#contents > article h2').html().length;
  h4_0 = $('body > div#contents > article h4:eq(0)').html().length;
  h4_1 = $('body > div#contents > article h4:eq(1)').html().length;
  h4_2 = $('body > div#contents > article h4:eq(2)').html().length;
  h4_3 = $('body > div#contents > article h4:eq(3)').html().length;
  h5 = $('body > div#contents > article h5').html().length;

  pWord0 = $('body > div#contents > article p:eq(0)').html().length;
  pWord1 = $('body > div#contents > article p:eq(1)').html().length;
  pWord2 = $('body > div#contents > article p:eq(2)').html().length;
  pWord3 = $('body > div#contents > article p:eq(3)').html().length;
  pWord4 = $('body > div#contents > article p:eq(4)').html().length;
  
  countedWord = pWord0 + pWord1 + pWord2 + pWord3 + pWord4 + h1 + h2 + h4_0 + h4_1 + h4_2 + h4_3 + h5;
  
  $('#resultCountedWord').text("文字数：" + countedWord);
});
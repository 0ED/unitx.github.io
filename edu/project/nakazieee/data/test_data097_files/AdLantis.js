(function(){if(typeof document.getElementsByClassName=="undefined")document.getElementsByClassName=function(b){var e,c,a,g=[],f=document.getElementsByTagName?document.getElementsByTagName("*"):document.all;e=0;for(len=f.length;e<len;e++){a=f[e].className.split(/\s+/);for(c=0;c<a.length;c++)if(a[c]==b){g.push(f[e]);break}}return g};var r={create:function(){return function(){this.extend=function(b){var e=function(){this.initialize.apply(this,arguments)};for(var c in this)e.prototype[c]=this[c];for(c in b)e.prototype[c]=
b[c];return e};this.initialize.apply(this,arguments)}},register:function(b,e){b=b.split(".");for(var c=window,a=0,g=b.length;a<g;a++){if(typeof c[b[a]]=="undefined")c[b[a]]={};c=c[b[a]]}for(var f in e)c[f]=e[f]}},s=r.create();s.prototype={initialize:function(b){this.scanner(b)},scanner:function(b){for(var e=jp.atlantis.mashiron.advertise,c=document.getElementsByClassName("adlantiss_frame"),a=[],g=0,f=0;f<c.length;f++){for(var k,j="iframe",l=false,o=false,n=false,i=false,h=c[f].className.split(" "),
d=0;d<h.length;d++)switch(true){case h[d]=="loaded":o=true;break;case h[d]=="autosize":l=true;break;case h[d]=="nocss":i=true;break;case /^zid_.*$/.test(h[d]):k=/^zid_(.*)$/.exec(h[d])[1];break;case /^checksum_.*$/.test(h[d]):n=/^checksum_(.*)$/.exec(h[d])[1];break;case /^container_.*$/.test(h[d]):j=/^container_(.*)$/.exec(h[d])[1];break;case /^color_.*$/.test(h[d]):color=/^color_(.*)$/.exec(h[d])[1].split("-");break;default:}if(!(o||!k)){a.push(k);j={zid:k,checksum:n,id:g,containerTag:j,autosize:l,
nocss:i,classes:h};if(/iPhone OS.*Mobile\/5[A-H]/.test(navigator.userAgent))j.containerTag="div";if(typeof color!="undefined")j.color=color.length>1?{title:color[0],text:color[1],background:color[2],border:color[3],url:color[4]}:color[0];if(typeof AdLantisOptions!="undefined")for(d in AdLantisOptions)j[d]=typeof AdLantisOptions[d]=="function"?window.AdLantisOptions[d]():window.AdLantisOptions[d];l=document.getElementsByTagName("meta");o=0;for(n=l.length;o<n;o++){i=l[o];if(i.getAttribute("name")&&
i.getAttribute("name")=="adlantis-ad-params")j.adlantisAdParam=i.getAttribute("content")}if(b)for(d in b.additionalParams){if(typeof b.additionalParams[d]=="string")j[d]=b.additionalParams[d];if(typeof b.additionalParams[d]=="object")j[d]=b.additionalParams[d];if(typeof b.additionalParams[d]=="function")j.additionalParam=b.additionalParams[d]()}d=new e(c[f],j);jp.atlantis.mashiron.ads["ads"+d.id]=d;g++;c[f].className+=" loaded"}}this.zidlist=a}};var t=r.create();t.prototype={domain:"http://ad.adlantis.jp/",
rehearsal:false,requiredFlashVersion:"6",adlantisInfoURL:"http://www.adlantis.jp/?ref=ad_box",pathTextAdCSS:"http://static.adlantis.jp/stylesheets/multiple_text_ads.css",jsonendpoint:"ad/load_script",containerTag:"iframe",options:{forceHtmlAdInFrame:true,forceNetworkAdInFrame:true},additionalParam:false,autosize:false,nocss:false,checksum:false,adlantisAdParam:false,initialize:function(){this.arguments=arguments;var b=this.arguments[0],e=this.arguments[1];for(var c in e)this[c]=e[c];if(this.checksum&&
this.rehearsal){this.domain=this.rehearsal.domain;this.jsonendpoint=this.rehearsal.jsonendpoint}b.id=["adbox_",this.id].join("");this.containerElement=b;this.openJSONRequest(this.getURL());return this},openJSONRequest:function(b){putTag=function(){var c=document.createElement("script");c.src=b;c.type="text/javascript";c.charset="UTF-8";document.body.appendChild(c)};if(window.opera){var e=document.createElement("img");e.onerror=putTag;e.width=0;e.height=0;e.src=b;document.body.appendChild(e)}else putTag.apply()},
getURL:function(){var b=new Array(["zid",encodeURIComponent(this.zid)].join("="));b.push(["ref",document.referrer].join("="));b.push(["callbackid","ads"+this.id].join("="));this.checksum&&b.push(["checksum",this.checksum].join("="));this.adlantisAdParam&&b.push(["adlantisAdParam",this.adlantisAdParam].join("="));if(this.additionalParam&&typeof this.additionalParam=="object")try{b.push(this.additionalParam.join("="))}catch(e){}return[this.domain,this.jsonendpoint,"?",b.join("&")].join("")},setVars:function(b){for(var e=
0,c=this.containerElement.childNodes.length;e<c;e++)this.containerElement.removeChild(this.containerElement.childNodes[e]);if(typeof b.type!="undefined"){for(e in b)this[e]=b[e];if(this.type=="html"&&this.options.forceHtmlAdInFrame||this.type=="externalNetwork"&&this.options.forceNetworkAdInFrame)this.containerTag="iframe";if(this.width=="auto"||this.height=="auto"){this.containerTag="div";this.autosize=true}this.subContainer=this.getContainer();this.insertElement(this.subContainer,this.containerElement);
this.updateAdElement()}},getContainer:function(){var b=document.createElement(this.containerTag);if(this.containerTag=="iframe"){b.setAttribute("frameBorder","0");b.setAttribute("marginHeight","0");b.setAttribute("marginWidth","0");b.setAttribute("vspace","0");b.setAttribute("hspace","0");b.setAttribute("allowTransparency","true");b.setAttribute("scrolling","no")}if(this.width&&this.height&&!this.autosize){b.style.width=this.width+"px";b.style.height=this.height+"px"}return b},updateAdElement:function(){var b=
function(i,h){var d=containerOrigin.createElement("a");d.href=i;d.target=h;return d},e=function(i,h,d){if(!this.nocss){for(var m=0,q=h.length;m<q;m++){var p=h[m];i.setAttribute(p[0],p[1]);if(p[0]=="class")i.className=p[1]}m=0;for(q=d.length;m<q;m++){h=d[m];i.style[h[0]]=h[1]}}},c=function(i,h,d){i=containerOrigin.createElement(i);e(i,h,d);return i};if(this.containerTag=="iframe"){this.subContainer.setAttribute("frameBorder","0");var a=this.subContainer.contentDocument?this.subContainer.contentDocument:
this.subContainer.contentWindow.document;if(this.type!="externalNetwork"&&this.type!="html"){a.writeln("<head></head><body></body>");a.close();containerOrigin=a;targetContainer=a.body;targetContainer.style.margin=0;targetContainer.style.padding=0;targetContainer.style.backgroundColor="transparent"}}else{containerOrigin=document;targetContainer=this.subContainer}switch(this.type){case "externalNetwork":if(this.containerTag!="iframe")return false;this.subContainer.src=this.iframeLocation;break;case "text":var g=
containerOrigin.createElement("div");g.style.textAlign=this.align;g.innerHTML=this.showPR?"[PR]"+decodeURIComponent(this.string):decodeURIComponent(this.string);a=b(this.href,this.target);a.style.color=this.color;a.style.fontSize="13px";a.appendChild(g);targetContainer.appendChild(a);break;case "multiple":this.useList=false;var f=0;for(a=this.classes.length;f<a;f++)if(this.classes[f]=="use_list")this.useList=true;g=this.useList?containerOrigin.createElement("ul"):containerOrigin.createElement("div");
f=0;for(a=this.ads.length;f<a;f++){ad=this.ads[f];var k=this.useList?containerOrigin.createElement("li"):containerOrigin.createElement("div");k.setAttribute("class","eachAd");var j;j=ad.showPR?containerOrigin.createTextNode("[PR]"+decodeURIComponent(ad.string)):containerOrigin.createTextNode(decodeURIComponent(ad.string));var l=b(ad.href,ad.target);l.appendChild(j);k.appendChild(l);g.appendChild(k)}targetContainer.appendChild(g);break;case "img":a=b(this.href,this.target);g=c("img",[["src",this.src],
["alt",decodeURIComponent(this.alt)],["border","0"]],[["width",this.width+"px"],["height",this.height+"px"]]);a.appendChild(g);targetContainer.appendChild(a);break;case "html":if(this.containerTag=="iframe"||this.options.forceHtmlAdInFrame)this.subContainer.src=this.iframeLocation;else targetContainer.innerHTML=decodeURIComponent(this.innerHTML);break;case "swf":try{g=(f=deconcept.SWFObjectUtil.getPlayerVersion())&&f.major>=this.requiredFlashVersion?true:false}catch(o){g=false}if(typeof this.alter!=
"undefined"&&!g)switch(this.alter.type){case "img":g=c("img",[["src",this.alter.src],["alt",this.alter.alt],["border","0"]],[]);a=b(this.alter.href,this.alter.target);a.appendChild(g);targetContainer.appendChild(a);break;case "text":a=b(this.alter.href,this.alter.target);g=c("table",[["border",0],["cellPadding",0],["cellSpacing","0"]],[["width",this.width+"px"],["height",this.height+"px"]]);f=containerOrigin.createElement("tbody");k=containerOrigin.createElement("tr");j=c("td",[["align","center"],
["valign","middle"]],[]);j.appendChild(containerOrigin.createTextNode(decodeURIComponent(this.alter.string)));k.appendChild(j);f.appendChild(k);g.appendChild(f);a.appendChild(g);targetContainer.appendChild(a);break}else{this.flashWmode=false;f=0;for(a=this.classes.length;f<a;f++){if(this.classes[f]=="wmode_opaque")this.flashWmode="opaque";if(this.classes[f]=="wmode_transparent")this.flashWmode="transparent"}a=new SWFObject(this.src,"swf"+this.id+"_"+this.zid,this.width,this.height,this.requiredFlashVersion,
null);a.addVariable("clickTAG",this.href);a.addVariable("targetTAG",this.target);a.addParam("allowScriptAccess","always");this.flashWmode&&a.addParam("wmode",this.flashWmode);if(this.containerTag=="iframe")targetContainer.innerHTML=a.getSWFHTML();else{g=containerOrigin.createElement("div");targetContainer.appendChild(g);a.write(g)}}break;case "js":this.source&&eval(this.source);if(this.src){a=containerOrigin.createElement("script");a.type="text/javascript";a.src=this.src;targetContainer.appendChild(a)}break;
case "multiple_text":g=c("div",[],[["position","relative"]]);f=function(i,h){var d=c("td",[["class","ad_td_base ad"+i.width+"x"+i.height+"_td"],["valign","middle"]],[["verticalAlign","middle"]]);if(typeof h.preview_title!="undefined"){var m=b(h.href,i.target);e(m,[["class","ad_anchor"]],[]);var q=c("div",[["class","preview_title"]],[["color",i.color.title],["textDecoration","underline"]]);q.innerHTML=decodeURIComponent(h.preview_title);var p=c("div",[["class","preview_text"]],[["color",i.color.text]]);
p.innerHTML=decodeURIComponent(h.preview_text);i=c("div",[["class","preview_url"]],[["color",i.color.url]]);i.innerHTML=decodeURIComponent(h.preview_url);m.appendChild(q);m.appendChild(p);m.appendChild(i);d.appendChild(m)}return d};if(this.containerTag=="iframe"||!jp.atlantis.mashiron.isStyleSheetLoaded){a=containerOrigin.createElement("link");a.rel="stylesheet";a.type="text/css";a.href=this.pathTextAdCSS;containerOrigin.getElementsByTagName("head")[0].appendChild(a);if(this.containerTag!="iframe")jp.atlantis.mashiron.isStyleSheetLoaded=
true}e(g,[["class","ad_content"]],[["backgroundColor",this.color.background]]);switch(this.boxType){case "rectangle":case "skyscraper":k=c("div",[["class","ad_title"]],[["width",this.width+"px"],["backgroundColor",this.color.border],["lineHeight","14px"]]);a=c("a",[["target","_blank"],["href",this.adlantisInfoURL]],[["color","#000"],["margin","0"],["padding","0"],["textDecoration","none"]]);a.innerHTML="Ads by <b>Adlantis</b>";k.appendChild(a);g.appendChild(k);break}k=c("table",[["class","ad_base ad"+
this.width+"x"+this.height],["cellPadding","0"],["cellSpacing","0"]],[]);j=containerOrigin.createElement("tbody");switch(this.boxType){case "rectangle":case "skyscraper":l=0;for(a=this.ads.length;l<a;l++){var n=c("tr",[],[]);n.appendChild(f(this,this.ads[l]));j.appendChild(n)}break;case "banner":n=c("tr",[],[]);l=0;for(a=this.ads.length;l<a;l++)n.appendChild(f(this,this.ads[l]));j.appendChild(n);break}k.appendChild(j);g.appendChild(k);switch(this.boxType){case "banner":f=c("span",[],[["position",
"absolute"],["top",this.height-15+"px"],["left",this.width-84+"px"],["padding","0"],["fontSize","9px"],["lineHeight","14px"]]);a=c("a",[["target","_blank"],["href",this.adlantisInfoURL]],[["color","#000"],["margin","0px"],["padding","0px"],["textDecoration","none"]]);a.innerHTML="Ads by <b>Adlantis</b>";f.appendChild(a);g.appendChild(f);break}targetContainer.appendChild(g);break}},insertElement:function(b,e){if(arguments.length==1){document.write('<span id="'+this.id+'"></span>');var c=document.getElementById(this.id),
a=c.parentNode;a.insertBefore(b,c);a.removeChild(c)}else e.appendChild(b)}};r.register("jp.atlantis.mashiron",{advertise:t,loader:s,ads:{}})})();
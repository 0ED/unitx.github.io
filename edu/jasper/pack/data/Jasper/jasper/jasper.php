<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Jasper</title>
		
	<!-- 検索エンジンに食わせる -->
    <meta name = "keywords" content="Jasper｜Darwin" />
    <meta name = "description" content="画像検索サイトJasper。画像中の人数から、画像を検索できる。" />
        
    <!-- CSS -->
    <link href="pack/css/import.css" rel="stylesheet" type="text/css" /><!-- メインCSS -->
    <link href="pack/css/custom-theme/jquery-ui-1.9.2.custom.css" rel="stylesheet">
	<link rel="stylesheet" type="text/css" href="pack/css/jquery.fancybox-thumbs.css" />
	<link rel="stylesheet" type="text/css" href="pack/css/jquery.fancybox.css" media="screen" />
    <style type="text/css"><!--
		.fancybox-custom .fancybox-skin {
			box-shadow: 0 0 50px #222;
		}
		body {
			//max-width: 700px;
			margin: 0 auto;
		}
	--></style>
    
    <!-- JS -->
    <script type="text/javascript" src="pack/jquery/jquery-1.9.1.js"></script>
    <script type="text/javascript" src="pack/jquery/jquery-ui.js"></script>
	<script type="text/javascript" src="pack/jquery/jquery.fancybox.js"></script>
	<script type="text/javascript" src="pack/jquery/jquery.fancybox-thumbs.js"></script>
	<script type="text/javascript" src="pack/jquery/jquery.mousewheel-3.0.6.pack.js"></script>
	<script type="text/javascript" src="pack/js/system.js"></script><!-- MyJavaScript -->
	
	<script type="text/javascript"><!--
		$(document).ready(function() {
			$('.fancybox').fancybox();
			$('.fancybox-thumbs').fancybox({
				prevEffect : 'none',
				nextEffect : 'none',

				closeBtn  : false,
				arrows    : false,
				nextClick : true,

				helpers : {
					thumbs : {
						width  : 50,
						height : 50
					}
				}
			});
		});
	--></script>

	<script><!--
		$(function() {
			$( "#slider-range" ).slider({
				range: true,
				min: 0,
				max: 10,
				values: [ 0, 10 ],
				slide: function( event, ui ) {
					$( "#amount" ).val( ui.values[ 0 ] + "人"+ " - " + ui.values[ 1 ]+"人" );
					document.getElementById('number1').value=ui.values[ 0 ];//ここでフォームに代入
					document.getElementById('number2').value=ui.values[ 1 ];//ここでフォームに代入
				}
			});
			//初期スライダー位置設定　以下
			$( "#amount" ).val($( "#slider-range" ).slider( "values", 0 ) + "人" +" - " + $( "#slider-range" ).slider( "values", 1 ) + "人");
			//ここでフォームに代入（スライダ初期状態）
			document.getElementById('number1').value=$( "#slider-range" ).slider( "values", 0);
			document.getElementById('number2').value=$( "#slider-range" ).slider( "values", 1);
	});
	--></script>
	
	<!--[if lt IE 9]>
    <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]--> 
</head>

<body class="Jasper" id="jasper">
	<form action="<?php echo $_SERVER['PHP_SELF'] ?>" method="post">
		<div id="seacher-space">
			<a href="../jasper" id="jasper_logo">
				<img src="pack/images/jasper_mini.png" alt="Jasper's logo" />
			</a>
			<div id="searcher">
				<input type="text" id="search-textarea" name="keyword"/>
				<button type="submit" id="search-start">検索</button>
			<!-- /#seacher --></div>
			<button type="button" id="setButton" alt="システム">
				<!--<img src="pack/images/system.png" />-->
			</button>
		<!-- /#seacher-space --></div>
		
		<div id="systemPanel" style="display: none;">
			<div id='slider-range'></div><!-- Show Slider ! -->
			<input type='text' id='amount' style='border: 0; color: #f6931f; font-weight: bold;' />
			<input type='hidden' name='number1' id='number1' />
			<input type='hidden' name='number2' id='number2' />
		</div>
	</form>


<!-- ここから、検索結果を表示する領域 -->
<?php
	// tfファイルの読み込み　１行ずつ　最後まで
	$tf_data = array( array());
	$tffile = "tfimg.all";
	$f1 = fopen($tffile, "r");
	while (! feof ($f1)) {
		$line = fgets($f1);
		$tf_line = preg_split( "/\t/" , $line );
		@$tf_line[2] = preg_replace("/\r|\n/","",$tf_line[2]);
		@$tf_data[$tf_line[0]][$tf_line[2]] = $tf_line[1]; 
	}
	fclose($f1);
	// tfファイルの読み込み　ここまで
	
	
	// fcファイルの読み込み　１行ずつ　最後まで
	$fc_data = array();
	$fcfile = "fcimg.all";
	$f2 = fopen($fcfile, "r");
	while (! feof ($f2)) {
		$line = fgets($f2);
		$fc_line = preg_split( "/\t/" , $line );
		@$fc_line[1] = preg_replace("/\r|\n/","",$fc_line[1]);
		$fc_data[$fc_line[1]] = $fc_line[0]; 
	}
	fclose($f2);
	// fcファイルの読み込み　ここまで


    // 以下、検索処理
    $result_num = 0;

    if (isset($_POST["keyword"]) && isset($_POST["number1"]) && isset($_POST["number2"])) {
        if($_POST["keyword"]<>null){
            //前後の空白文字を取り除く処理
            $_POST["keyword"]=preg_replace('/^[\s　]*(.*?)[\s　]*$/u', '\1', $_POST["keyword"]);
            //全角スペースから半角スペースへ変換する
            $_POST["keyword"]=preg_replace('/　/', ' ', $_POST["keyword"]);
            $words=preg_split("/ /", $_POST["keyword"], -1, PREG_SPLIT_NO_EMPTY);
            $numberMin=$_POST["number1"];
            $numberMax=$_POST["number2"];
            
            //検索キーワードの表示
            echo "キーワード";
            foreach($words as $word){
                echo "『".$word."』";
            }
            if($numberMax==10){
                $numberMax=null;
            }
            if($numberMin==0){
                $numberMin=null;
            }
            if($numberMax<>null && $numberMin<>null && $numberMax<$numberMin){
                $number=$numberMax;
                $numberMax=$numberMin;
                $numberMin=$number;
            }
            
            //検索人数の表示
            if($numberMax<>null && $numberMin<>null){
                echo "　人数『".$numberMin."人から".$numberMax."人』での検索結果<br>\n";
            }
            else if($numberMax==$numberMin && $numberMax<>null){
                echo "　人数『".$numberMax."人』での検索結果<br>\n";
            }
            else if($numberMax<>null && $numberMin==null){
                echo "　人数『".$numberMax."人以下』での検索結果<br>\n";
            }
            else if($numberMin<>null && $numberMax==null){
                echo "　人数『".$numberMin."人以上』での検索結果<br>\n";
            }
            else{
                echo "　人数指定なしでの検索結果<br>\n";
            }
            echo "<hr>\n";
            
            //検索リストを作成して初期化する。
            $List=array();
            foreach($words as $word){
                foreach((array)$tf_data[$word] as $keyword => $data){
                    $flag=array();
                    if(array_key_exists($keyword, $List)!=true){
                        foreach($words as $word){
                            $flag[$word]="F";
                        }
                        $List[$keyword]=$flag;
                    }
                }
            }
            
            
            //検索ワードを持つデータを割り出す。
            foreach($words as $word){
                foreach((array)$tf_data[$word] as $keyword => $data){
                    $flag=$List[$keyword];
                    if($numberMax<>null && $numberMin<>null && $numberMax >=$fc_data[$keyword] && $numberMin <= $fc_data[$keyword]){
                        //人数指定が二つとも入力されているとき。
                        $flag2=&$flag[$word];
                        $flag2="T";
                    }
                    else if($numberMax<>null && $numberMin==null && $numberMax >=$fc_data[$keyword] && $fc_data[$keyword] !=null){
                        //人数指定が一つ入力されているとき（〜以下）
                        $flag2=&$flag[$word];
                        $flag2="T";
                    }
                    else if($numberMax==null && $numberMin<>null && $numberMin <= $fc_data[$keyword] && $fc_data[$keyword] !=null){
                        //人数指定が一つ入力されているとき（〜以上）
                        $flag2=&$flag[$word];
                        $flag2="T";
                    }
                    else if($numberMax==null && $numberMin==null){//人数の範囲指定がないとき
                        $flag2=&$flag[$word];
                        $flag2="T";
                    }
                    $List2=&$List[$keyword];
                    $List2=$flag;
                }
            }
            
            //画像を表示する
            foreach($List as $key => $val){	
                if(in_array("F", $val)!=true){//検索wordがすべて含まれている場合。
                    echo "<a class=\"fancybox-thumbs\" data-fancybox-group=\"thumb\" href=\"$key\"><img src=\"$key\" width=(200*($width/$height)) height=200 /></a>";
                    $result_num++;
                }
            }
            	
			$result_num2=0;
	    	$countFlag=true;
            //AND検索で40件に満たなかった場合の処理
            if($result_num<40){
	      			$before=count($words);
	      			while($countFlag==true){	    
			  			foreach($List as $key => $val){
		  					$array=array();
		  					$array=array_count_values($val);
		  					$count=$array["T"];
		  					if(in_array("F", $val)==true && in_array("T", $val)==true && $count==$before){//検索wordがすべて含まれている場合。
		  						echo "<a class=\"fancybox-thumbs\" data-fancybox-group=\"thumb\" href=\"$key\"><img src=\"$key\" width=(200*($width/$height)) height=200 /></a>";
		  						$result_num2++;
							} 
        				}
						$before--;
						if($before==0){
		  					$countFlag=false;
						}
	      			}
            }
            $result=$result_num+$result_num2;
			echo "<br>";
            echo "検索結果の総ヒット件数：".$result."件<br>\n";
        }
        else if(@$_POST["keyword"]==null){
            echo'検索キーワードを入力してください。<br>';
        }
        else{
            echo '人数を正しく入力してください。<br>';
        }
    }
    ?>
</body>
</html>

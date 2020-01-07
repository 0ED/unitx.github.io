window.onload = function() 
{
	var visible = true;

	document.getElementById("setButton").onclick = function() 
	{
		if(visible)
		{
			document.getElementById("systemPanel").style.display = "block";
			visible = false;
		} 
		else
		{
			document.getElementById("systemPanel").style.display = "none";
			visible = true;
		}
	}
}

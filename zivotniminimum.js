<!DOCTYPE>
<html>
<head>
<script>
function minimum() 
{

	document.getElementById("dospely");
	if (dospely.value == 1 && dite.value == 0 && teenage.value == 0 && nezaopatreny.value == 0) var dospelaci = 3860;	
	else if (dospely.value == 1 && dite.value > 0 && teenage.value > 0 && nezaopatreny.value > 0) var dospelaci = 3550;
	else if (dospely.value == 1 && dite.value == 1) var dospelaci = 3550;
	else if (dospely.value != 1) {
	var cenad = dospely.value * 3200;
	var dospelaci = cenad + 350; 
		}
	document.getElementById("dite");
	var deti = dite.value * 1970;
	var mezisoucet1 = deti + dospelaci;
	
	document.getElementById("teenage");
	var teen = teenage.value * 2420;
	var mezisoucet2 = mezisoucet1 + teen;

	document.getElementById("nezaopatreny");
	var nezaop = nezaopatreny.value * 2770;
	var mezisoucet3 = mezisoucet2 + nezaop;		

	alert(mezisoucet3);
}


</script>
</head>
<body>
<h1>Výpočet životního minima</h1>

<p>Vyberte počet dospělých</p>
<select id="dospely">
    <option value="1">1</option>
    <option value="2">2</option> 
    <option value="3">3</option>
    <option value="4">4</option>			
</select>
<p>Vyberte počet dětí do 6 let</p>
<select id="dite">
    <option value="0">0</option>
    <option value="1">1</option>
    <option value="2">2</option>
    <option value="3">3</option>	
</select>
<p>Vyberte počet dětí 6-15 let</p>
<select id="teenage">
    <option value="0">0</option>	 
    <option value="1">1</option>
    <option value="2">2</option>
    <option value="3">3</option>
</select>
<p>Vyberte počet 15-26 let</p>
<select id="nezaopatreny">
    <option value="0">0</option>	
    <option value="1">1</option>
    <option value="2">2</option>
    <option value="3">3</option>
</select>

<br><input type="button" value="Počítej" onclick="minimum();">

</body>


</html>

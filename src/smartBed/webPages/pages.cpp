/*
	export string isntructions https://en.cppreference.com/w/cpp/language/string_literal
*/

String indexPage = R"###(
<!DOCTYPE html>
<html>
<head>
<style>
*{

	font: 'Fira Sans', sans-serif;
}
body {
	padding-left: 20px;
}
.timeInput {
  font-family: 'PT Sans', sans-serif;
  font-size: 1.2rem;
  display: block;
  padding: 0.5rem 1rem;
}
.ckeckInput{
	width: 100px;
	height: 20px;
}
.ckeckInput:hover{
	color: #FFFF
}
.sendButton {
	margin-top: 10px;
	width: 100px;
	height: 20px;
	background-color: red
}
h3{
	color: #ccc;
}
</style>
</head>
<body>

<h1>SmartBed</h1>
<p>Your alarm is set to [placeholder]. Currently [placeholder on/off]</p>
<h3>Configure your alarm</h3>
<form method="get">
	<p>Set Status</p>
	<input class="checkInput" type="radio" name="alarmStatus" value="on">On
	<input class="checkInput" type="radio" name="alarmStatus"value="on">Off
	<h3>Time setup</h3>
	<input class="timeInput" type="time" name="alarmTime">
	<input class="sendButton" type="submit" value="Send">
</form>

</body>
</html>
)###";

String connectPage = R"###(
<!DOCTYPE html>
<html>
<head>
<style>
*{

	font: 'Fira Sans', sans-serif;
}
body {
	padding-left: 20px;
}
.timeInput {
  font-family: 'PT Sans', sans-serif;
  font-size: 1.2rem;
  display: block;
  padding: 0.5rem 1rem;
}
.ckeckInput{
	width: 100px;
	height: 20px;
}
.ckeckInput:hover{
	color: #FFFF
}
.sendButton {
	margin-top: 10px;
	width: 100px;
	height: 20px;
	background-color: red
}
h3{
	color: #ccc;
}
</style>
</head>
<body>

<h1>SmartBed</h1>
<p>Login to a internet wifi network </p>
<h3>Enter yout login credentials</h3>
<form method="get">
	<p>Connection Name</p>
	<input class="checkInput" type="text" name="ssid" id="ssid" >
	<p>Password</p>
	<input class="checkInput" type="text" name="passWord" id="passWord" ><br>
	<input class="sendButton" type="submit" value="Login" onclick="Clicked()">
</form>

</body>
</html>
<script>
	function Clicked()
	{
  		// Display a message.
		var wifissid = document.getElementById("ssid").value;
		alert("You typed " + wifissid);
	}
</script>
)###";  
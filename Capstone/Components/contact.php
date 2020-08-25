<?php
	header("Access-Control-Allow-Origin: *");
	header("Access-Control-Allow-Headers: *");
	header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
	$rest_json = file_get_contents("php://input");
//	$_POST = json_decode($rest_json, true);

	$json_data = json_decode($rest_json);
	var_dump($json_data);
	
	//echo $json_data->i;


	@$db = new mysqli('107.180.55.11', 'jcohn', 'passwd', 'mlnrp');
	
	//$method = $_SERVER['REQUEST_METHOD'];
	//$request = explode('/', trim($_SERVER['PATH_INFO'],'/'));

	/*
	$sub = $bd->query('SELECT * FROM contact'); // submit query
	$res = $sub->fetchAll(PDO::FETCH_OBJ); // results 
	$resList = []; // results list
	*/

	
	if (!$db) {
		die("Connection failed: " . mysqli_connect_error());
	}
	
	http_response_code(200);

/*
	$fname = "Tom";
	$lname = 'Smith';	
	$calltime = 'em';
	$phone = '5555555555';
	$email = 'email';
	$subject = 'interest';
	$message = 'message';
*/

	$fname = $_POST["firstName"];
	$lname = $_POST["lastName"];	
	$calltime = $_POST["callBackTime"];
	$phone = $_POST["phoneNumber"];
	$email = $_POST["email"];
	$subject = $_POST["interest"];
	$message = $_POST["message"];

	/*
	// loop through results
	foreach($res as $row) {
		$resList = $row
	}
	*/



	if (!$fname || !$lname || !$email || !$phone || !$calltime || !$subject || !$message) {
		echo "You have not entered all required details.  Please go back and try again.";
		exit;
	}

	$query = "INSERT into contact (fname, lname, email, phone, calltime, subject, message) values (?, ?, ?, ?, ?, ?, ?)";
	$stmt = $db->prepare($query);
	$stmt->bind_param("sssssss", $fname, $lname, $email, $phone, $calltime, $subject, $message);
	$stmt->execute();
	echo $stmt->affected_rows." contact updated in database";
	
	$db->close();
?>
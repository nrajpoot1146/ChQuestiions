<?php

/**
 * Run this file using apache server like, xampp, wampp etc
 * your output will appear on web browser
 */

$data = getWeatherData();


function getWeatherData(){

    /**
     * get your own api key, by registering on https://openweathermap.org/
     * get your city code from city json file, to download city json file follow this link, http://bulk.openweathermap.org/sample/city.list.json.gz
     */

    $apiKey = "88b925a36c3123eccbf276b190867151";
    $cityId = "6425403";

    $url = "http://api.openweathermap.org/data/2.5/weather?id=" . $cityId . "&lang=en&units=metric&APPID=" . $apiKey;

    $curl = curl_init(); //curl library to generate request on weather api

    curl_setopt($curl, CURLOPT_HEADER, 0);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($curl, CURLOPT_URL, $url);
    curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_setopt($curl, CURLOPT_VERBOSE, 0);
    curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);

    $res = curl_exec($curl);

    curl_close($curl);

    $data = json_decode($res);

    return $data;
}

?>

<!doctype html>
<html>
<head>
<title>Forecast Weather using OpenWeatherMap with PHP</title>
</head>
<body>
    <div class="report-container">
        <h2><?php echo $data->name; ?> Weather Status</h2>
        <div class="weather-forecast">
            <img
                src="http://openweathermap.org/img/w/<?php echo $data->weather[0]->icon; ?>.png"  /> <?php echo $data->main->temp_max; ?>°C<span ><?php echo $data->main->temp_min; ?>°C</span>
        </div>
        <div class="time">
            <div>Humidity: <?php echo $data->main->humidity; ?> %</div>
            <div>Wind: <?php echo $data->wind->speed; ?> km/h</div>
        </div>
    </div>
</body>
</html>
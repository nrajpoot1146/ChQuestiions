<?php

   if(isset($_POST['checkbox'])){
       $checkbox = 'Yes';
    }else{
        $checkbox = 'False';
    }

    $investment = filter_input(INPUT_POST, 'investment',
    FILTER_VALIDATE_FLOAT);
    $interest_rate = filter_input(INPUT_POST, 'interest_rate',
    FILTER_VALIDATE_FLOAT);
    $years = filter_input(INPUT_POST, 'years',
    FILTER_VALIDATE_INT);

    if ($error_message != '') {
        include('index.php');
        exit();
    }

    $future_value = calFutureValue($investment, $checkbox, $interest_rate, $years);

    $investment_f = currency_formating($future_value);
    $yearly_rate_f = percentformatting($interest_rate);
    $future_value_f = currency_formating($future_value);

    function calFutureValue($investment, $checkbox, $interest_rate, $years){

        if($checkbox =='Yes'){
            $future_value = $investment;
            $interest_rate_monthly=$interest_rate/12;
            for ($i = 1; $i <= $years*12; $i++) {
                $future_value += $future_value * $interest_rate_monthly *.01;
            }
        } else{
            $future_value = $investment;
            for ($i = 1; $i <= $years; $i++) {
                $future_value += $future_value * $interest_rate *.01;
            }
        }

        return $future_value;
    }

    function currency_formating($currency){
        return '$'.number_format($currency, 2);
    }

    function percentformatting($value){
        return $value.'%';
    }
                    
?>
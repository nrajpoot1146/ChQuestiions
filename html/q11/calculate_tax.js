"use strict";
var $ = function (id) {
    return document.getElementById(id);
};



window.onload = function () {
    $("calculate").onclick = processEntry;
};

/**
 * calculate owed tax
 * read income value from input element with id income
 * add tax value into input element with id tax
 */
function processEntry(){
    let income = $("income").value;

    let tax = 0;

    if (income > 0 && income <= 8589){
        tax = 0 + income * 0.10;
    }else if(income > 8589 && income <= 38449){
        tax = 858.90 + (income - 8589) * 0.15;
    }else if (income > 38449 && income <= 94250){
        tax = 5337.90 + (income - 38449) * 0.25;
    }else if (income > 94250 && income <= 192150){
        tax = 19288 + (income - 94220) * 0.28;
    }else if (income > 192150 && income <= 421440){
        tax = 46700.15 + (income - 192150) * 0.33;
    }else if (income > 421440 && income <= 425323){
        tax = 123647 + (income - 421440) * 0.35;
    }else{
        tax = 127147 + (income - 425323) * 0.38;
    }

    $("tax").value = tax.toFixed(2);
}

/**
 * function to detect alphanumeric symbol in given string
 * return number of alpha numeric symbol
 * @param {*} str 
 */
var f1 = function(str){
    let alphaNumCounter = "";
    let res = "";
    for( x of str){
        if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x<= '9'){
            alphaNumCounter++;
            res += x;
        }
    }
    return alphaNumCounter +" (" +res+")";
}

/**
 * This funtion adds the = value of asterisks in the 1st argument to both ends of the
 * input string 
 * @param {*} str 
 * @param {*} num 
 */
var f2 = function(str, num){
    for (let i=0; i<num; i++){
        str = "*" + str + "*";
    }
    return str;
}

console.log("f1(\"+mgu+1} =+++2+\") = "+ f1("+mgu+1} =+++2+")); // output of first function
console.log("f2(\"kit\", 3) = "+ f2("kit", 3)); // output of second function
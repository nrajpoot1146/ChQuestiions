function domLoaded() {

    // instance for convert bbutton
    let cButton = document.getElementById("convertButton");

    // instance for celsius input
    let cInput = document.getElementById("cInput");

    // instance for Fahrenheit input
    let fInput = document.getElementById("fInput");

    // instannce for error message div
    let eMsg = document.getElementById("errorMessage");

    // attach key press listener to celsius input
    // when user start to type Fahrenheit input field set to empty 
    cInput.addEventListener("keypress", function (){
        fInput.value = "";
    });

    // attach key press listener to fahrenheit input
    // when user start to type celsius input field set to empty 
    fInput.addEventListener("keypress", function (){
        cInput.value = "";
    });

    // attach click listener to convert button
    cButton.addEventListener("click", function () {
        let cVal = cInput.value; // read value from celsius input field
        let fVal = fInput.value; // read value from fahrenheit input field
        let error = ""; // variable to store error message

        if (cVal != ""){
            if (!isNaN(cVal)){
                let f = convertCtoF(cVal);
                fInput.value = f;
                setimage(f);
            }else{
                error = cVal + " is not a number.";
            }

        }else if (fVal != ""){
            if (!isNaN(fVal)){
                let c = convertFtoC(fVal);
                cInput.value = c;
                setimage(fVal);
            }else{
                error = fVal + " is not a number.";
            }
        }

        eMsg.innerHTML = error;
    });
}

// convert degree celsius to degree fahrenheit
function convertCtoF(degreesCelsius) {
    let f = degreesCelsius * 9 / 5 + 32;
    return f;
}

// convert degree fahrenheit to degree celsius
function convertFtoC(degreesFahrenheit) {
    let c = (degreesFahrenheit - 32) * 5 / 9;
    return c;
}

// update image according to degree fahrenheit
// deg <  32                : src = cold.gif
// deg >= 32 and deg <50    : src = cool.gif
// deg >  50                : sec = warm.gif
function setimage(deg){
    let wImage = document.getElementById("weatherImage");
    if (deg < 32){
        wImage.setAttribute("src", "cold.gif");
        wImage.setAttribute("alt", "cold");
    } else if (deg >= 32 && deg < 50){
        wImage.setAttribute("src", "cool.gif");
        wImage.setAttribute("alt", "cool");
    } else {
        wImage.setAttribute("src", "warm.gif");
        wImage.setAttribute("alt", "warm");
    }   
}

window.onload = domLoaded;
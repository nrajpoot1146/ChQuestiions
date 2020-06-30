let playerTurn = true;

let computerMoveTimeout = 0;

window.addEventListener("DOMContentLoaded", domLoaded);

function domLoaded() {

    window.turnInfo = document.getElementById("turnInfo");

    // Setup the click event for the "New game" button

    let newBtn = document.getElementById("newGameButton");

    newBtn.addEventListener("click", newGame);

    // Create click-event listeners for each cell in the game board

    let cells = getGameBoard();

    for (let cell of cells) {

        cell.addEventListener("click", function () { cellClicked(cell); });

    }

    // Call newGame() to make sure the board is clear

    newGame();

}

// Returns an array of 9 elements that make up the game board. The first 3

// elements are the top row, the next 3 the middle row, and the last 3 the

// bottom row.

function getGameBoard() {

    let gameBoardTable = document.getElementById("gameBoard");

    let result = [];

    for (let i = 0; i < 3; i++) {

        for (let j = 0; j < 3; j++) {

            result.push(gameBoardTable.rows[i].cells[j]);

        }

    }

    return result;

}

/**

* reset tic toc toe

* make turn player turn

*/

function newGame() {

    let cells = getGameBoard();

    for (let cell of cells){

        cell.innerHTML = "";

    }

    playerTurn = false;

    switchTurn();

}

/**

* listen user clicked

* @param {*} cell

*/

function cellClicked(cell) {

    if (playerTurn == true){

        if (cell.innerHTML == ""){

            cell.style.color = "red";

            cell.innerHTML = "X";

            switchTurn();

            computerMoveTimeout = setTimeout(makeComputerMove, 1000);

        }else{

            alert("Wrong move.");

        }

    }

}

/**

* switch turn between player and computer

* check player is win or not

* check game is over or not

* show meassage

*/

function switchTurn() {

    if (isWin() == -1){

        turnInfo.innerHTML = "Game Over";

        return;

    }

    if(isWin() && playerTurn){

        turnInfo.innerHTML = "You win!";

        playerTurn = -1;

        return;

    }else if(isWin()){

        turnInfo.innerHTML = "Computer Win!";

        playerTurn = -1;

        return;

    }

    playerTurn = !playerTurn;

    if (playerTurn){

        turnInfo.innerHTML = "Your Turn";

    }else{

        turnInfo.innerHTML = "Computer Turn";

    }

}

/**

* make computer move

* choose random position

* put O on random cell

*/

function makeComputerMove() {

    if (playerTurn == false){

        let cells = getGameBoard();

        let pos = Math.floor(Math.random() * 10) % 9;

        while (cells[pos].innerHTML != ""){

            pos = Math.floor(Math.random() * 10) % 9;

        }

        cells[pos].style.color = "blue";

        cells[pos].innerHTML = "O";

        switchTurn();

    }

    clearTimeout(computerMoveTimeout);

}

/**

* function to check win or not

* return true if one of the player is win

* return false if none player is win

* return -1 if each cell is filled with either O or X

*/

function isWin(){

    let cells = getGameBoard();

    // check row have same X or same O

    for (let i = 0; i < 3; i++){

        if (cells[i*3 + 0].innerHTML == "O" && cells[i*3 + 1].innerHTML == "O" && cells[i*3 + 2].innerHTML == "O"){

            return true;

        }else if(cells[i*3 + 0].innerHTML == "X" && cells[i*3 + 1].innerHTML == "X" && cells[i*3 + 2].innerHTML == "X"){

            return true;

        }

    }

    // check coll have same X or same O

    for (let i = 0; i < 3; i++){

        if (cells[0*3 + i].innerHTML == "O" && cells[1*3 + i].innerHTML == "O" && cells[2*3 + i].innerHTML == "O"){

            return true;

        }else if(cells[0*3 + i].innerHTML == "X" && cells[1*3 + i].innerHTML == "X" && cells[2*3 + i].innerHTML == "X"){

            return true;

        }

    }

    // chect atleast one cell is empty or not

    // if all cell is filled return -1;

    for (let cell of cells){

        if (cell.innerHTML == ""){

            return false;

        }

    }

    return -1;

}
let playerTurn = true;

let computerMoveTimeout = 0;
let EMPTY_CELL = "";

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

 * make turn player turn
  * reset tic toc toe
 */
function newGame() {
    let cells = getGameBoard();
    for (let c of cells){
        c.innerHTML = "";
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
        if (cell.innerHTML == EMPTY_CELL){
            cell.innerHTML = "X";
            cell.style.color = "red";
            computerMoveTimeout = setTimeout(makeComputerMove, 1000);
            switchTurn();
        }else{
            alert("Wrong cell move.");
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
    let isWinn = isWinner();
    if (isWinn == -1){
        turnInfo.innerHTML = "Game Over";
        return;
    }

    if(isWinn && playerTurn){
        playerTurn = -1;
        turnInfo.innerHTML = "You win!";
        return;
    }
    
    if(isWinn){
        playerTurn = -1;
        turnInfo.innerHTML = "Computer Win!";
        return;
    }

    playerTurn = !playerTurn;
    if (playerTurn){
        turnInfo.innerHTML = "Your Turn";
        return;
    }else
        turnInfo.innerHTML = "Computer Turn";
}

/**
 * make_computer_move
 * generate random number between 0-9
 * if cell with random number is empty put O in that cell
 * change style color to blue
 */
function makeComputerMove() {
    if (playerTurn == false){
        let cells = getGameBoard();
        // generate random number between 0 - 9
        let position = Math.floor(Math.random() * 10) % 9;
        while (cells[position].innerHTML != EMPTY_CELL){
            position = Math.floor(Math.random() * 10) % 9;
        }
        cells[position].innerHTML = "O";
        cells[position].style.color = "blue";
        switchTurn();
    }
    clearTimeout(computerMoveTimeout);
}

/**
 * function to check any player of two is win or not
 * return true if one of the player is win
 * return false if none player is win
 * return -1 if each cell is filled with either O or X
 */
function isWinner(){
    let cells = getGameBoard();

    
    // check coll have same X or same O
    for (let i = 0; i < 3; i++){
        if ( (cells[0*3 + i].innerHTML == "O" && cells[1*3 + i].innerHTML == "O" && cells[2*3 + i].innerHTML == "O")
            || (cells[0*3 + i].innerHTML == "X" && cells[1*3 + i].innerHTML == "X" && cells[2*3 + i].innerHTML == "X")
        ){
            return true;
        }
    }

    // check row have same X or same O
    for (let i = 0; i < 3; i++){
        if ( (cells[i*3 + 0].innerHTML == "O" && cells[i*3 + 1].innerHTML == "O" && cells[i*3 + 2].innerHTML == "O")
            || (cells[i*3 + 0].innerHTML == "X" && cells[i*3 + 1].innerHTML == "X" && cells[i*3 + 2].innerHTML == "X")
        ){
            return true;
        }
    }


    // chect atleast one cell is empty or not
    // if all cell is filled return -1;
    for (let c of cells){
        if (c.innerHTML == ""){
            return false;
        }
    }
    return -1;
}
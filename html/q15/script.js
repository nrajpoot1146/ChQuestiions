
/**
 * get list of game board cell
 * @return list of cells
 */
var getCells = function(){
    let gameBoard = document.getElementById("game");
    let cells = [];
    for (let i=0; i<3; i++){
        for (let j=0; j<3; j++){
            cells.push(gameBoard.rows[i].cells[j]);
        }
    }

    return cells;
}

/**
 * switch turn between x marker and o marker
 */
var switchTurn = function () {
    window.playerTurn = !window.playerTurn;
}

/**
 * check atleast one cell is empty or not
 * @return true if atleast one cell is empty otherwise return false
 */
var isEmpty = function(){
    let cells = getCells();

    for (let cell of cells){
        if (! cell.classList.contains("x-marker") && ! cell.classList.contains("o-marker"))
            return true;
    }
    return false;
}

/**
 * check one of ther players is win or not
 * @return true if win otherwise return false
 */
var isWin = function(){
    let cells = getCells();
    let winnerColor = "#82E0AA";
    // check coll have same X or same O
    for (let i = 0; i < 3; i++){
        if ( (cells[0*3 + i].classList.contains("o-marker") && cells[1*3 + i].classList.contains("o-marker") && cells[2*3 + i].classList.contains("o-marker"))
            || (cells[0*3 + i].classList.contains("x-marker") && cells[1*3 + i].classList.contains("x-marker") && cells[2*3 + i].classList.contains("x-marker"))
        ){
            // change cell color
            cells[0*3 + i].style.backgroundColor = winnerColor;
            cells[1*3 + i].style.backgroundColor = winnerColor;
            cells[2*3 + i].style.backgroundColor = winnerColor;
            return true;
        }
    }

    // check row have same X or same O
    for (let i = 0; i < 3; i++){
        if ( (cells[i*3 + 0].classList.contains("o-marker") && cells[i*3 + 1].classList.contains("o-marker") && cells[i*3 + 2].classList.contains("o-marker"))
            || (cells[i*3 + 0].classList.contains("x-marker") && cells[i*3 + 1].classList.contains("x-marker") && cells[i*3 + 2].classList.contains("x-marker"))
        ){
            // change cell color
            cells[i*3 + 0].style.backgroundColor = winnerColor;
            cells[i*3 + 1].style.backgroundColor = winnerColor;
            cells[i*3 + 2].style.backgroundColor = winnerColor;
            return true;
        }
    }

    // first diagnonal check 
    if ( (cells[0].classList.contains("o-marker") && cells[4].classList.contains("o-marker") && cells[8].classList.contains("o-marker"))
        || (cells[0].classList.contains("x-marker") && cells[4].classList.contains("x-marker") && cells[8].classList.contains("x-marker"))
    ){
        // change cell color
        cells[0].style.backgroundColor = winnerColor;
        cells[4].style.backgroundColor = winnerColor;
        cells[8].style.backgroundColor = winnerColor;
        return true;
    }
    // second diagonal check
    if ( (cells[2].classList.contains("o-marker") && cells[4].classList.contains("o-marker") && cells[6].classList.contains("o-marker"))
        || (cells[2].classList.contains("x-marker") && cells[4].classList.contains("x-marker") && cells[6].classList.contains("x-marker"))
    ){
        // change cell color
        cells[2].style.backgroundColor = winnerColor;
        cells[4].style.backgroundColor = winnerColor;
        cells[6].style.backgroundColor = winnerColor;
        return true;
    }
}

/**
 * function to handle cell clicks
 * @param cell 
 */
var cellClickedListener = function(cell){
    if (window.playerTurn == -1){
        return;
    }

    if (window.playerTurn){
        if (! cell.classList.contains("o-marker") && ! cell.classList.contains("x-marker")){
            cell.classList.add("x-marker");
            if (isWin()){
                document.getElementById("win-info").innerHTML = "X Win!";
                window.playerTurn = -1;
                return;
            } else
                switchTurn();
        }
    } else {
        if (! cell.classList.contains("o-marker") && ! cell.classList.contains("x-marker")){
            cell.classList.add("o-marker");
            if (isWin()){
                document.getElementById("win-info").innerHTML = "O Win!";
                window.playerTurn = -1;
                return;
            } else
                switchTurn();
        }
    }

    // update player turn information
    if(playerTurn){
        document.getElementById("win-info").innerHTML = "X Turn!";
    } else{
        document.getElementById("win-info").innerHTML = "O Turn!";
    }

    if (!isEmpty()){
        document.getElementById("win-info").innerHTML = "Game Over!";
        return;
    }

}

window.onload = function(){
    let cells = getCells();
    window.playerTurn = true;

    // attach listener
    for (let cell of cells){
        cell.addEventListener("click", function (){
            cellClickedListener(cell);
        });
    }

    document.getElementById("win-info").innerHTML = "X Turn!";

    // new game button listener
    document.getElementById("new-game").addEventListener("click",function () {
        window.location.reload();
    });
}
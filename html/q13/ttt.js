$(document).ready(function () {
    let turnFlag = true; // flag to switch between X annd O
    
    /*
     * attach click listener to each cell 
     */
    $("td").click(function (e){

        // if cell is not empty return without doing anything
        if (e.target.innerHTML != ""){
            return;
        }

        // put O with text color red
        if (turnFlag) {
            e.target.style.color = "Red";
            e.target.innerHTML = "O";
            turnFlag = false;
        } else { // put X with text color X
            e.target.style.color = "blue";
            e.target.innerHTML = "X";
            turnFlag = true;
        }

        // condition to check game board cell is completely full or not
        if (isFull()){
            $("#info").html("Game Over!"); // declare game over if all cell is full
        }
    });

    /*
    * function to check cell of game board is full or not
    * @return true if all cells filled with X or O
    */
    function isFull(){
        let cells = $("td");
        
        for (let i=0; i < cells.length; i++){
            if (cells[i].innerHTML == ""){
                return false;
            }
        }

        return true;
    }

  });
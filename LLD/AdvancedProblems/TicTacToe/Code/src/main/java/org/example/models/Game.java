package org.example.models;

import org.example.enums.ResultState;
public class Game {

    private Board board;
    private Player[] players;
    private Player currentPlayer;
    private Result result;


    public void startGame(Player player1, Player player2){
        this.players = new Player[]{player1,player2};
        this.currentPlayer = player1;
        this.board = new Board();
        this.result = new Result();
    }

    public void switchPlayer(){
        if(currentPlayer == players[0]){
            currentPlayer = players[1];
        } else {
            currentPlayer = players[0];
        }
    }
    
    public void makeMove(int row, int col){
        if(board.isCellEmpty(row, col)){
            board.placeSymbol(currentPlayer, row, col);
            if(board.checkWin(currentPlayer)){
                result.setWinner(currentPlayer);
                result.setResultState(ResultState.WIN);
            }
            else if(board.isFull()){
                result.setResultState(ResultState.DRAW);
            }
        } else {
            throw new IllegalArgumentException("Cell is already occupied!");
        }
    }

    public Player getCurrentPlayer() {
        return currentPlayer;
    }

    public Result getResult() {
        return result;
    }
}

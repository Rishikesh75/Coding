package org.example.models;

import org.example.enums.Symbol;
import org.example.exceptions.PositionException;

public class Board {
    private Cell[][] board;

    public Board(){
        board = new Cell[3][3];

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j] = new Cell();
                board[i][j].setSymbol(Symbol.Empty);
            }
        }
    }


    public boolean isCellEmpty(int row, int col){
        return board[row][col].getSymbol() == Symbol.Empty;
    }
    public void placeSymbol(Player p,int row,int column) throws PositionException{

        if(row<=3 && column<=3){
            this.board[row][column].setSymbol(p);
            return;
        }

        throw new PositionException(String.format("Row %d Column %d are out of bound",row,column));
    }

    public boolean isFull(){
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][i].getSymbol() == Symbol.Empty){
                    return false;
                }
            }
        }

        return true;
    }

    public void resetBoard(){
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
               board[i][j].setSymbol(Symbol.Empty);

            }
        }
    }

    public boolean checkWin(Player player){
        Symbol symbol = player.getSymbol();
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0].getSymbol() == symbol && board[i][1].getSymbol() == symbol && board[i][2].getSymbol() == symbol) {
                return true;
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j].getSymbol() == symbol && board[1][j].getSymbol() == symbol && board[2][j].getSymbol() == symbol) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0].getSymbol() == symbol && board[1][1].getSymbol() == symbol && board[2][2].getSymbol() == symbol) {
            return true;
        }
        if (board[0][2].getSymbol() == symbol && board[1][1].getSymbol() == symbol && board[2][0].getSymbol() == symbol) {
            return true;
        }

        return false;
    }
}

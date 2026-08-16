package org.example;

import org.example.enums.ResultState;
import org.example.enums.Symbol;
import org.example.models.Game;
import org.example.models.Player;

import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        Player player1 = new Player("Player 1", Symbol.X);
        Player player2 = new Player("Player 2", Symbol.O);
        Game game = new Game();
        
        game.startGame(player1, player2);
        

        while(game.getResult().getResultState() == ResultState.IN_PROGRESS) {
            // Get the current player
            Player currentPlayer = game.getCurrentPlayer();
            // Get the row and column from the current player (this can be done via user input)
    
            System.out.println(currentPlayer.getSymbol() + "'s turn. Enter row and column (0-2):");
            int row = Integer.parseInt(sc.nextLine());
            int col = Integer.parseInt(sc.nextLine());
            try {
                game.makeMove(row, col);
                game.switchPlayer();
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }

        System.out.println("Winner"+ game.getResult().getWinner().getName());
    }
}

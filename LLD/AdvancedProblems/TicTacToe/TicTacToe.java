import java.util.*;
import java.lang.*;
import java.io.*;


enum Symbol
{
    X,O
}

enum Result
{
    DRAW,PENDING,DONE
}

class User
{
    public int id;
    public String name;
    public Symbol symbol;
    
    public User(int id,String name){
        this.id = id;
        this.name = name;
    }
    
    public void setSymbol(Symbol symbol)
    {
        this.symbol = symbol;
    }
}

class Board
{
    private Symbol[][] board;
    private int count;
    
    public Board()
    {
        board = new Symbol[3][3];
    }
    
    public void setSymbol(int row,int column,Symbol symbol){
        board[row][column] = symbol;
        count++;
    }
    
    public Result checkState(Symbol symbol){
        
        //Row
        for(int i=0;i<3;i++){
            
            int count = 0;
            
            for(int j=0;j<3;j++){
                if(board[i][j] == symbol) 
                    count++;
            }
            
            if(count == 3) 
                return Result.DONE;
        }
        
        //Column
        for(int i=0;i<3;i++){
            
            int count = 0;
            
            for(int j=0;j<3;j++){
                if(board[j][i] == symbol) 
                    count++;
            }
            
            if(count == 3) 
                return Result.DONE;
        }
        
        //Diagnol
        int count = 0;
        for(int i=0;i<3;i++){
            if(board[i][i] == symbol)
                count++;
        }
        
        if(count == 3) 
            return Result.DONE;
            
        
        count = 0;
        for(int i=0;i<3;i++){
            if(board[i][2-i] == symbol)
                count++;
        }
        
        if(count == 3) 
            return Result.DONE;
            
        else if(this.count == 9) 
            return Result.DRAW;
            
        return Result.PENDING;
    }
}

class Game
{
    private User user1;
    private User user2;
    private Board board;
    
    private User currentPlayer;
    
    public Game()
    {
        this.board = new Board();
    }

    static Scanner sc = new Scanner(System.in);
    
    
    public void setUser1(User user){
        this.user1 = user;
    }
    
    public void setUser2(User user){
        this.user2 = user;
    }
    
    public void setCurrentPlayer()
    {
        this.currentPlayer = this.user1;
    }
    public void changeCurrentPlayer(){
        if(currentPlayer == this.user2)
            this.currentPlayer = user1;
        else
            this.currentPlayer = user2;
    }
    

    public void play()
    {
        while(true){
            
            int row = Integer.parseInt(sc.nextLine());
            int column = Integer.parseInt(sc.nextLine());
            board.setSymbol(row,column,currentPlayer.symbol);
            var result = board.checkState(currentPlayer.symbol);
            if(result == Result.DRAW)
            {
                System.out.println("Game is Draw");
                break;
            }
            
            else if(result == Result.DONE){
                System.out.printf("Game won by:%s Symbol:%s",currentPlayer.name,currentPlayer.symbol);
                break;
            }
            
            changeCurrentPlayer();
        }
        
    }
    
    
    public void setBoard(Board board){
        this.board = board;
    }
    
    
    
    
}
class TicTacToe
{
	
	
	public static void main (String[] args) throws java.lang.Exception
	{
		User user1 = new User(1,"Rishi");
		user1.setSymbol(Symbol.X);
		
		User user2 = new User(2,"Nani");
		user2.setSymbol(Symbol.O);
		
		Game game = new Game();
		game.setUser1(user1);
		game.setUser2(user2);
		
		game.setCurrentPlayer();
		
		game.play();

	}
}

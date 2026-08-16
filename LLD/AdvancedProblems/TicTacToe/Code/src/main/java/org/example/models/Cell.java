package org.example.models;

import org.example.enums.Symbol;

public class Cell {
    private int row;
    private int column;
    private Symbol symbol;

    public void setSymbol(Player p){
        this.symbol = p.getSymbol();
    }

    public void setSymbol(Symbol symbol){
        this.symbol = symbol;
    }

    public Symbol getSymbol(){
        return this.symbol;
    }
}

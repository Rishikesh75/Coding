package org.example.models;

import org.example.enums.Symbol;

public class Player {
    private String name;
    private Symbol symbol;

    public Player(String name, Symbol symbol) {
        this.name = name;
        this.symbol = symbol;
    }
    public Symbol getSymbol(){
        return symbol;
    }

    public String getName(){
        return name;
    }
}

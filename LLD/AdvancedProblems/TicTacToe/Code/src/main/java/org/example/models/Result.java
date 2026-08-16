package org.example.models;

import org.example.enums.ResultState;

public class Result {
    private  Player winner;
    private ResultState resultState;

    public Result() {
        this.resultState = ResultState.IN_PROGRESS;
        this.winner = null;
    }
    public Player getWinner() {
        return winner;
    }

    public void setWinner(Player winner) {
        this.winner = winner;
    }

    public ResultState getResultState() {
        return resultState;
    }

    public void setResultState(ResultState resultState) {
        this.resultState = resultState;
    }
}

package Service;

import models.Ladder;
import models.Player;
import models.Snake;
import models.SnakeAndLadderBoard;

import java.util.*;

public class SnakeAndLadderService {
    private SnakeAndLadderBoard snakeAndLadderBoard;
    private int initialNumberOfPlayers;
    private Queue<Player> players;
    private boolean isCompleted;

    private static final int DEFAULT_BOARD_SIZE = 100;

    public SnakeAndLadderService(int boardSize) {
        this.snakeAndLadderBoard = new SnakeAndLadderBoard(boardSize);
        this.players = new LinkedList<>();
    }

    public SnakeAndLadderService() {
        this.snakeAndLadderBoard = new SnakeAndLadderBoard(SnakeAndLadderService.DEFAULT_BOARD_SIZE);
    }

    public void setPlayers(List<Player> players) {
        this.players = new LinkedList<>();
        this.initialNumberOfPlayers = players.size();

        Map<String, Integer> playerPieces = new HashMap<>();

        for (Player player : players) {
            this.players.add(player);
            playerPieces.put(player.getId(), 0);
        }

        snakeAndLadderBoard.setPlayerPieces(playerPieces);
    }

    public void setSnakes(List<Snake> snakes) {
        snakeAndLadderBoard.setSnakes(snakes);
    }

    public void setLadders(List<Ladder> ladders) {
        snakeAndLadderBoard.setLadders(ladders);
    }

    private int getTotalValueAfterDiceRolls() {
        return DiceService.roll();
    }

    private int getNewPositionAfterGoingThroughSnakesAndLadders(int newPosition) {
        int previousPosition;

        do {
            previousPosition = newPosition;

            for (Snake snake : snakeAndLadderBoard.getSnakes()) {
                if (snake.getStart() == newPosition) {
                    newPosition = snake.getEnd();
                }
            }

            for (Ladder ladder : snakeAndLadderBoard.getLadders()) {
                if (ladder.getStart() == newPosition) {
                    newPosition = ladder.getEnd();
                }
            }
        } while (newPosition != previousPosition);

        return newPosition;
    }

    private boolean hasPlayerWon(Player player) {
        int playerPosition = snakeAndLadderBoard.getPlayerPieces().get(player.getId());
        int winningPosition = snakeAndLadderBoard.getSize();
        return playerPosition == winningPosition;
    }

    private boolean isGameCompleted() {
        int currentNumberOfPlayers = players.size();
        return currentNumberOfPlayers < initialNumberOfPlayers;
    }

    private void movePlayer(Player player, int positions) {
        int oldPosition = snakeAndLadderBoard.getPlayerPieces().get(player.getId());
        int newPosition = oldPosition + positions;

        int boardSize = snakeAndLadderBoard.getSize();

        if (newPosition > boardSize) {
            newPosition = oldPosition;
        } else {
            newPosition = getNewPositionAfterGoingThroughSnakesAndLadders(newPosition);
        }

        snakeAndLadderBoard.getPlayerPieces().put(player.getId(), newPosition);

        System.out.println(player.getName() + " rolled a " + positions + " and moved from " + oldPosition + " to " + newPosition);
    }

    public void startGame() {
        while (!isCompleted) {
            int totalDiceValue = getTotalValueAfterDiceRolls();
            Player currentPlayer = players.poll();

            if (hasPlayerWon(currentPlayer)) {
                System.out.println(currentPlayer.getName() + " wins the game");
                snakeAndLadderBoard.getPlayerPieces().remove(currentPlayer.getId());
            } else {
                players.add(currentPlayer);
            }
        }
    }
}

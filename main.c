#include <stdio.h>

struct TicTacToe {
    char board[3][3];
};

void initBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            board[i][y] = ' ';
        }
    }
}

int playBoard(int position, char value, char board[3][3]) {
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            index++;
            if (index == position && board[i][j] == ' ') {
                board[i][j] = value;
                return 1;
            }
        }
    }
    return 0;
}

void printBoard(struct TicTacToe ticTacToe) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
                printf("|%c", ticTacToe.board[i][y]);
        }
        printf("|\n");
    }
}

char checkBoard(char board[3][3]) {
   
    // Check horizontals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if (board[i][1] != ' ') {
                return board[i][1];
            }
        }
    }
   
    // Check verticals
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[1][i] != ' ') {
                return board[1][i];
            }
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if (board[0][0] != ' ') {
            return board[0][0];
        }
    }
    if (board[1][1] == board[0][2] && board[1][1] == board[2][0]) {
        if (board[1][1] != ' ') {
            return board[1][1];
        }
    }

    // Check for tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return ' ';
            }
        }
    }
    return 't';
}

int main(int argc, char** argv) {
    struct TicTacToe ticTacToe; 
    int location;
    int player;
    int success;
    char winner;

    initBoard(ticTacToe.board);
    player = 1;
    winner = ' ';
    printf("=== T I C  T A C  T O E ===\n");
    printBoard(ticTacToe);
    while(winner == ' ') {
        printf("Please enter a position (1-9): ");
        scanf("%d", &location);
        if(playBoard(location, player ? 'x' : 'o', ticTacToe.board)) {
            player = !player;
        }
        printBoard(ticTacToe);
        winner = checkBoard(ticTacToe.board);
    }
    if (winner == 't') {
        printf("It's a tie!\n");
    } else {
        printf("Congratulations, winner is %c!\n", winner);
    }
    printf("\n=== T I C  T A C  T O E ===\n");
}


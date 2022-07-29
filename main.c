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

int main(int argc, char** argv) {
    struct TicTacToe ticTacToe; 
    int location;
    int player;
    int success;
    int done;

    initBoard(ticTacToe.board);
    player = 1;
    done = 0;
    printf("=== T I C  T A C  T O E ===\n");
    printBoard(ticTacToe);
    while(done == 0) {
        printf("Please enter a position (1-9): ");
        scanf("%d", &location);
        if(playBoard(location, player ? 'x' : 'o', ticTacToe.board)) {
            player = !player;
        }
        printBoard(ticTacToe);
    }
    return 0;
}


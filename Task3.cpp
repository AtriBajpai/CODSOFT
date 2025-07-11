#include <iostream>
using namespace std;

char board[3][3];      
char player = 'X';     

void setupBoard() {
    char num = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void showBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

void switchPlayer() {
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

bool validMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
        return true;
    else
        return false;
}

void makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    board[row][col] = player;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player &&
             board[i][1] == player &&
             board[i][2] == player) ||

            (board[0][i] == player &&
             board[1][i] == player &&
             board[2][i] == player))
            return true;
    }

    if ((board[0][0] == player &&
         board[1][1] == player &&
         board[2][2] == player) ||

        (board[0][2] == player &&
         board[1][1] == player &&
         board[2][0] == player))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

int main() {
    char playAgain;

    do {
        setupBoard();         
        player = 'X';          
        int move;
        bool gameEnd = false;

        while (!gameEnd) {
            showBoard();

            cout << "Player " << player << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || !validMove(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            makeMove(move);

            if (checkWin()) {
                showBoard();
                cout << "Player " << player << " wins!\n";
                gameEnd = true;
            } else if (checkDraw()) {
                showBoard();
                cout << "It's a draw!\n";
                gameEnd = true;
            } else {
                switchPlayer(); 
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!\n";

    return 0;
}


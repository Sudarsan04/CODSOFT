#include <iostream>
using namespace std;
char board[3][3];
char currentPlayer;
void initializeBoard() {
    char count = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count++;
        }
    }
}
void displayBoard() {
    cout << "\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
    cout << "\n";
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}
bool makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        cout << "Invalid move! Cell already taken. Try again.\n";
        return false;
    }
}
int main() {
    char playAgain;
    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameOver = false;
        cout << "===== TIC-TAC-TOE GAME =====\n";
        displayBoard();
        while (!gameOver) {
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;
            if (move < 1 || move > 9) {
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
                continue;
            }
            if (!makeMove(move)) continue;
            displayBoard();
            if (checkWin()) {
                cout << "?? Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}

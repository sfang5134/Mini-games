#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// Function prototypes
void printBoard(char board[5][5], int size);
void initializeBoard(char board[5][5], int size);
void placeShips(char board[5][5], int size);
void playerTurn(char board[5][5], char board2[5][5], int size);
void computerTurn(char board[5][5], char board2[5][5], int size);
bool checkWin(char board[5][5], int size);
bool checkDraw(char board[5][5], char board2[5][5], int size);
bool isValidInput(int row, int col, int size);

int main() {
    char board[5][5];
    char board2[5][5];
    int size = 5;
    bool exitGame = false;
    char choice;
    srand(time(0)); // Seed for random number generation

    // Game loop
    while (!exitGame) {
        // Game menu
        cout << "Battleship Menu:" << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. View Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case '1':
            // Start new game
            initializeBoard(board, size);
            initializeBoard(board2, size);
            placeShips(board, size);

            // Game rounds loop
            while (true) {
                // Player's turn
                playerTurn(board, board2, size);
                if (checkWin(board, size)) {
                    cout << "Congratulations! You sunk all the ships!" << endl;
                    break; // Player wins
                }
                if (checkDraw(board, board2, size)) {
                    cout << "The game ended in a draw!" << endl;
                    break; // Draw
                }

                // Computer's turn
                computerTurn(board, board2, size);
                if (checkWin(board, size)) {
                    cout << "Game over! The computer sunk all your ships!" << endl;
                    break; // Computer wins
                }
                if (checkDraw(board, board2, size)) {
                    cout << "The game ended in a draw!" << endl;
                    break; // Draw
                }
            }
            break;
        case '2':
            // View instructions
            cout << "Welcome to Battleship!" << endl;
            cout << "The goal of the game is to sink all the ships on the board." << endl;
            cout << "You will be given a 5x5 board with 3 ships randomly placed on it." << endl;
            cout << "You will have to guess the location of the ships by entering the row and column." << endl;
            cout << "If you hit a ship, it will be marked with an 's' on the board." << endl;
            cout << "If you miss, it will be marked with an 'm' on the board." << endl;
            cout << "You win the game by sinking all the ships." << endl;
            break;
        case '3':
            exitGame = true;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}

void printBoard(char board[5][5], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void initializeBoard(char board[5][5], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i][j] = '-';
        }
    }
}

void placeShips(char board[5][5], int size) {
    for (int i = 0; i < 3; ++i) {
        int row = rand() % size;
        int col = rand() % size;
        board[row][col] = 's';
    }
}

void playerTurn(char board[5][5], char board2[5][5], int size) {
    int row, col;
    cout << "Enter your guess (row and column, 0-4): ";
    cin >> row >> col;
    cout << endl;

    // Input validation
    while (!isValidInput(row, col, size) || board2[row][col] != '-') {
        cout << "Invalid guess. Please enter a valid row and column (0-4): ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cin >> row >> col;
        cout << endl;
    }

    if (board[row][col] == 's') {
        cout << "Hit!" << endl;
        board2[row][col] = 's';
    }
    else {
        cout << "Miss!" << endl;
        board2[row][col] = 'm';
    }

    cout << "Your board:" << endl;
    printBoard(board2, size);
    cout << endl;
}

void computerTurn(char board[5][5], char board2[5][5], int size) {
    int row, col;
    do {
        row = rand() % size;
        col = rand() % size;
    } while (board2[row][col] != '-');

    if (board[row][col] == 's') {
        cout << "The computer hit your ship!" << endl;
        board2[row][col] = 's';
    }
    else {
        cout << "The computer missed!" << endl;
        board2[row][col] = 'm';
    }

    cout << "Computer's board:" << endl;
    printBoard(board2, size);
    cout << endl;
}

bool checkWin(char board[5][5], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == 's') {
                return false; // Ships remaining
            }
        }
    }
    return true; // All ships sunk
}

bool checkDraw(char board[5][5], char board2[5][5], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == 's' && board2[i][j] == '-') {
                return false; // Still ships remaining and unrevealed cells
            }
        }
    }
    return true; // All cells revealed and still ships remaining
}

bool isValidInput(int row, int col, int size) {
    return row >= 0 && row < size && col >= 0 && col < size;
}
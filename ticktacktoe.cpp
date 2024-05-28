#include <iostream>
#include <limits>
using namespace std;

// Function prototypes
void print2Darray(char arr[][3], int rows, int cols);
bool checkWin(char grid[3][3]);
bool checkDraw(char grid[3][3]);
bool isValidInput(int row, int col);

int main() {
    // Create a tic-tac-toe game
    char grid[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    bool exitGame = false;
    char choice;

    while (!exitGame) {
        cout << "Tic Tac Toe Menu:" << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            // Reset the board
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    grid[i][j] = '-';
                }
            }

            // Game loop
            bool gameOver = false;
            char currentPlayer = 'X';

            while (!gameOver) {
                // Print the current board
                print2Darray(grid, 3, 3);

                // Player input
                int row, col;
                cout << "Player " << currentPlayer << ": Enter the row and column (0-2): ";
                cin >> row >> col;

                // Input validation
                while (!isValidInput(row, col) || grid[row][col] != '-') {
                    cout << "Invalid input. Please enter a valid row and column (0-2): ";
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    cin >> row >> col;
                }

                // Update the grid
                grid[row][col] = currentPlayer;

                // Check for win or draw
                if (checkWin(grid)) {
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                }
                else if (checkDraw(grid)) {
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                }

                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            break;
        }
        case '2':
            exitGame = true;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}

void print2Darray(char arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char grid[3][3]) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '-') {
            return true; // Row win
        }
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '-') {
            return true; // Column win
        }
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '-') {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '-') {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

bool checkDraw(char grid[3][3]) {
    // Check if the grid is full (no more empty cells)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == '-') {
                return false; // Grid is not full yet
            }
        }
    }
    return true; // Grid is full (draw)
}

bool isValidInput(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3;
}
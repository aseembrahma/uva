#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <string>

#define CHESS_BOARD_SIZE 8

using namespace std;

static char board[CHESS_BOARD_SIZE][CHESS_BOARD_SIZE];

void reset() {
    for (unsigned short i = 0; i < CHESS_BOARD_SIZE; i++)
        for (unsigned short j = 0; j < CHESS_BOARD_SIZE; j++)
            board[i][j] = '.';
}

int main(int argc, char* argv[]) {
    unsigned long long int game_number = 0;
    do {
        reset();

        string line;
        bool empty_board = true;

        game_number++;

        for (unsigned short i = 0; i < CHESS_BOARD_SIZE; i++) {
            getline(cin, line);
            istringstream iss (line);

            for (unsigned short j = 0; j < CHESS_BOARD_SIZE; j++) {
                iss >> board[i][j];
                if (empty_board == true && board[i][j] != '.')
                    empty_board = false;
            }
        }
        if (empty_board == true)
            break;

        /*
        for (unsigned short i = 0; i < CHESS_BOARD_SIZE; i++) {
            for (unsigned short j = 0; j < CHESS_BOARD_SIZE; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << endl;
        */

        bool white_king_check = false, black_king_check = false;
        for (unsigned short i = 0; i < CHESS_BOARD_SIZE; i++) {
            if (white_king_check == true || black_king_check == true)
                    break;

            for (unsigned short j = 0; j < CHESS_BOARD_SIZE; j++) {

                if (board[i][j] == '.'
                    || board[i][j] == 'k'
                    || board[i][j] == 'K')
                    continue;

                // Black is in lowercase, and on the top
                // White is in uppercase, and on the bottom
                // p/P n/N b/B r/R q/Q k/K

                if (board[i][j] == 'p') {
                    // can attack [i+1][j-1], [i+1][j+1]
                    if (i + 1 < CHESS_BOARD_SIZE) {
                        if (j - 1 >= 0 && board[i + 1][j - 1] == 'K')
                            white_king_check = true;
                        if (j + 1 < CHESS_BOARD_SIZE && board[i + 1][j + 1] == 'K')
                            white_king_check = true;

                    }
                }
                else if (board[i][j] == 'P') {
                    // can attack [i-1][j-1], [i-1][j+1]
                    if (i - 1 >= 0) {
                        if (j - 1 >= 0 && board[i - 1][j - 1] == 'k')
                            black_king_check = true;
                        if (j + 1 < CHESS_BOARD_SIZE && board[i - 1][j + 1] == 'k')
                            black_king_check = true;

                    }
                }
                else if (board[i][j] == 'n') {
                    // can attack [i-2][j-1], [i-2][j+1],
                    //            [i-1][j-2], [i+1][j-2],
                    //            [i-1][j+2], [i+1][j+2],
                    //            [i+2][j-1], [i+2][j+1]
                    if (i - 2 >= 0) {
                        if (j - 1 >= 0 && board[i - 2][j - 1] == 'K')
                            white_king_check = true;
                        if (j + 1 < CHESS_BOARD_SIZE && board[i - 2][j + 1] == 'K')
                            white_king_check = true;
                    }
                    if (j - 2 >= 0) {
                        if (i - 1 >= 0 && board[i - 1][j - 2] == 'K')
                            white_king_check = true;
                        if (i + 1 < CHESS_BOARD_SIZE && board[i + 1][j - 2] == 'K')
                            white_king_check = true;
                    }
                    if (j + 2 < CHESS_BOARD_SIZE) {
                        if (i - 1 >= 0 && board[i - 1][j + 2] == 'K')
                            white_king_check = true;
                        if (i + 1 < CHESS_BOARD_SIZE && board[i + 1][j + 2] == 'K')
                            white_king_check = true;
                    }
                    if (i + 2 < CHESS_BOARD_SIZE) {
                        if (j - 1 >= 0 && board[i + 2][j - 1] == 'K')
                            white_king_check = true;
                        if (j + 1 < CHESS_BOARD_SIZE && board[i + 2][j + 1] == 'K')
                            white_king_check = true;
                    }
                }
                else if (board[i][j] == 'N') {
                    // can attack [i-2][j-1], [i-2][j+1],
                    //            [i-1][j-2], [i+1][j-2],
                    //            [i-1][j+2], [i+1][j+2],
                    //            [i+2][j-1], [i+2][j+1]
                    if (i - 2 >= 0) {
                        if (j - 1 >= 0 && board[i - 2][j - 1] == 'K')
                            black_king_check = true;
                        if (j + 1 < CHESS_BOARD_SIZE && board[i - 2][j + 1] == 'k')
                            black_king_check = true;
                    }
                    if (j - 2 >= 0) {
                        if (i - 1 >= 0 && board[i - 1][j - 2] == 'K')
                            black_king_check = true;
                        if (i + 1 < CHESS_BOARD_SIZE && board[i + 1][j - 2] == 'k')
                            black_king_check = true;
                    }
                    if (j + 2 < CHESS_BOARD_SIZE) {
                        if (i - 1 >= 0 && board[i - 1][j + 2] == 'K')
                            black_king_check = true;
                        if (i + 1 < CHESS_BOARD_SIZE && board[i + 1][j + 2] == 'k')
                            black_king_check = true;
                    }
                    if (i + 2 < CHESS_BOARD_SIZE) {
                        if (j - 1 >= 0 && board[i + 2][j - 1] == 'K')
                            black_king_check = true;
                        if (j + 1 < CHESS_BOARD_SIZE && board[i + 2][j + 1] == 'k')
                            black_king_check = true;
                    }
                }
                else if (board[i][j] == 'b') {
                    unsigned short int k = 1;

                    k = 1;
                    while (i - k >= 0 && j - k >= 0 && white_king_check == false) {
                        if (board[i - k][j - k] == 'K')
                            white_king_check = true;
                        else if (board[i - k][j - k] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && j + k < CHESS_BOARD_SIZE && white_king_check == false) {
                        if (board[i + k][j + k] == 'K')
                            white_king_check = true;
                        else if (board[i + k][j + k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (i - k >= 0 && j + k < CHESS_BOARD_SIZE && white_king_check == false) {
                        if (board[i - k][j + k] == 'K')
                            white_king_check = true;
                        else if (board[i - k][j + k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && j - k >= 0 && white_king_check == false) {
                        if (board[i + k][j - k] == 'K')
                            white_king_check = true;
                        else if (board[i + k][j - k] != '.')
                            break;
                        k++;
                    }
                }
                else if (board[i][j] == 'B') {
                    unsigned short int k = 1;

                    k = 1;
                    while (i - k >= 0 && j - k >= 0 && black_king_check == false) {
                        if (board[i - k][j - k] == 'k')
                            black_king_check = true;
                        else if (board[i - k][j - k] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && j + k < CHESS_BOARD_SIZE && black_king_check == false) {
                        if (board[i + k][j + k] == 'k')
                            black_king_check = true;
                        else if (board[i + k][j + k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (i - k >= 0 && j + k < CHESS_BOARD_SIZE && black_king_check == false) {
                        if (board[i - k][j + k] == 'k')
                            black_king_check = true;
                        else if (board[i - k][j + k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && j - k >= 0 && black_king_check == false) {
                        if (board[i + k][j - k] == 'k')
                            black_king_check = true;
                        else if (board[i + k][j - k] != '.')
                            break;
                        k++;
                    }
                }
                else if (board[i][j] == 'r') {
                    unsigned short int k = 1;

                    k = 1;
                    while (i - k >= 0 && white_king_check == false) {
                        if (board[i - k][j] == 'K')
                            white_king_check = true;
                        else if (board[i - k][j] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && white_king_check == false) {
                        if (board[i + k][j] == 'K')
                            white_king_check = true;
                        else if (board[i + k][j] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (j - k >= 0 && white_king_check == false) {
                        if (board[i][j - k] == 'K')
                            white_king_check = true;
                        else if (board[i][j - k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (j + k < CHESS_BOARD_SIZE && white_king_check == false) {
                        if (board[i][j + k] == 'K')
                            white_king_check = true;
                        else if (board[i][j + k] != '.')
                            break;
                        k++;
                    }
                }
                else if (board[i][j] == 'R') {
                    unsigned short int k = 1;

                    k = 1;
                    while (i - k >= 0 && black_king_check == false) {
                        if (board[i - k][j] == 'k')
                            black_king_check = true;
                        else if (board[i - k][j] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && black_king_check == false) {
                        if (board[i + k][j] == 'k')
                            black_king_check = true;
                        else if (board[i + k][j] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (j - k >= 0 && black_king_check == false) {
                        if (board[i][j - k] == 'k')
                            black_king_check = true;
                        else if (board[i][j - k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (j + k < CHESS_BOARD_SIZE && black_king_check == false) {
                        if (board[i][j + k] == 'k')
                            black_king_check = true;
                        else if (board[i][j + k] != '.')
                            break;
                        k++;
                    }
                }
                else if (board[i][j] == 'q') {
                    unsigned short int k = 1;

                    k = 1;
                    while (i - k >= 0 && white_king_check == false) {
                        if (board[i - k][j] == 'K')
                            white_king_check = true;
                        else if (board[i - k][j] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && white_king_check == false) {
                        if (board[i + k][j] == 'K')
                            white_king_check = true;
                        else if (board[i + k][j] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (j - k >= 0 && white_king_check == false) {
                        if (board[i][j - k] == 'K')
                            white_king_check = true;
                        else if (board[i][j - k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (j + k < CHESS_BOARD_SIZE && white_king_check == false) {
                        if (board[i][j + k] == 'K')
                            white_king_check = true;
                        else if (board[i][j + k] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i - k >= 0 && j - k >= 0 && white_king_check == false) {
                        if (board[i - k][j - k] == 'K')
                            white_king_check = true;
                        else if (board[i - k][j - k] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && j + k < CHESS_BOARD_SIZE && white_king_check == false) {
                        if (board[i + k][j + k] == 'K')
                            white_king_check = true;
                        else if (board[i + k][j + k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (i - k >= 0 && j + k < CHESS_BOARD_SIZE && white_king_check == false) {
                        if (board[i - k][j + k] == 'K')
                            white_king_check = true;
                        else if (board[i - k][j + k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && j - k >= 0 && white_king_check == false) {
                        if (board[i + k][j - k] == 'K')
                            white_king_check = true;
                        else if (board[i + k][j - k] != '.')
                            break;
                        k++;
                    }

                }
                else if (board[i][j] == 'Q') {
                    unsigned short int k = 1;

                    k = 1;
                    while (i - k >= 0 && black_king_check == false) {
                        if (board[i - k][j] == 'k')
                            black_king_check = true;
                        else if (board[i - k][j] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && black_king_check == false) {
                        if (board[i + k][j] == 'k')
                            black_king_check = true;
                        else if (board[i + k][j] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (j - k >= 0 && black_king_check == false) {
                        if (board[i][j - k] == 'k')
                            black_king_check = true;
                        else if (board[i][j - k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (j + k < CHESS_BOARD_SIZE && black_king_check == false) {
                        if (board[i][j + k] == 'k')
                            black_king_check = true;
                        else if (board[i][j + k] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i - k >= 0 && j - k >= 0 && black_king_check == false) {
                        if (board[i - k][j - k] == 'k')
                            black_king_check = true;
                        else if (board[i - k][j - k] != '.')
                            break;
                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && j + k < CHESS_BOARD_SIZE && black_king_check == false) {
                        if (board[i + k][j + k] == 'k')
                            black_king_check = true;
                        else if (board[i + k][j + k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (i - k >= 0 && j + k < CHESS_BOARD_SIZE && black_king_check == false) {
                        if (board[i - k][j + k] == 'k')
                            black_king_check = true;
                        else if (board[i - k][j + k] != '.')
                            break;

                        k++;
                    }

                    k = 1;
                    while (i + k < CHESS_BOARD_SIZE && j - k >= 0 && black_king_check == false) {
                        if (board[i + k][j - k] == 'k')
                            black_king_check = true;
                        else if (board[i + k][j - k] != '.')
                            break;
                        k++;
                    }

                }

                if (white_king_check == true || black_king_check == true)
                    break;

            }
        }

        if (white_king_check == true)
            cout << "Game #" << game_number << ": white king is in check." << endl;
        else if (black_king_check == true)
            cout << "Game #" << game_number << ": black king is in check." << endl;
        else if (white_king_check == false && black_king_check == false)
            cout << "Game #" << game_number << ": no king is in check." << endl;

        getline(cin, line);
    } while(1);

    return 0;
}


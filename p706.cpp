#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>

#define MAX_S 10
#define MAX_N_DIGITS 8

char output[(2*MAX_S)+3][(MAX_N_DIGITS + 1) + ((MAX_S + 2) * MAX_N_DIGITS)];

using namespace std;

void eight(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        output[size + 1][col + j] = '-';
        output[row_max - 1][col + j] = '-';
    }
}

void zero(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        //output[size + 1][col + j] = '-';
        output[row_max - 1][col + j] = '-';
    }
}

void one(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    /*
    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        output[size + 1][col + j] = '-';
        output[row_max - 1][col + j] = '-';
    }
    */
}

void two(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        output[i][col + 0] = '|';
        //output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        output[size + 1][col + j] = '-';
        output[row_max - 1][col + j] = '-';
    }
}

void three(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        output[size + 1][col + j] = '-';
        output[row_max - 1][col + j] = '-';
    }
}

void four(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        //output[0][col + j] = '-';
        output[size + 1][col + j] = '-';
        //output[row_max - 1][col + j] = '-';
    }
}

void five(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        output[i][col + 0] = '|';
        //output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        output[size + 1][col + j] = '-';
        output[row_max - 1][col + j] = '-';
    }
}

void six(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        output[i][col + 0] = '|';
        //output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        output[size + 1][col + j] = '-';
        output[row_max - 1][col + j] = '-';
    }
}

void seven(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        //output[size + 1][col + j] = '-';
        //output[row_max - 1][col + j] = '-';
    }
}

void nine(unsigned int col, unsigned int size) {
    unsigned int row_max = (2 * size) + 3,
                 col_max = size + 2;

    for (unsigned int i = 1; i < 1 + size; i++) {
        output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }
    for (unsigned int i = size + 2; i < size + 2 + size; i++) {
        //output[i][col + 0] = '|';
        output[i][col + col_max - 1] = '|';
    }

    for (unsigned int j = 1; j < 1 + size; j++) {
        output[0][col + j] = '-';
        output[size + 1][col + j] = '-';
        output[row_max - 1][col + j] = '-';
    }
}

int main(int argc, char* argv[]) {
    do {
        unsigned int size;
        string n;
        unsigned int col = 0;

        cin >> size;
        cin >> n;
        if (size == 0)
            break;

        for (unsigned int i = 0; i < (2*MAX_S)+3; i++) {
            for (unsigned int j = 0; j < (MAX_N_DIGITS + 1) + ((MAX_S + 2) * MAX_N_DIGITS); j++) {
                output[i][j] = ' ';
            }
        }

        for (unsigned int i = 0; i < n.length(); i++) {
            if (n[i] == '0') {
                zero(col, size);
            }
            else if (n[i] == '1') {
                one(col, size);
            }
            else if (n[i] == '2') {
                two(col, size);
            }
            else if (n[i] == '3') {
                three(col, size);
            }
            else if (n[i] == '4') {
                four(col, size);
            }
            else if (n[i] == '5') {
                five(col, size);
            }
            else if (n[i] == '6') {
                six(col, size);
            }
            else if (n[i] == '7') {
                seven(col, size);
            }
            else if (n[i] == '8') {
                eight(col, size);
            }
            else if (n[i] == '9') {
                nine(col, size);
            }
            col += (size + 2);
            col++;
        }

        for (unsigned int i = 0; i < (2 * size) + 3; i++) {
            for (unsigned int j = 0; j < col - 1; j++) {
                cout << output[i][j];
            }
            cout << endl;
        }
        cout << endl;
    } while (1);

    return 0;
}


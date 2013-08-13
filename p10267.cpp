#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 

#define MAX_DIM 250

using namespace std;

char canvas[MAX_DIM][MAX_DIM];
bool visited[MAX_DIM][MAX_DIM];

void clear(unsigned int rows, unsigned int cols) {
    for (unsigned int i = 0; i < rows; i++)
        for (unsigned int j = 0; j < cols; j++)
            canvas[i][j] = 'O';
}

int main(int argc, char* argv[]) {
    unsigned int rows = 0, cols = 0;

    do {
        char command;
        string line;

        getline (cin, line);
        istringstream iss (line);
        iss >> command;

        if (command == 'I') {
            iss >> cols >> rows;
            clear(rows, cols);
        }
        else if (command == 'C') {
            clear(rows, cols);
        }
        else if (command == 'L') {
            unsigned int col, row;
            char color;
            iss >> col >> row >> color;
            row -= 1;
            col -= 1;
            canvas[row][col] = color;
        }
        else if (command == 'V') {
            unsigned int col, row1, row2;
            char color;
            iss >> col >> row1 >> row2 >> color;
            col -= 1;
            row1 -= 1;
            row2 -= 1;
            for (unsigned int i = row1; i <= row2; i++)
                canvas[i][col] = color;
        }
        else if (command == 'H') {
            unsigned int col1, col2, row;
            char color;
            iss >> col1 >> col2 >> row >> color;
            col1 -= 1;
            col2 -= 1;
            row -= 1;
            for (unsigned int j = col1; j <= col2; j++)
                canvas[row][j] = color;
        }
        else if (command == 'K') {
            unsigned int col1, row1, col2, row2;
            char color;
            iss >> col1 >> row1 >> col2 >> row2 >> color;
            col1 -= 1;
            row1 -= 1;
            col2 -= 1;
            row2 -= 1;
            for (unsigned int i = row1; i <= row2; i++)
                for (unsigned int j = col1; j <= col2; j++)
                    canvas[i][j] = color;
        }
        else if (command == 'F') {
            for (unsigned int i = 0; i <= rows; i++)
                for (unsigned int j = 0; j <= cols; j++)
                    visited[i][j] = false;
        }
        else if (command == 'S') {
            string name;
            iss >> name;
            cout << name;
            for (unsigned int i = 0; i <= rows; i++) {
                for (unsigned int j = 0; j <= cols; j++) {
                    cout << canvas[i][j];
                }
                cout << endl;
            }
        }
        else if (command == 'X') {
            break;
        }
    } while (1);

    return 0;
}


#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define MAX_DIM 100

using namespace std;

unsigned int grid[MAX_DIM][MAX_DIM];

int main(int argc, char* argv[]) {
    unsigned int n, m;
    unsigned int i, j;
    unsigned int result, field;
    char ch;

    do {
        cin >> n >> m;
        if (n != 0 && m != 0) {
            if (field > 0)
                cout << endl;
            cout << "Field #" << ++field << ":" << endl;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> ch;
                if (ch == '.')
                    grid[i][j] = 0;
                else
                    grid[i][j] = 1;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                //cout << grid[i][j] << " ";
                if (grid[i][j] == 1) {
                    cout << "*";
                    continue;
                }

                // let's go row-wise
                result = 0;

                if (i > 0) {
                    if (j > 0)
                        result += grid[i - 1][j - 1];
                    result += grid[i - 1][j];
                    if (j < m - 1)
                        result += grid[i - 1][j + 1];
                }
                if (j > 0)
                    result += grid[i][j - 1];
                if (j < m - 1)
                    result += grid[i][j + 1];
                if (i < n - 1) {
                    if (j > 0)
                        result += grid[i + 1][j - 1];
                    result += grid[i + 1][j];
                    if (j < m - 1)
                        result += grid[i + 1][j + 1];
                }
                cout << result;
            }
            cout << endl;
        }
    } while (n != 0 && m != 0);
    return 0;
}


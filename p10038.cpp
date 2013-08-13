#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <string>
#include <cmath>

using namespace std;


int main(int argc, char* argv[]) {
    string line;
    istringstream iss;

    getline(cin, line);
    while (!line.empty()) {
        iss.str(line);

        int n, num1, num2;
        vector<int> diffs;
        bool is_jolly = true;

        iss >> n;

        if (n == 0) {
            is_jolly = false;
        }
        else if (n != 1) {
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    iss >> num1;
                }
                else {
                    iss >> num2;
                    diffs.push_back(abs(num2 - num1));
                    num1 = num2;
                }
            }
            sort(diffs.begin(), diffs.end());
            for (int i = 0; i < diffs.size(); i++) {
                if (diffs[i] != i + 1) {
                    is_jolly = false;
                    break;
                }
            }
        }
        if (is_jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;

        iss.clear();
        getline(cin, line);
    }

    return 0;
}


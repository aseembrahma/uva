#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;

int main(int argc, char* argv[]) {
    string line;
    istringstream iss;

    getline(cin, line);
    if (line.empty())
        return 0;

    iss.str(line);

    unsigned int num_test_cases;
    iss >> num_test_cases;
    iss.clear();

    for (unsigned int i = 0; i < num_test_cases; ++i) {
        int num_days, num_parties, total_hartal_days = 0;
        cin >> num_days;
        vector<bool> hartal_days(num_days, false);
        cin >> num_parties;
        vector<int> hartal_params(num_parties);
        for (int j = 0; j < num_parties; ++j)
            cin >> hartal_params[j];

        sort(hartal_params.begin(), hartal_params.end());

        // Print the input
        /*
        cout << num_days << " days, " << num_parties << " parties." << endl;
        for (int j = 0; j < num_parties; ++j)
            cout << hartal_params[j] << ", ";
        cout << endl;
        */

        // Mark the hartal days
        for (int j = 1; j <= num_days; ++j) {
            if ((j + 1) % 7 == 0 || j % 7 == 0)
                continue;

            for (int k = 0; k < num_parties && hartal_days[j - 1] == false; ++k) {
                if (j % hartal_params[k] == 0) {
                    hartal_days[j - 1] = true;
                    total_hartal_days++;
                }
            }
        }
        cout << total_hartal_days << endl;
    }

    return 0;
}


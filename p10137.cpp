#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>

#define MAX_DIM 100

using namespace std;

int main(int argc, char* argv[]) {
    unsigned int num_students, i;
    double input;

    do {
        cin >> num_students;
        vector<unsigned long long int> values;
        unsigned long long int temp, average, sum = 0, result = 0;
        unsigned long long int first, second;
        unsigned int num_above_avg = 0, left_over;

        for (i = 0; i < num_students; i++) {
            cin >> input;
            input = (input * 100) + 0.5;
            temp = static_cast<unsigned long long int>(input);
            values.push_back(temp);
            sum += temp;
        }
        if (num_students > 0) {
            average = sum / values.size();
            for (size_t i = 0; i < values.size(); i++) {
                if (values[i] > average) {
                    num_above_avg++;
                    result += (values[i] - average);
                }
            }
            left_over = sum % values.size();
            if (left_over != 0) {
                result -= min(left_over, num_above_avg);
            }

            //cout << "$" << setprecision(2) << fixed << result << endl;
            first = result / 100;
            second = result % 100;
            cout << "$" << first << "." << ((second < 10) ? "0" : "") << second << endl;
        }
    } while (num_students != 0);
    return 0;
}


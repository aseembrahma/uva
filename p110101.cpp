#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<unsigned long long int, unsigned long long int> result_store;

unsigned long long int bruteforce(const unsigned long long int& num) {
    unsigned long long int result, n = num;
    map<unsigned long long int, unsigned long long int>::iterator it = result_store.end();
    vector<unsigned long long int> intermediates;

    while ((it = result_store.find(n)) == result_store.end()) {
        intermediates.push_back(n);

        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = (3 * n) + 1;
        }
    }

    result = it->second;
    for (vector<unsigned long long int>::reverse_iterator it2 = intermediates.rbegin();
         it2 != intermediates.rend();
         ++it2) {
        result_store.insert (pair<unsigned long long int, unsigned long long int>(*it2, ++result));
    }
    return result;
}

int main(int argc, char* argv[]) {
    unsigned long long int a, b;
    result_store.insert (pair<unsigned long long int, unsigned long long int>(1, 1));

    //cout << bruteforce(22) << endl;

    while (cin >> a >> b) {
        unsigned long long int max_found = 0;
        unsigned long long int i, temp;
        cout << a << " " << b << " " ;
        if (b < a) {
            temp = b;
            b = a;
            a = temp;
        }
        for (i = a; i <= b; i++) {
            max_found = max(max_found, bruteforce(i));
        }
        cout << max_found << endl;
    }
    return 0;
}


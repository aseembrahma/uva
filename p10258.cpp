#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <string>
#include <cmath>
#include <set>

#define INCORRECT_SUBMISSION_PENALTY 20

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

class Contestant {
    public:
        int id;
        map<int, int> unsolved_problems;
        set<int> solved_problems;
        int final_penalty;

        Contestant() : id(0), final_penalty(0) { }
        Contestant(int contestant_id);
};

Contestant::Contestant(int contestant_id) {
    id = contestant_id;
    final_penalty = 0;
}

bool sort_by_problems_solved(const Contestant &a, const Contestant &b) {
    return a.solved_problems.size() > b.solved_problems.size();
}

bool sort_by_penalty(const Contestant &a, const Contestant &b) {
    return a.final_penalty < b.final_penalty;
}

bool sort_by_id(const Contestant &a, const Contestant &b) {
    return a.id < b.id;
}

int main(int argc, char* argv[]) {
    string line;
    istringstream iss;

    getline(cin, line);
    if (line.empty())
        return 0;

    iss.str(line);
    int num_cases;
    iss >> num_cases;
    iss.clear();

    if (num_cases > 0) {
        // get blank line
        getline(cin, line);

        for (int i = 0; i < num_cases; ++i) {
            map<int, Contestant> contestants;

            while (getline(cin, line) && !line.empty()) {
                iss.str(line);
                int contestant, problem, problem_time;
                char status;
                iss >> contestant >> problem >> problem_time >> status;
                iss.clear();

                if ('R' == status || 'U' == status || 'E' == status)
                    continue;

                map<int, Contestant>::iterator it = contestants.find(contestant);
                if (contestants.end() == it) {
                    Contestant c(contestant);
                    contestants[contestant] = c;
                    it = contestants.find(contestant);
                }
                set<int>::iterator it2 = (it->second).solved_problems.find(problem);
                if ((it->second).solved_problems.end() != it2)
                    continue;

                if ('I' == status) {
                    (it->second).unsolved_problems[problem] += 1;
                }
                else if ('C' == status) {
                    (it->second).solved_problems.insert(problem);
                    (it->second).final_penalty += problem_time;

                    map<int, int>::iterator it3 = (it->second).unsolved_problems.find(problem);
                    if ((it->second).unsolved_problems.end() != it3) {
                        (it->second).final_penalty += (INCORRECT_SUBMISSION_PENALTY) * it3->second;
                        (it->second).unsolved_problems.erase(it3);
                    }
                }
            }

            vector<Contestant> all_contestants;
            for (map<int, Contestant>::iterator it = contestants.begin(); it != contestants.end(); ++it)
                all_contestants.push_back(it->second);
            sort (all_contestants.begin(), all_contestants.end(), sort_by_problems_solved);
            sort (all_contestants.begin(), all_contestants.end(), sort_by_penalty);
            sort (all_contestants.begin(), all_contestants.end(), sort_by_id);

            for (vector<Contestant>::iterator it = all_contestants.begin(); it != all_contestants.end(); ++it)
                cout << (*it).id << " " << (*it).solved_problems.size() << " " << (*it).final_penalty << endl;

            if (i != num_cases - 1)
                cout << endl;
        }
    }
    return 0;
}


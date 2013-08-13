#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    int num_cases;
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> num_cases;
    iss.clear();

    getline(cin, line);

    for (int i = 0; i < num_cases; i++) {
        vector<vector<int> > votes;
        vector<string> candidates;
        int num_candidates;

        getline(cin, line);
        iss.str(line);
        iss >> num_candidates;
        iss.clear();

        for (int j = 0; j < num_candidates; j++) {
            getline(cin, line);
            candidates.push_back(line);
        }

        getline(cin, line);
        while (!line.empty()) {
            vector<int> current_vote;
            vector<int> temp_vote;
            int vote;

            iss.str(line);
            while (iss >> vote) {
                current_vote.push_back(vote);
                temp_vote.push_back(vote);
            }
            iss.clear();

            sort (temp_vote.begin(), temp_vote.end());
            bool vote_is_valid = true;
            if (temp_vote.size() != num_candidates) {
                vote_is_valid = false;
            }
            else {
                for (int k = 0; k < temp_vote.size(); k++) {
                    if (temp_vote[k] != k+1) {
                        vote_is_valid = false;
                        break;
                    }
                }
            }
            if (true == vote_is_valid)
                votes.push_back(current_vote);
            getline(cin, line);
        }

        //cout << "Num candidates: " << num_candidates << endl;
        //for (vector<string>::iterator it = candidates.begin(); it != candidates.end(); it++)
        //    cout << "Candidate: " << *it << endl;

        //for (vector<vector<int> >::iterator it = votes.begin(); it != votes.end(); it++) {
        //    cout << "Vote: ";
        //    for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
        //        cout << *it2 << ", ";
        //    cout << endl;
        //}

        if (votes.size() == 0)
            continue;

        vector<bool> eliminated(num_candidates, false);
        while (true) {
            vector<int> vote_count(num_candidates, 0);
            for (size_t j = 0; j < votes.size(); j++) {
                for (size_t k = 0; k < votes[j].size(); k++) {
                    if (eliminated[votes[j][k] - 1] == false) {
                        vote_count[votes[j][k] - 1]++;
                        break;
                    }
                }
            }

            vector<int>::iterator max_vote_count_it = max_element(vote_count.begin(), vote_count.end());

            int min_vote_count = *max_vote_count_it;
            for (size_t j = 0; j < vote_count.size(); j++) {
                if (false == eliminated[j] && vote_count[j] < min_vote_count)
                    min_vote_count = vote_count[j];
            }

            //debug prints
            //for (size_t j = 0; j < vote_count.size(); j++) {
            //    cout << vote_count[j] << ", ";
            //}
            //cout << endl << "max: " << *max_vote_count_it << ", min: " << min_vote_count << endl;

            if ((((*max_vote_count_it) * 100) / votes.size()) > 50) {
                // We have a winner
                // print the name and exit
                cout << candidates[max_vote_count_it - vote_count.begin()] << endl;
                break;
            }
            else if (*max_vote_count_it == min_vote_count) {
                // We have a tie
                // print names of all non-eliminated candidates and exit
                for (vector<bool>::iterator it = eliminated.begin(); it != eliminated.end(); ++it)
                    if (*it == false)
                        cout << candidates[it - eliminated.begin()] << endl;
                break;
            }
            else {
                // We do not have a majority
                // Remove everyone with the lowest vote
                for (size_t j = 0; j < vote_count.size(); j++) {
                    if (vote_count[j] == min_vote_count)
                        eliminated[j] = true;
                }
            }
        }
        if (i != num_cases - 1)
            cout << endl;
    }

    return 0;
}


#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <string>
#include <cmath>

#define NUM_CARDS_IN_DECK 52
#define NUM_SUITS 4
#define NUM_CARDS_IN_SUIT 13

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

string cardToString(int card) {
    // Clubs, Diamonds, Hearts, Spades
    // 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace
    int suit = (card - 1) / NUM_CARDS_IN_SUIT;
    int value = (card - 1) % NUM_CARDS_IN_SUIT;

    string card_string;
    if (0 == value)
        card_string = "2";
    else if (1 == value)
        card_string = "3";
    else if (2 == value)
        card_string = "4";
    else if (3 == value)
        card_string = "5";
    else if (4 == value)
        card_string = "6";
    else if (5 == value)
        card_string = "7";
    else if (6 == value)
        card_string = "8";
    else if (7 == value)
        card_string = "9";
    else if (8 == value)
        card_string = "10";
    else if (9 == value)
        card_string = "Jack";
    else if (10 == value)
        card_string = "Queen";
    else if (11 == value)
        card_string = "King";
    else if (12 == value)
        card_string = "Ace";

    if (0 == suit)
        card_string += " of Clubs";
    else if (1 == suit)
        card_string += " of Diamonds";
    else if (2 == suit)
        card_string += " of Hearts";
    else if (3 == suit)
        card_string += " of Spades";

    return card_string;
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
    //cout << "# Cases: " << num_cases << endl;

    if (num_cases > 0) {
        // get blank line
        getline(cin, line);

        for (int i = 0; i < num_cases; ++i) {
            getline(cin, line);
            iss.str(line);
            int num_shuffles;
            iss >> num_shuffles;
            iss.clear();

            vector<int> cards(NUM_CARDS_IN_DECK);
            for (int j = 1; j <= NUM_CARDS_IN_DECK; ++j)
                cards[j - 1] = j;

            if (num_shuffles > 0) {
                vector<vector<int> > shuffles(num_shuffles);
                for (int j = 0; j < num_shuffles; ++j) {
                    int cards_read = 0;
                    do {
                        getline(cin, line);
                        iss.str(line);
                        int temp;
                        while (iss >> temp) {
                            shuffles[j].push_back(temp);
                            ++cards_read;
                        }
                        iss.clear();
                    } while (cards_read < NUM_CARDS_IN_DECK);
                }

                //cout << "# Shuffles: " << num_shuffles << endl;
                /*
                for (int j = 0; j < num_shuffles; ++j) {
                    for (int k = 0; k < NUM_CARDS_IN_DECK; ++k) {
                        cout << shuffles[j][k] << ", ";
                    }
                    cout << endl;
                }
                */

                while (getline(cin, line) && !line.empty()) {
                    iss.str(line);
                    int shuffle_id;
                    iss >> shuffle_id;
                    iss.clear();

                    // cout << "Shuffle ID: " << shuffle_id << endl;
                    --shuffle_id;

                    vector<int> new_deck(NUM_CARDS_IN_DECK);
                    for (int j = 0; j < NUM_CARDS_IN_DECK; ++j) {
                        new_deck[j] = cards[shuffles[shuffle_id][j] - 1];
                    }
                    cards = new_deck;
                }
            }
            // print out the final deck of cards
            for (int j = 0; j < NUM_CARDS_IN_DECK; ++j)
                cout << cardToString(cards[j]) << endl;
            
            if (i != num_cases - 1) {
                cout << endl;
            }
        }
    }

    return 0;
}


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

#define NUM_CARDS_PER_HAND 5

int cardValueToInt(char card_value) {
    if (card_value == 'A')
        return 14;
    else if (card_value == 'K')
        return 13;
    else if (card_value == 'Q')
        return 12;
    else if (card_value == 'J')
        return 11;
    else if (card_value == 'T')
        return 10;
    else
        return card_value - '0';
}

bool sortByValueDesc(const string &a, const string &b) {
    if (cardValueToInt(a[0]) >= cardValueToInt(b[0]))
        return true;
    else return false;
}

int categorizeHand(const vector<string> &cards, const map<int, int> card_map, bool all_same_suit, vector<int> &comparison_vector) {
    bool two_of_same_val = false, three_of_same_val = false, four_of_same_val = false;
    bool two_more_of_same_val = false;
    int two_value, three_value, four_value;
    int two_more_value;
    bool consecutive_values = true;

    for (size_t i = 1; i < cards.size(); ++i) {
        if (cardValueToInt(cards[i - 1][0]) - cardValueToInt(cards[i][0]) != 1) {
            consecutive_values = false;
            break;
        }
    }

    for (map<int,int>::const_iterator it = card_map.begin(); it != card_map.end(); ++it) {
        if (4 == it->second) {
            four_of_same_val = true;
            four_value = it->first;
        }
        else if (3 == it->second) {
            three_of_same_val = true;
            three_value = it->first;
        }
        else if (2 == it->second) {
            if (two_of_same_val == false) {
                two_of_same_val = true;
                two_value = it->first;
            }
            else {
                two_more_of_same_val = true;
                two_more_value = it->first;
            }
        }
    }

    // 1. Staight flush
    if (all_same_suit && consecutive_values) {
        comparison_vector.push_back(cardValueToInt(cards[0][0]));
        return 1;
    }

    // 2. Four of a kind
    if (four_of_same_val) {
        comparison_vector.push_back(four_value);
        return 2;
    }

    //3. Full House
    if (three_of_same_val && two_of_same_val) {
        comparison_vector.push_back(three_value);
        return 3;
    }

    // 4. Flush
    if (all_same_suit) {
        for (size_t i = 0; i < cards.size(); ++i) {
            comparison_vector.push_back(cardValueToInt(cards[i][0]));
        }
        return 4;
    }

    // 5. Straight
    if (consecutive_values) {
        comparison_vector.push_back(cardValueToInt(cards[0][0]));
        return 5;
    }

    // 6. Three of a kind
    if (three_of_same_val) {
        comparison_vector.push_back(three_value);
        return 6;
    }

    // 7. Two pairs
    if (two_of_same_val && two_more_of_same_val) {
        comparison_vector.push_back(two_value);
        comparison_vector.push_back(two_more_value);
        for (size_t i = 0; i < cards.size(); ++i) {
            int val = cardValueToInt(cards[i][0]);
            if (val != two_value && val != two_more_value) {
                comparison_vector.push_back(val);
            }
        }
        return 7;
    }

    if (two_of_same_val) {
        comparison_vector.push_back(two_value);
        for (size_t i = 0; i < cards.size(); ++i) {
            int val = cardValueToInt(cards[i][0]);
            if (val != two_value) {
                comparison_vector.push_back(val);
            }
        }
        return 8;
    }

    for (size_t i = 0; i < cards.size(); ++i) {
        comparison_vector.push_back(cardValueToInt(cards[i][0]));
    }
    return 9;
}

int breakTie(int category, vector<int> &black_comparison, vector<int> &white_comparison) {
    for (size_t i = 0; i < black_comparison.size(); ++i) {
        if (black_comparison[i] > white_comparison[i]) {
            return 1;
        }
        else if (black_comparison[i] < white_comparison[i]) {
            return -1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    string line;
    istringstream iss;

    getline(cin, line);
    while (!line.empty()) {
        iss.str(line);

        vector<string> black_cards;
        vector<string> white_cards;
        map<int, int> black_map;
        map<int, int> white_map;
        bool black_all_same_suit = true, white_all_same_suit = true;

        string temp;

        char suit = ' ';
        for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
            iss >> temp;
            black_cards.push_back(temp);
            black_map[cardValueToInt(temp[0])]++;
            if (i == 0) {
                suit = temp[1];
            }
            else {
                if (black_all_same_suit) {
                    if (temp[1] != suit)
                        black_all_same_suit = false;
                }
            }
        }
        for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
            iss >> temp;
            white_cards.push_back(temp);
            white_map[cardValueToInt(temp[0])]++;
            if (i == 0) {
                suit = temp[1];
            }
            else {
                if (white_all_same_suit) {
                    if (temp[1] != suit)
                        white_all_same_suit = false;
                }
            }
        }
        sort (black_cards.begin(), black_cards.end(), sortByValueDesc);
        sort (white_cards.begin(), white_cards.end(), sortByValueDesc);

        
        // Print sorted hands
        /*
        for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
            cout << black_cards[i] << ", ";
        }
        cout << endl;
        for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
            cout << white_cards[i] << ", ";
        }
        cout << endl;
        cout << endl;
        for (map<int,int>::iterator it = black_map.begin(); it != black_map.end(); ++it)
            cout << it->first << " => " << it->second << ", ";
        cout << endl;
        for (map<int,int>::iterator it = white_map.begin(); it != white_map.end(); ++it)
            cout << it->first << " => " << it->second << ", ";
        cout << endl;
        cout << endl;
        if (black_all_same_suit == true)
            cout << "black all same suit!" << endl;
        if (white_all_same_suit == true)
            cout << "white all same suit!" << endl;
        */


        vector<int> black_comparison_vector;
        vector<int> white_comparison_vector;
        int category_black = categorizeHand(black_cards, black_map, black_all_same_suit, black_comparison_vector);
        int category_white = categorizeHand(white_cards, white_map, white_all_same_suit, white_comparison_vector);

        if (category_black < category_white) {
            cout << "Black wins." << endl;
        }
        else if (category_white < category_black) {
            cout << "White wins." << endl;
        }
        else {
            int retval = breakTie(category_black, black_comparison_vector, white_comparison_vector);
            if (1 == retval)
                cout << "Black wins." << endl;
            else if (-1 == retval)
                cout << "White wins." << endl;
            else
                cout << "Tie." << endl;
        }

        iss.clear();
        getline(cin, line);
    }

    return 0;
}


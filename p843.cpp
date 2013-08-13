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

bool word_match(string &word, string &dict_word, map<char, char> &mapping, map<char, char> &rev_mapping) {

    map<char, char> cur_mapping;
    map<char, char> cur_rev_mapping;

    if (word.length() != dict_word.length())
        return false;

    //if (word.length() == 2) {
        //cout << "Comparing " << word << " with " << dict_word << endl;
    //}

    for (size_t k = 0; k < word.length(); ++k) {
        map<char, char>::iterator it1 = mapping.find(word[k]);
        map<char, char>::iterator it2 = rev_mapping.find(dict_word[k]);

        // if it is already present in the mapping and conflicts then quit
        if (mapping.end() != it1 && it1->second != dict_word[k]) {
            return false;
        }
        if (rev_mapping.end() != it2 && it2->second != word[k]) {
            return false;
        }

        map<char, char>::iterator it3 = cur_mapping.find(word[k]);
        map<char, char>::iterator it4 = cur_rev_mapping.find(dict_word[k]);

        // if it is already present in the mapping and conflicts then quit
        if (cur_mapping.end() != it3 && it3->second != dict_word[k]) {
            return false;
        }
        if (cur_rev_mapping.end() != it4 && it4->second != word[k]) {
            return false;
        }

        if (mapping.end() == it1 && cur_mapping.end() == it3) {
            cur_mapping[word[k]] = dict_word[k];
        }
        if (rev_mapping.end() == it2 && cur_rev_mapping.end() == it4) {
            cur_rev_mapping[dict_word[k]] = word[k];
        }
    }
    //if (word.length() == 2)
        //cout << "found match" << endl;

    // merge into main map
    mapping.insert(cur_mapping.begin(), cur_mapping.end());
    rev_mapping.insert(cur_rev_mapping.begin(), cur_rev_mapping.end());

    /*
    for (map<char, char>::iterator it = mapping.begin(); it != mapping.end(); ++it)
        cout << it->first << ": " << it->second << ", ";
    cout << endl;
    */

    return true;
}

bool match(vector<string> &dict, vector<string> &words, size_t word_num, map<char, char> &mapping, map<char, char> &rev_mapping) {
    map<char, char> cur_mapping(mapping);
    map<char, char> cur_rev_mapping(rev_mapping);

    for (size_t j = 0; j < dict.size(); ++j) {
        if (word_match(words[word_num], dict[j], cur_mapping, cur_rev_mapping)) {

            if (word_num == words.size() - 1 ||
                match(dict, words, word_num + 1, cur_mapping, cur_rev_mapping)) {

                /*
                cout << "Outer1. ";
                for (map<char, char>::iterator it = cur_mapping.begin(); it != cur_mapping.end(); ++it)
                    cout << it->first << ": " << it->second << ", ";
                cout << endl;
                */

                // merge into main map
                mapping.insert(cur_mapping.begin(), cur_mapping.end());
                rev_mapping.insert(cur_rev_mapping.begin(), cur_rev_mapping.end());

                /*
                cout << "Outer2. ";
                for (map<char, char>::iterator it = mapping.begin(); it != mapping.end(); ++it)
                    cout << it->first << ": " << it->second << ", ";
                cout << endl;
                */

                return true;
            }
            else {
                cur_mapping = mapping;
                cur_rev_mapping = rev_mapping;
            }
        }
    }
    return false;
}

bool string_length_sort(const string &a, const string &b) {
    return a.length() > b.length();
}

int main(int argc, char* argv[]) {
    string line;
    istringstream iss;

    getline(cin, line);
    if (line.empty())
        return 0;

    iss.str(line);
    int dict_size;
    iss >> dict_size;
    iss.clear();

    if (dict_size > 0) {
        vector<string> dict(dict_size);

        for (int i = 0; i < dict_size; ++i)
            getline(cin, dict[i]);
        stable_sort(dict.begin(), dict.end(), string_length_sort);

        /*
        cout << "Dict is : ";
        for (size_t i = 0; i < dict.size(); ++i)
            cout << dict[i] << ", ";
        cout << endl;
        */

        while(getline(cin, line)) {
            if (!line.empty()) {
                vector<string> words = split(line, ' ');
                stable_sort(words.begin(), words.end(), string_length_sort);

                /*
                cout << "Words in sentence are: ";
                for (size_t i = 0; i < words.size(); ++i)
                    cout << words[i] << ", ";
                cout << endl;
                */

                //  For each word in the sentence
                //      For each word in the dictionary
                //          If the dictionary word length equals the sentence word length
                //              extract this mapping. if it is a conflicted mapping, reset the mapping

                map<char, char> mapping; // mapping of ciphertext to plaintext
                map<char, char> rev_mapping; // mapping of plaintext to ciphertext 
                bool retval = match(dict, words, 0, mapping, rev_mapping);

                /*
                if (retval)
                    for (map<char, char>::iterator it = mapping.begin(); it != mapping.end(); ++it)
                        cout << it->first << ": " << it->second << ", ";
                */


                for (size_t i = 0; i < line.length(); ++i) {
                    if (line[i] == ' ') {
                        cout << ' ';
                    }
                    else {
                        if (retval)
                            cout << mapping[line[i]];
                        else
                            cout << "*";
                    }
                }
                cout << endl;
            }
            else {
                cout << endl;
            }
        }
    }

    return 0;
}


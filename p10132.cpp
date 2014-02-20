#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <iomanip>
#include <sstream> 
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <limits>
#include <numeric>
#include <bitset>
#include <iterator>

#define DEBUG 0

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

template <typename K, typename V>
V GetWithDef(const  std::map <K,V> & m, const K & key, const V & defval ) {
    typename std::map<K,V>::const_iterator it = m.find( key );
    if ( it == m.end() ) {
        return defval;
    }
    else {
        return it->second;
    }
}

void reset() {
}

bool check(vector<string> v, const string &str)
{
  if (v.size() == 0) {
    return true;
  }

  for (size_t i = v.size() - 1; i > 0; i--) {
    if ((v[0] + v[i] == str) || (v[i] + v[0] == str)) {
      vector<string> tempv(v);
      tempv.erase(tempv.begin() + 0);
      tempv.erase(tempv.begin() + i);
      return check(tempv, str);
    }
  }
  return false;
}

string solve(vector<string> &fragments)
{
  size_t min_length = fragments[0].size(),
         max_length = fragments[fragments.size() - 1].size();

  for (size_t i = 0; fragments[i].size() == min_length; i++) {
    for (size_t j = fragments.size() - 1;
        fragments[j].size() == max_length;
        j--) {
      string temp_str;
      temp_str = fragments[i] + fragments[j];
      if (check(fragments, temp_str)) return temp_str;
      temp_str = fragments[j] + fragments[i];
      if (check(fragments, temp_str)) return temp_str;
    }
  }
  return "";
}

bool sort_str_by_len(const string &s1, const string &s2)
{
  return s1.length() < s2.length();
}

int main(int argc, char* argv[]) {
  string line;
  istringstream iss;
  size_t num_cases = 0;

  getline(cin, line);
  iss.str(line);
  iss >> num_cases;
  iss.clear();

  getline(cin, line);

  for (size_t i = 0; i < num_cases; ++i) {

    vector<string> fragments;
    size_t file_length = 0, num_fragments = 0, num_strings = 0;

    getline(cin, line);
    while (line.length() > 0) {
      file_length += line.length();
      num_fragments++;
      fragments.push_back(line);
      getline(cin, line);
    }

    num_strings = num_fragments / 2;
    file_length /= num_strings;

    sort(fragments.begin(), fragments.end(), sort_str_by_len);
    cout << solve(fragments) << endl;
    if (i != num_cases - 1)
      cout << endl;
  }

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

  // lets sort the strings , when we sort both anagrams, thye will have same value.
  // like tan, nat after sorting both become ant. sort each string and store it hashmap
  // this will take m*nlogn because of sorting -> it took 15ms
  // vector<vector<string>> groupAnagrams(vector<string>& strs) {
  //   unordered_map<string, vector<string>> res;
  //   for ( auto s : strs) {
  //     string sortedS = s;
  //     sort(sortedS.begin(), sortedS.end());
  //     res[sortedS].push_back(s);
  //   }

  //   vector<vector<string>> result;
  //   for (auto pair : res) {
  //     result.push_back(pair.second);
  //   }
  //   return result;
  // }

  //Lets use hashtable -> this is much slower than sorting it took 77ms 

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> res; // can't use vector as key as it is not hashable only primitives like int, float , char and only class like string can be used as string.

    for (auto s : strs) {
      vector<int> count(26, 0);

      for (char x : s) {count[x - 'a']++;} // to get index 
      // converting hashtable as string and storing it as key
      string key;
      for (int i = 0; i < 26; i++) {
        key += "," + to_string(count[i]);
      }
      cout << key << endl;
      res[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto pair : res) {
      result.push_back(pair.second);
    }

    return result;
  }


};

int main() {
  Solution s;
  vector<string> strs = { "bdddddddddd","bbbbbbbbbbc" };
  vector<vector<string>> result = s.groupAnagrams(strs);

  for (auto& x : result) {
    for (auto& y : x) {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}
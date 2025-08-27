#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // we can sort both the strings and see if both or same. 
  // cause anagram means same number of characters rearranged to form a different word.
  // as sorting will take nlogn time this will take nlogn + mlogm time

  // bool isAnagram(string s, string t) {
  //   if (s.length() != t.length()) return false; // for anagram both string length must be same if not exit with false.

  //   sort(s.begin(), s.end());
  //   sort(t.begin(), t.end());

  //   return s == t; // this will return true if both strings are same else false.
  // }

  // using Hash map

  // bool isAnagram(string s, string t) {
  //   if (s.length() != t.length()) return false;

    // create hash map for both strings to count the characters in each string.
    // unordered_map<char, int> countS;
    // unordered_map<char, int> countT;
    // for (int i = 0; i < s.length(); i++) {
    //   countS[s[i]]++;
    //   countT[t[i]]++;
    // }
    // return countS == countT;
  // }

  // using Hash Table this one is crazy. so we take a array of 26 elements and fill it with zeros
  // we will increase the value of char found in string s by one and decrease the value of char found in stirng t by one.
  // at the end the array should contain all zeros if both strings are same 

  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> v(26, 0);
    for (int i = 0; i < s.length(); i++) {
      v[s[i] - 'a']++; // to get index in range of 0-26 , 
      // 'a' has ascii value of 97 so if the letter is b then it is 98-97 which will give 1. 
      v[t[i] - 'a']--;
    }

    for (int x : v) {
      if (x != 0) {
        return false;
      }
    }
    return true;
  }

};

int main() {
  Solution s;

  cout << s.isAnagram("anagram", "nagaram") << endl;
  cout << s.isAnagram("rat", "car") << endl;

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

  // written on my own :) not efficient yet super satisfying cause this a medium problem.  it took 6ms 
  // vector<int> topKFrequent(vector<int>& nums, int k) {
  //   unordered_map<int, int> freq; // hashmap to count the frequency of each integer.

  //   for (int x : nums) {
  //     freq[x]++;
  //   }
  //   vector<int> res(k, 0);
  //   int maxValue = 0;
  //   int maxKey = 0;

  //   for (int i = 0; i < k; i++) { // this is where i think we can improve efficiency cause this will take n+k*freq. if k and freq have same size that means it is O(n*n) 
  //     cout << freq.size() << endl;
  //     for (auto pair : freq) {
  //       if (pair.second > maxValue) {
  //         maxValue = pair.second;
  //         maxKey = pair.first;
  //       }
  //     }
  //     res[i] = maxKey;
  //     freq.erase(maxKey); // this will reduce the loop of freq cause i am deleteing the element.
  //     maxValue = 0;
  //   }

  //   return res;
  // }


  // Lets store pairs in vector and sort it. instead of looping.  this one took 7ms.


  // vector<int> topKFrequent(vector<int>& nums, int k) {
  //   unordered_map<int, int> freq;

  //   for (int num : nums) freq[num]++;

  //   vector<pair<int, int>> count; // array of pairs nice.

  //   for (auto pair : freq) {
  //     count.push_back({ pair.second, pair.first });
  //   }

  //   sort(count.rbegin(), count.rend()); // this will sort in descending order

  //   vector<int> res(k, 0);
  //   for (int i = 0; i < k; i++) res[i] = count[i].second;
  //   return res;
  // }


  // this sort took only 1ms 
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> numFreq;

    for (auto& num : nums) {
      numFreq[num]++;
    }

    vector<pair<int, int>> numFreqVec;

    for (auto& [key, val] : numFreq) {
      numFreqVec.push_back({ key, val });
    }

    sort(numFreqVec.begin(), numFreqVec.end(),
      [](const pair<int, int> a, const pair<int, int> b) { return a.second > b.second; }); //custom sort using lambda.

    vector<int> result;

    for (int i = 0; i < k; i++) {
      result.push_back(numFreqVec[i].first);
    }

    return result;
  }

 // we can achieve better efficiency using min Heap / priority_queue 
};


int main() {
  Solution s;
  vector<int> v = { 1,1,1,2,2,3,5,5,5,5,5,5,5 };
  int k = 3;
  vector<int> res = s.topKFrequent(v, k);

  for (int x : res) cout << x << ',';

  return 0;
}
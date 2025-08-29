#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

  // brute force method, checking if the sum of 2 elements are equal to target at every index, 
  // this will take n*n time not efficent but  gets the work done.

  // vector<int> twoSum(vector<int>& nums, int target) {
  //   for (int i = 0; i < nums.size(); i++) {
  //     for (int j = i + 1; j < nums.size(); j++) {
  //       if (nums[i] + nums[j] == target) {
  //         return { i,j };
  //       };
  //     }
  //   }
  //   return {};
  // }

  //Hash map 

  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashMap; // will map the value to index
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (hashMap.find(diff) != hashMap.end()) { // find return an iterator with key value pair if its found or else it will return .end() 
        return { hashMap[diff], i };
      }
      // hashMap.insert({nums[i], i}); 
      // you can also insert directly as below instead of using insert method. for some reason when used insert it took 1ms more 
      hashMap[nums[i]] = i;
    }
    return {};
  }

};

int main() {
  vector<int> nums = { 2,11,15,7 };
  int target = 17;
  Solution s;
  vector<int> res = s.twoSum(nums, target);

  for (int x : res) {
    cout << x << ",";
  }
  cout << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // sort is present in this header

using namespace std;

class Solution {
public:
  // this is bruteforce, 
  // means checking every value in array from the index i am standing at to see if there are any duplicates
  // This will take n square time , not efficient

  // bool containsDuplicate(vector<int>& nums) {
  //   for (int i = 0; i < nums.size(); i++) {       // current index
  //     for (int j = i + 1; j < nums.size(); j++) { // check all other elements 
  //       if (nums[i] == nums[j]) return true;      // return true if you find the duplicate
  //     }
  //   }
  //   return  false;
  // } 

  // we can sort and check if any continous numbers are same. this will take nlogn time. 

  // bool containsDuplicate(vector<int>& nums) {
  //   sort(nums.begin(), nums.end());
  //   for (int i = 1; i<nums.size(); i++ ){
  //     if(nums[i] == nums[i-1]) return true;
  //   }
  //   return false;
  // }

  // now we use hashset, hashset count will return 1 if the element already exists
  // if the num is not present we will insert in the set. #this takes order of n time. 
  // for some reason below code is fast in leetcode 

  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
      if (seen.count(num)) return true;
      seen.insert(num);
    }
    return false;
  }

  // hashset will not contain duplicate , 
  // we can create hashset with vector nums, if the length of hashset is less than vector then we have duplicate.
  // this will also take order of n time. 

  // bool containsDuplicate(vector<int>& nums) {
  //   return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
  // }


};

int main() {

  Solution s;
  vector<int> nums = { 1,2,3,1 };

  cout << s.containsDuplicate(nums) << endl;
}
#include <bits/stdc++.h>

using namespace std;

class Solution {
  void ms(vector<int> &arr , int low , int high){
    if(low == high) return;
    int mid = (low+high)/2;
    ms(arr, low ,mid);
    ms(arr, mid+1 , high);
    merge(arr , low , mid , high);
  }

  void merge(vector<int> &arr , int low , int mid , int high){
    vector<int> temp ;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high ){
      if(arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      }else{
        temp.push_back(arr[right]);
        right++;
      }
    }

    while(left <= mid){
      temp.push_back(arr[left]);
      left++;
    }

    while(right <= high){
      temp.push_back(arr[right]);
      right++;
    }

    for(int i=low ; i <= high; i++ ){
      arr[i] = temp[i-low];
    }
  }

  void qs(vector<int> &arr , int low , int high){
    if(low < high){
      int pIndex = qsPartition(arr , low , high);
      qs(arr , low , pIndex-1);
      qs(arr, pIndex+1 , high);
    }
  }

  int qsPartition(vector<int> &arr , int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
      while(arr[i] <= pivot && i < high){ // this will give the first number that is greater than pivot
        i++;
      }
      while(arr[j] > pivot && j > low){ // this will give the first number that is less than pivot , cause it will move the index as long as it is great.
        j--;
      }
      if(i < j) swap(arr[i] , arr[j]);
    }

    swap(arr[low] , arr[j]);
    return j;
  }

public:
  vector<int> selectionSort(vector<int>& nums) {
    for(int i=0; i<nums.size()-1; i++){
      int minIndex = i;
      for(int j=i; j<nums.size(); j++){
        if(nums[j] < nums[minIndex]) minIndex = j;
      }
      if(minIndex != i){
        swap(nums[i], nums[minIndex]);
      }
    }
    return nums;
  }

  vector<int> bubbleSort(vector<int> &nums){
    for(int i=nums.size()-1 ; i>= 1 ;i--){
      int hasSwapped = 0;
      for(int j=0; j<nums.size()-1; j++){ //as we are not using j<=nums.size()-1 it will go only till nums.size()-2
        if(nums[j] > nums[j+1]){
          swap(nums[j], nums[j+1]);
          hasSwapped = 1;
        }
      }
      if(hasSwapped == 0) break; // if the given array is sorted it will just take O(n) time only with this optimization.
    }
    return nums;
  }

  vector<int> insertionSort(vector<int> &nums) {
    for(int i=0; i<nums.size(); i++){
      int j=i;
      while(j>0 && nums[j-1] > nums[j]){
        int temp = nums[j-1];
        nums[j-1] = nums[j];
        nums[j] = temp;
        j--;
      }
    }
    return nums;
  }

  vector<int> mergeSort(vector<int> &nums){
    int n = nums.size();
    ms(nums , 0 , n);
    return nums;
  }

  vector<int> quickSort(vector<int> &nums){
    qs(nums , 0 , nums.size()-1);
    return nums;
  }
};

int main() {
  vector<int> nums = { 6 , 5, 4, 3, 2 ,1};
  Solution s;
  s.quickSort(nums);
  for(int x : nums){
    cout << x << " " ;
  }


  return 0;
}
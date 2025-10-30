#include <bits/stdc++.h>

using namespace std;

void explainPair() {
  pair<int, int> pr1 = { 2,8 };
  cout << pr1.first << " " << pr1.second << endl;

  pair<int, char> pr2 = { 2, 'b' };
  cout << pr2.first << " " << pr2.second << endl;

  pair<pair<int, char>, int> pr3 = { {2 , 'k'}, 4 };
  cout << pr3.first.first << " " << pr3.first.second << " " << pr3.second << endl;

}
void explainVector() {
  vector<int> vec = { 7, 8 ,2 };

  vec.insert(vec.begin() + 3, 1);

  // creating vec using other vec .  noish
  // vector<int> dupVec(vec.rbegin() , vec.rend());
  // for(auto x : dupVec) {
  //   cout << x << " ";
  // }

  // Iterators
  // vector<int>::iterator beginItr = vec.begin(); -> we have rbegin() and rend() iterators as well.
  // auto endItr =vec.end(); 

  for (int x : vec) {
    cout << x << " ";
  }
}
void explainList() {
  list<int> ls = { 2,3 };
  ls.push_front(2);

  cout << *ls.begin() + 1 << endl;

  // we cannot acceess elements like ls[1] , because list and deque both are under the hood linked lists.

}
void explainStack() {
  // LIFO -> Last In First Out. 
  stack<int> st;
  st.push(1);
  st.push(7);
  st.push(71);
  st.push(72);
  st.push(73);

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}
void explainQueue() {
  // FIFO 
  queue<int> q;
  q.push(2);
  q.push(3);
  q.push(4);

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
}
void explainPQ() {
  //stores highest element at the top
  priority_queue<int> pq;
  pq.push(5);
  pq.push(8);
  pq.push(10);
  pq.push(2);

  cout << pq.top() << endl;

  //stores smallest element at the top - min Heap
  priority_queue<int, vector<int>, greater<int>> p2;
  p2.push(4);
  p2.push(3);
  p2.push(6);
  p2.push(10);
  cout << p2.top() << endl;
}
void explainSet() {
  set<int> s;
  s.insert(10);
  s.insert(1);
  s.insert(100);
  s.insert(10);

  auto it = s.lower_bound(10);
  auto i2 = s.upper_bound(10);
  cout << *it << endl;
  cout << *i2 << endl;
}
void explainMultiset() {
  multiset<int> ms;
  ms.insert(1);
  ms.insert(0);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(2);
  auto it = ms.erase(1);
  for (auto i : ms) {
    cout << i << " ";
  }
}
void explainUnorderedset() {
  unordered_set<int> st;
  st.insert(1);
  st.insert(12);
  st.insert(2);
  st.insert(1);
  st.insert(12);

  auto it = st.find(2);
  cout << *it << " ";
}
void explainMap() {
  map<int, string> mp;
  mp[1] = "kv";
  mp[2] = "vk";
  mp.insert({ 3,"kk" });

  auto it = mp.find(3); // time complexity i O(logn)

  cout << (*it).first << " " << (*it).second << endl;
}
void explainUnorderedmap() {
  unordered_map<int, string> mp;
  mp[1] = "kv";
  mp[2] = "vk";
  mp.insert({ 3,"kk" });

  auto it = mp.find(3); // time complexity i O(1)

  cout << (*it).first << " " << (*it).second << endl;
}
void explainMultimap() {
  multimap<int, string> mp;
  mp.insert({ 2,"kv" });
  mp.insert({ 2,"vk" });
  mp.insert({ 3,"vk" });
  mp.insert({ 23,"kv" });
  mp.insert({ 24,"kv" });
  mp.insert({ 2,"kk" });

  auto it = mp.equal_range(2);
  for (auto i = it.first; i != it.second; i++) {
    cout << (*i).first << " " << (*i).second << endl;
  }
}
void explainSort() {
  int arr[5] = { 5, 6 ,7, 3, 2 };
  sort(arr, arr + 5);
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;

  vector<int> vec = { 5, 6 ,7, 3, 2 };
  sort(vec.begin(), vec.end());
  for (auto x : vec) {
    cout << x << " ";
  }
}
void explainAccumulate() {
  int arr[5] = { 1,2,3,4,5 };
  cout << accumulate(arr, arr + 5, 5) << endl;
}
void explainCount() {
  int arr[5] = { 1,2,3,1,5 };
  cout << count(arr, arr + 5, 2) << endl;
}
void explainFind() {
  int arr[5] = { 1,2,3,1,5 };
  auto it = find(arr, arr + 5, 1);
  cout << *it << endl;
}
void explainNextpermutation() {
  string str = "bca";
  do {
    cout << str << endl;
  } while (next_permutation(str.begin(), str.end())); // we can use prev_permutation 
}

bool internalCompartor(pair<int, int> el1 , pair<int, int> el2) {
  if(el1.second > el2.second) return true;
  if(el2.second < el1.second) return false;
  if(el1.first < el2.first) return true;
  return false;
}

void explainCompartor() {
  pair<int, int> arr[] = { {1,6} , {1,5} , {2,6} , {2,9} , {3,9} };
  // sort it according to the second element
  // {2,9} {3,9} {1,6} {2,6} {1,5}

  sort(arr , arr+5 , internalCompartor);
  for(auto i : arr){
    cout << "{" << i.first << "," << i.second << "}" << " " ;
  }
}

int main() {
  explainCompartor();
  return 0;
}
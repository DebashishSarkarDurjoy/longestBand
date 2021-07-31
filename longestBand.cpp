#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int longestBand(vector<int> arr) {
  int cnt = 0;
  unordered_set<int> s;
  int largest = 0;

  for (int i: arr) {
    s.insert(i);
  }

  for (int i: arr) {
    if (s.find(i-1) == s.end()) {
      cnt = 1;
      int nextNo = i + 1;
      while (s.find(nextNo) != s.end()) {
        cnt++;
        nextNo++;
      }
      largest = max(largest, cnt);
    }
  }

  return largest;
}

int main(void) {
  vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
  cout << longestBand(arr) << endl;

  return 0;
}

#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
  int a[3], b[3];
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  int count1 = 0, count2 = 0;
      for (int i = 0; i < 3; i++) {
    cin >> b[i]; 
    if (a[i] > b[i]) 
      count1++;
    else if (a[i] < b[i]) 
    count2++; 
  }
  cout << count1 << ' ' << count2 << endl;
  return 0;
}
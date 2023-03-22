#include <bits/stdc++.h> 
#include <string>
#include <iostream>
using namespace std; 

int minInserts(string str, int n);

int main(int argc, char* argv[]) {  
  while(cin.good()) {
    string palin;
    cin >> palin;
    cout << palin.length() << " " << minInserts(palin, palin.length()) << endl;
  }
}
int minInserts(string S, int n) {
  int DPtable[n][n], i, j, l;
  string ret = S;
  memset(DPtable, 0, sizeof(DPtable));
  for (l = 1; l < n; ++l) {
    for (i = 0, j = l; j < n; ++i, ++j) {
      if(S[i] == S[j])
        DPtable[i][j] = DPtable[i+1][j-1];
      else
        DPtable[i][j] = (min(DPtable[i][j-1], DPtable[i+1][j])+1);
    }
    for(i=0; i<n; ++i) {
      for(j=0; j<n; ++j)
        cout << DPtable[i][j];
      cout << endl;
    }
  }
  return DPtable[0][n - 1];
}

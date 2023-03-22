/* Copyright Evan Owre, CSCE350, Dec 8th 2020
 */
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int minInserts(string str, int n);

int main(int argc, char* argv[]) {  
  while(cin.good()) {
    string palin;
    cin >> palin;
    minInserts(palin, palin.length());  
  }
}

int minInserts(string str, int n) {
  int DPtable[n][n], i, j;
  int count = 0;
  while 
}



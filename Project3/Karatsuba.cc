/*
 *Copyright: Evan Owre, CSCE350, Nov 25th 2020
 */
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;
vector<int> karatsuba(vector<int> &a, vector<int> &b);//methods used in algorithms
void add(vector<int> &a, vector<int> &b);
vector<int> sub(vector<int> &a, vector<int> &b);
void equal(vector<int> &a, vector<int> &b);
vector<int> pen_paper(vector<int> &a, vector<int> &b);
void printV(vector<int> &a);

int main(int argc, char* argv[]) {//main method
  bool found = false;//bool used to swap vectors 
  vector<int> num1, num2;//vectors for numbers
  string line;
  cin >> line;//read in whole line
  for(size_t j=0; j < line.length(); ++j) {//count through line
    string temp = line.substr(j,1);//capture individual numbers
    if(temp == "*") {//conditional for swapping storing vectors 
      found = true;
      continue;//continue to force step through any ideration that satisifies conditional
    }
    int i = stoi(temp);//convert from string to int
    if(found == false)//conditional to store ints in proper vector
      num1.push_back(i);
    else
      num2.push_back(i);
  }
  vector<int> testPP = pen_paper(num1,num2);//testing brute force
  vector<int> testKara = karatsuba(num1,num2);//testing karatsuba
  cout << "** Brute Force: "; printV(testPP); cout << endl;//print
  cout << "** Karatsuba: "; printV(testKara); cout << endl;
}
vector<int> pen_paper(vector<int> &a, vector<int> &b) {
  equal(a,b);//ensure equal length
  vector<int> retvec;//return vector
  vector<int> temp;//temp storage vector
  int tens = 0;//keep track of 0's to add
  int carry;
  for(int i=b.size()-1; i>=0; --i) {//loop for bruteforce
    carry = 0;//carry
    for(int j=a.size()-1; j>=0; --j) {//nested loop for algo
      int prod = a[j]*b[i]+carry;// product including carry
      carry = prod/10;//setting carry
      temp.insert(temp.begin(), prod%10);//insert single digit value
    }
    for(int i=0; i<tens; ++i)//adds neccesary number of zeros to end of temp vector
      temp.push_back(0);
    if(carry!=0)
      temp.insert(temp.begin(),carry);
    printV(temp); cout << endl;
    ++tens;//increase number fo zeros for next iteration
    retvec = add(retvec,temp);// add temp to current vector
    temp.erase(temp.begin(),temp.end());//clear temp vector
  }
  return retvec;
}

vector<int> karatsuba(vector<int> &a, vector<int> &b) {
  vector<int> retvec;
  equal(a,b);
  if(a.size() == 0 || b.size() == 0)
    retvec.push_back(0);
  else if(a.size() < 2 & b.size() < 2) {
    int temp = a[0]*b[0];
    retvec.push_back(temp/10);
    retvec.push_back(temp%10);
  } else {
    int m = a.size()/2;
    vector<int> a0, a1, b0, b1;
    for(int i=0; i<m; ++i) {
      a0.insert(a0.begin(), a.back());
      a.pop_back();
      b0.insert(b0.begin(), b.back());
      b.pop_back();
    }
    a1 = a;
    b1 = b;
    vector<int> c2 = karatsuba(a1,b1);
    vector<int> c0 = karatsuba(a0,b0);

  }
}
void add(vector<int> &a, vector<int> &b) {//addition method for vectors
  equal(a,b);
  int carry = 0;//carrry
  for(int i=a.size()-1; i>=0; --i) {// for loop fro addition
    int sum = a[i]+b[i]+carry;//total sum
    a[i] = sum%10;//divided into stroe vale and carry value
    carry = sum/10;
  }
  if(carry!=0)//if carry is not 0 insert number stored in carry at the front
    a.insert(a.begin(), carry);
}
vector<int> sub(vector<int> &a, vector<int> &b) {// vector subtraction for c1 = kara(a1+a0,b1+b0)-c2-c0
  equal(a,b);
  vector<int> retvec;//return vec
  for(int i = a.size()-1; i>0; --i) {//loop for subtraction
    if(a[i]>b[i])//condition to check if barrowing is needed
      retvec.insert(retvec.begin(), a[i]-b[i]);//insert val into the return 
    else {
      a[i-1] = a[i-1]-1;//barrow
      int temp = a[i]+10;//temp to store
      retvec.insert(retvec.begin(), temp-b[i]);//insert barrowed val
    }
  }
  return retvec;
}
void equal(vector<int> &a, vector<int> &b) { //methdo to make vectors same length by adding preceding zeros
  if(a.size()==b.size()) {
    return;
  }
  if(a.size()>b.size())
    while(a.size()!=b.size())
      b.insert(b.begin(),0);
  else
    while(b.size()!=a.size())
      a.insert(a.begin(),0);
}
void printV(vector<int> &a) { //printing method
  for(size_t i=0; i<a.size(); ++i)
	  cout << a[i];
}

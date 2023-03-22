#include <iostream>  
#include <cmath>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
vector<int> sub(vector<int> &a, vector<int> &b);
void add(vector<int> &a, vector<int> &b);
void equal(vector<int> &a, vector<int> &b);
vector<int> pen_paper(vector<int> &a, vector<int> &b);
void printV(vector<int> &a);

int main(int argc, char* argv[]) {
  bool found = false;
  vector<int> num1, num2;
  string line;
  cin >> line;
  for(size_t j=0; j < line.length(); ++j) {
    string temp = line.substr(j,1);
    if(temp == "*") {
      found = true;
      continue;
    }
    int i = stoi(temp);
    if(found == false)
      num1.push_back(i);
    else
      num2.push_back(i);
  }
  printV(num1); cout <<" ";printV(num2);cout<< endl;
  vector<int> test_sub;
  add(num1,num2);
  printV(num1); cout << " arrived ";printV(num2);cout<< endl;
}
void equal(vector<int> &a, vector<int> &b) {
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

vector<int> sub(vector<int> &a, vector<int> &b) {
  equal(a,b);
  vector<int> retvec;
  for(int i = a.size()-1; i>0; --i) {
    cout << a[i] << " " << b[i] <<endl;
    if(a[i]>b[i])
      retvec.insert(retvec.begin(), a[i]-b[i]);
    else {
	    cout << "else" << a[i-1];
      a[i-1] = a[i-1]-1;
      cout << " " << a[i-1] <<endl;
      int temp = a[i]+10;
      retvec.insert(retvec.begin(), temp -b[i]);
    }
  }
  return retvec;
}

void printV(vector<int> &a) {
  for(size_t i=0; i<a.size(); ++i)
	  cout << a[i];
}
/*
vector<int> karatsuba(vector<int> &a, vector<int> &b) {//karatsuba algo
  vector<int> retvec;//return vector
  equal(a,b);//ensure same length 
  if(a.size()==0 || b.size()==0)//if either is 0 return 0
    retvec.push_back(0);
  else if(a.size()==1 && b.size()==1) { // less then ten, base case for recursion
    int prod = a[0]*b[0];// multiply
    int ones = prod%10;//if larger then ten split into two ints, ones and tens place
    int tens = prod/10;//hold ten to push on back first
    retvec.push_back(tens);//push numbers on
    retvec.push_back(ones);
  } else {
    size_t m = a.size()/2;//floor of length /2
    vector<int> numa0, numb0, numa1, numb1;//vectors for later use
    for(size_t i=0; i<m; ++i) {//split into two different vectors
      numa0.insert(numa0.begin(), a.back());//read end of vector and insert at fron of a0
      a.pop_back();//delete end of vector
      numb0.insert(numb0.begin(), b.back());
      b.pop_back();
    }
    numa1 = a;//must copy vectors over so future recursion doesn't completely destroy the vectors
    numb1 = b;
    vector<int> c2 = karatsuba(a, b);// calculate c2
    vector<int> c0 = karatsuba(numa0, numb0);// calculate c0
    vector<int> addA = add(numa1,numa0);//adding a1+a0 and storing in seperate vector
    vector<int> addB = add(numb1,numb0);//same with b1+b0
    vector<int> c1temp = karatsuba(addA,addB);//calculating part of c1
    vector<int> tt = add(c2,c0);//combining c2 and c0 to subtract from c1temp
    vector<int> c1 = sub(c1temp,tt);//calculating c1
    for(size_t i=0; i<m; ++i) {//loop to add correct number of zeros to edd of c1 and c2
      c2.push_back(0);
      c2.push_back(0);
      c1.push_back(0);
    }
    vector<int> temp = add(c2,c1);//combining all vectors
    retvec = add(temp,c0);//final combination for return;
  }
  return retvec;//return answer. my algorithm see,s to increase Karatsuba products by a factor of 3
} //not sure why this is happening any input is appreciated.
*/

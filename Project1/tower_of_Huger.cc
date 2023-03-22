/*Written By: Evan Owre, CSCE350, Sep 21st 2020
 * I have upheld the honor code and pledge that all code in this assignment was written by me
 */
#include <iostream>
#include <cstddef>
#include <vector>
#include <string>
using namespace std;

string to_Letter(int i);
void solve_Huger(int n, vector<string> &a, vector<string> &b, vector<string> &c);
void move_Stack_of_Pairs(int n, vector<string> &a, vector<string> &b, vector<string> &c);
void print_Peg(vector<string> vec);
void print_Step(vector<string> a, vector<string> b);
void print(vector<string> a, vector<string> b, vector<string> c);
int step;

int main(int argc, char* argv[]) {
  while(cin.good()){
  int n;
  step = 0;
  cin >> n;
  cout << endl << "Starting at" << endl;
  std::vector<string> a;
  vector<string> b;
  vector<string> c;
  a.push_back(std::to_string(0));
  b.push_back(to_string(1));
  c.push_back(to_string(2));
  for(int i=0; i<n; ++i) {
    a.push_back(to_Letter(65+i));
    a.push_back(to_string(i+1));
  }
  solve_Huger(n,a,b,c);
  print_Peg(a);
  print_Peg(b);
  print_Peg(c);
  cout << "Done!" << endl;
  }
}
void solve_Huger(int n, vector<string> &a, vector<string> &b, vector<string> &c) {
  if(n<2) {
    ++step;
    print(a,c,b);
    c.push_back(a.back()); // Move a disk from a to c, done by copying disk at end of a to c
    a.pop_back(); // delete disk from a, to avoid duplicate disks
    ++step;
    print(a,b,c);
    b.push_back(a.back()); // Move a disk from a to b, do by copying disk at end of a to b 
    a.pop_back(); // delete disk from b, to avoid duplicate disks
  } else {
    move_Stack_of_Pairs(n-1,a,b,c); //calls sister function
    ++step;
    print(a,c,b);
    c.push_back(a.back()); // Move a disk from a to c, done by copying disk at end of a to c
    a.pop_back(); // delete disk from a, to avoid duplicate disks
    ++step;
    print(a,c,b);
    c.push_back(a.back()); // move another disk from a to c, copied last disk of a to c
    a.pop_back(); // delete to avoid duplicate
    move_Stack_of_Pairs(n-1,b,a,c); // calls sister function
    ++step;
    print(c,b,a);
    b.push_back(c.back()); // move disk from c to b, copied last disk in b to c
    c.pop_back(); // delete to avoid duplicate
    solve_Huger(n-1, a,b,c);
  }
}
void move_Stack_of_Pairs(int n, vector<string> &a, vector<string> &b, vector<string> &c) {
  if(n<2) {
    ++step;
    print(a,c,b);
    c.push_back(a.back()); // a to c 
    a.pop_back(); // delete copy of disk
    ++step;
    print(a,b,c);
    b.push_back(a.back()); // a to b
    a.pop_back(); // delete copy of disk
    ++step;
    print(c,b,a);
    b.push_back(c.back()); // c to b
    c.pop_back(); // delete copy of disk  
  } else {
    move_Stack_of_Pairs(n-1,a,b,c); // recursion
    ++step;
    print(a,c,b);
    c.push_back(a.back()); // a to c
    a.pop_back();
    ++step;
    print(a,c,b);
    c.push_back(a.back()); // a to c
    a.pop_back();
    move_Stack_of_Pairs(n-1,b,a,c); // recursion
    ++step;
    print(c,b,a);
    b.push_back(c.back()); // c to b
    c.pop_back();
    ++step;
    print(c,b,a);
    b.push_back(c.back()); // c to b
    c.pop_back(); 
    move_Stack_of_Pairs(n-1,a,b,c); //recursion
  }
}
void print_Peg(vector<string> vec) {
  int size = vec.size();
  cout << vec[0] << ":";
  for(int i=1; i<size; ++i) {
    cout << vec[i] << "";
  }
  cout << endl;
}
void print_Step(vector<string> a, vector<string> b) { 
  cout << "Step " << step << ": Move disk " << a.back() << " from peg " << a.front() << " to peg " << b.front() << endl;
}
void print(vector<string> a, vector<string> b, vector<string> c){
  for(int i = 0; i<3; ++i) {
    if(a[0]==to_string(i))
      print_Peg(a);
    if(b[0]==to_string(i))
      print_Peg(b);
    if(c[0]==to_string(i))
      print_Peg(c);
  }
  print_Step(a,b);
}
string to_Letter(int i) {
  char letter = (char)(i);
  string ret(1, letter);
  return ret;
}

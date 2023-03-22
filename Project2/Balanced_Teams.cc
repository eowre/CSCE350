/*Written By: Evan Owre, CSCE350, 10/19/20*/
#include <iostream>
#include <cstddef>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//global variables used throughout the program
void test(vector<string> &team, vector<int> &rank, string binary);
static int num;
bool SolFound = false;
void printNoSol();

int main(int argc, char* argv[]) {
  while(cin.good()) {//loop that runs while input is good
    cin >> num;//read in number of people, stored in global var for use across all functions
    vector<string> team;//vector of people
    vector<int> weight;//vector of weight of each worker
    int TW =0;
    for(int i = 0; i<num; ++i) {//loop runs num times, populates both vectors
      string worker;
      int rank;
      cin >> worker;
      cin >> rank;
      TW+=rank;//keeps track of total rank for initial check
      team.push_back(worker);//add worker to team vector
      weight.push_back(rank);//add rank to weight vector
      }
    if(TW%2!=0) {//initial check, if total weight is not even no solution possible
      printNoSol();//print out function
      continue;
    }
    cout << endl;//formatting
    for(int count=0; count<pow(2,num); ++count) {//loop that iterates through a binary number
      string binary;//used to store the binary number for transfer between functions
      for(int offset = num-1; offset>=0; --offset) {//uses count to properly generate each iteration of the binary number
        int binaryNum = ((count & (1 << offset)) >> offset);//captures each digit of the binary number
        binary = to_string(binaryNum)+binary;//update the binary string
      }
      test(team, weight, binary);//function to test each permutaion
    }
    if(SolFound==false)//if no solutions are found 
      printNoSol();//print out no solutions
  }
}
//testing method
void test(vector<string> &team, vector<int> &rank, string binary) {//takes in reference to team and rank vectors, takes in binary string
  string zero = "0";//strings need for future comparisions
  string one = "1";
  int a_weight = 0;//declare the weight of each team for checking equality
  int b_weight = 0;
  vector<string> team_a, team_b;//creates vectors for team a and team b
  if(binary[0]!=zero[0])// condition met if first person entered is not on team A, handles duplicate casess
    return;
  for(int i=0; i<num; ++i) {//loop that runs for total number of people, this is why num is  global var
    if(binary[i] == zero[0]) {//if ith index of binary string is zero adds person to team a
      a_weight+= rank[i];// adjusts total weight of team a
      team_a.push_back(team[i]);
    } else if(binary[i] == one[0]) {//if ith index of binary string is one adds person to team b
      b_weight+= rank[i];// adjusts total weight of team b
      team_b.push_back(team[i]);
    }
  }
  if(a_weight==b_weight) {//checks if each team is equal, if you wanted to allow for a slight difference between team strength this is the condition to alter
    if(SolFound == false)//updates global solution found variable, in case the total weight is even, and set of workers does not have a solution
      SolFound = true;
    cout<< "Team A:" << endl;//printing teams
    for(size_t i=0; i<team_a.size(); ++i)//printing team a
      cout << " " << team_a[i] << endl;
    cout << "Team B:" << endl;
    for(size_t i=0; i<team_b.size(); ++i)
      cout << " " << team_b[i] << endl;//printing team b
    cout << endl; 
  }
}

void printNoSol() { //function for no solutions
  cout << "------------" << endl << "NO SOLUTIONS" << endl << "------------" << endl;
}

#include "assignment4.h"

//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 4                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   February 22, 2018                                  //
//                                                                  //
//   FUNCTION:   Implements the Queue class using STL stacks        //
//******************************************************************//

#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

/***************************************************************
bool Queue::empty() const
Use: Makes sure both s1 and s2 are empty
Parameters: None
Returns: 1. True- s1 and s2 are empty
         2. False- s2 and/or s2 are not empty
***************************************************************/
bool Queue::empty() const{
  if(s1.empty() && s2.empty())
    return true;

  else
    return false;
}

/***************************************************************
int Queue::size() const
Use: Counts the number of elements in both s1 and s2
Parameters: None
Returns: int- Number of elements
***************************************************************/
int Queue::size() const{
  int sum = s1.size() + s2.size();
  return sum;
}

/***************************************************************
int Queue::front()
Use: Returns the oldest element aka the top element in s2
     If s2 is empty, moves all elements from s1 to s2
Parameters: None
Returns: int- Oldest element aka top element in s2
***************************************************************/
int Queue::front(){
  if(s2.empty()){
    s2.swap(s1);
  }

  return s2.top();
}

/***************************************************************
int Queue::back()
Use: Returns the newest element aka the top element in s1
Parameters: None
Returns: int- Newest element aka top element in s1
***************************************************************/
int Queue::back(){
  return s1.top();
}

/***************************************************************
void Queue::push(const int& val)
Use: Adds the element to s1
Parameters: const int& val- reference to the element
Returns: Nothing
***************************************************************/
void Queue::push(const int& val){
  s1.push(val);
}

/***************************************************************
void Queue::pop()
Use: Removes the oldest element
Parameters: None
Returns: Nothing
***************************************************************/
void Queue::pop(){
  if(s2.empty()){
    s2.swap(s1);
  }

  s2.pop();
}

//************************************************************//
//                             MAIN                           //
//************************************************************//

int main() {
  Queue q;
  string op;
  int val = 0;

  cout << "operation -- size front end" << endl;
  cin >> op;
  while(!cin.eof()){
    if(op == "push"){
      cin >> val;
      q.push(val);
      cout << op << " " << val << "    -- ";
    }

    else if(op == "pop"){
      q.pop();
      cout << op << "       -- ";
    }

    else{
      cerr << "Error input: " << op << endl;
      return 1;
    }

    cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
    cin >> op;
  }

  while(!q.empty())
    q.pop();

  return 0;
}

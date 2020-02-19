#ifndef ASSIGNMNET4_H
#define ASSIGNMENT4_H

//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 4                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   February 22, 2018                                  //
//                                                                  //
//   FUNCTION:   Implements the Queue class using STL stacks        //
//               Header File                                        //
//******************************************************************//

#include <stack>

class Queue {
  private:
    std::stack<int> s1, s2;

  public:
    bool empty() const;
    int size() const;
    int front();
    int back();
    void push(const int& val);
    void pop();
};

#endif

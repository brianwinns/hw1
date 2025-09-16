/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void deleteList(Node*& head)
{
  while (head != nullptr)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main(int argc, char* argv[])
{

  Node* listParser = nullptr;
  //Test 1: Mixed Odds/Evens
  Node* odds1 = nullptr;
  Node* evens1 = nullptr;
  Node* test1 = nullptr;
  Node* OneN3 = new Node(3, nullptr);
  Node* OneN2 = new Node(2, OneN3);
  Node* OneN1 = new Node(1, OneN2);
  test1 = OneN1;

  split(test1, odds1, evens1);

  cout << "\nTest 1: Mixed Input" << endl << "Odds: ";
  listParser = odds1;
  while (listParser != nullptr)
  {
    cout << listParser->value << " ";
    listParser = listParser->next;
  }

  cout << "\nEvens: ";
  listParser = evens1;
  while (listParser != nullptr)
  {
    cout << listParser->value << " ";
    listParser = listParser->next;
  }

  deleteList(odds1);
  deleteList(evens1);


// test all evens
  Node* odds2 = nullptr;
  Node* evens2 = nullptr;
  Node* test2 = nullptr;
  Node* twoN3 = new Node(6, nullptr);
  Node* twoN2 = new Node(4, twoN3);
  Node* twoN1 = new Node(2, twoN2);
  test2 = twoN1;

  split(test2, odds2, evens2);

  cout << "\nTest 2: All Evens" << endl << "Odds: ";
  listParser = odds2;
  while (listParser != nullptr)
  {
    cout << listParser->value << " ";
    listParser = listParser->next;
  }

  cout << "\nEvens: ";
  listParser = evens2;
  while (listParser != nullptr)
  {
    cout << listParser->value << " ";
    listParser = listParser->next;
  }

  deleteList(odds2);
  deleteList(evens2);



//Test all odds
  Node* odds3 = nullptr;
  Node* evens3 = nullptr;
  Node* test3 = nullptr;
  Node* threeN3 = new Node(5, nullptr);
  Node* threeN2 = new Node(3, threeN3);
  Node* threeN1 = new Node(1, threeN2);
  test3 = threeN1;

  split(test3, odds3, evens3);

  cout << "\nTest 3: All Odds" << endl << "Odds: ";
  listParser = odds3;
  while (listParser != nullptr)
  {
    cout << listParser->value << " ";
    listParser = listParser->next;
  }

  cout << "\nEvens: ";
  listParser = evens3;
  while (listParser != nullptr)
  {
    cout << listParser->value << " ";
    listParser = listParser->next;
  }

  deleteList(odds3);
  deleteList(evens3);



return 0;
}

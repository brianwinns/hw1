/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // BASE CASE: If input list is empty, return immediately; When input list is emptied (all nodes have been split), ends recursion
  if (in == nullptr)
  {
    return;
  }

  //keeps track of current "in" node in a temporary pointer;
  //sets head of in to the next node in the list to ensure recursive calls act upon remaining nodes in the list
  Node* temp = in;
  in = in->next;

  //if current node is odd, adds node to odds list (points odds->next to current node) and calls split recursively
  //updates odds->next after calling split recursively
  if (temp->value % 2 == 1)
  {
    odds = temp;
    odds->next = nullptr;
    split(in, odds->next, evens);
  }

  else
  {
    evens = temp;
    evens->next = nullptr;
    split(in, odds, evens->next);
  }
}

/* If you needed a helper function, write it here */

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
  //Base case: if input list is empty, return immediately; Ends recursion when input list is emptied
  if (in == nullptr){
    return;
  }

  //keeps track of current node of "in" in temporary pointer; 
  //set head of in to the next node in list, ensures recursive calls act on remainder of list
  Node* temp = in;
  in = in->next;

  //if current node is even, adds node to evens list and calls split recursively
  //updates evens->next upon recursive call
  if (temp->value % 2 == 0){
    evens = temp;
    evens->next = nullptr;
    split(in, odds, evens->next);
  } 

  //if current node is odd, adds node to odds list and calls split recursively
  //updates odds->next upon recursive call
  else {
    odds = temp;
    odds->next = nullptr;
    split(in, odds->next, evens);
  }
   
}

/* If you needed a helper function, write it here */

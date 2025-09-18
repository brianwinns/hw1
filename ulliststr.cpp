#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& value)
{
  //Check if list is empty or tail node is full at the back
  if (tail_ == NULL || tail_->last == ARRSIZE)
  {
    Item* newNode = new Item();
    newNode->val[0] = value;
    newNode->last++;

    //If there exists a tail node (full tail), link the new tail node
    if (tail_ != NULL)
    {
        tail_->next = newNode;
        newNode->prev = tail_;
    }

    tail_ = newNode;

    //If list was previously empty, set head and tail equal to the newly allocated node
    if (head_ == NULL)
    {
        head_ = tail_;
    }
  }

  //If tail node currently has space, push new value to the back of the tail node
  else
  {
    tail_->val[tail_->last] = value;
    tail_->last++;
  }

  size_++;
}

void ULListStr::push_front(const std::string& value)
{
  //check if list is empty or full at the front
  if (head_ == NULL || head_->first == 0)
  {
    //if empty or full at front, allocate new head node
    Item* newNode = new Item();
    newNode->val[ARRSIZE-1] = value;
    newNode->last = ARRSIZE;
    newNode->first = ARRSIZE - 1;

    //if there is a current head node (full at front), link the new head node
    if (head_ != NULL)
    {
      head_->prev = newNode;
      newNode->next = head_;
    }

    //set head to new head node
    head_ = newNode;
    // if list was previously empty, set head and tail equal to new, singular node
    if (tail_ == NULL)
    {
      tail_ = head_;
    }
  }

  //if head node has space, push new value to front of head node
  else 
  {
    head_->first--;
    head_->val[head_->first] = value;
  }

  size_++;
}

void ULListStr::pop_back()
{
  //if list is empty, do nothing
  if (tail_ == NULL)
  {
    return;
  }

  else 
  {
    //remove last element of tail by reducing last index, update size
    size_ -= 1;
    tail_->last -= 1;

    //if tail node is empty after popping back, delete node
    if (tail_->first == tail_->last)
    {
      Item* temp = tail_;
      tail_ = tail_->prev;

      //if updated tail node is not empty, unlink empty tail
      if (tail_ != NULL)
      {
        tail_->next = NULL;
      }

      //if updated tail is also empty, list is empty
      else 
      {
        head_ = NULL;
      }
      
      delete temp;
    }
  }
}

void ULListStr::pop_front()
{
  // if list is empty, do nothing
  if (head_ == NULL)
  {
    return;
  }
  
  else 
  {
    //remove first element of head by increasing first index, update size
    size_ -= 1;
    head_->first+=1;

    //if head node is empty after popping front, remove node
    if (head_->first == head_->last)
    {
      Item* temp = head_;
      head_ = head_->next;

      //if updated head node is not empty, unlink empty head
      if (head_ != NULL)
      {
        head_->prev = NULL;
      }

      //if updated head node is also empty, list is empty
      else 
      {
        tail_ = NULL;
      }

      delete temp;
    }
  }
}

std::string const & ULListStr::back() const
{
  //if list is empty, throw an exception
  if (tail_ == NULL)
  {
    throw std::out_of_range("List is empty");
  }

  //return last element
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  //if list is empty, throw an exception
  if (head_ == NULL)
  {
    throw std::out_of_range("List is empty");
  }
  
  //return first element
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  //if desired location is out of bounds, return nothing
  if (loc >= size_)
  {
    return NULL;
  }

  Item* current = head_;
  //traverse through linked list until reaching node containing desired element
  while (current != NULL)
  {
    //keep track of how many elements in node
    size_t nodeSize = current->last - current->first;
    //if desired element is in current node, return pointer to desired element
    if (loc < nodeSize)
    {
      return &current->val[current->first + loc];
    }

    //if desired element is not in current node, subtract # of skipped elements from loc and move to next node
    loc -= nodeSize;
    current = current->next;
  }

  //occurs if element not found (error case)
  return NULL;
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

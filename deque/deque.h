//
// COMP 2012H project#3 Queues @HKUST
// Author: GU Qiao
// Email: qgu@connect.ust.hk
// All rights reserved.
//


#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>

using namespace std;

template<typename T>
class Deque {
private:
  // The struct of the Node
  //it contains pointers to the next and previous node besides the data
  struct Node {
    T data;
    Node* next;
    Node* prev;
  };

  //the dummy head node
  Node *head;

  //the number of the items stored currently
  int _size;

public:

  //default constructor
  Deque();

  //copy  constructor
  Deque(const Deque<T>&);

  //assign constructor
  Deque<T>& operator=(const Deque<T>&);

  //destructor
  ~Deque();

  //return true if it is empty
  bool isEmpty();

  // return the number of items on the deque
  int size();

  // insert the item at the front of the queue
  void addFirst(T);

  // insert the item at the end of the queue
  void addLast(T);

  // delete and return the first item in queue
  T removeFirst();

  // delete and return the last item in queue
  T removeLast();

  class Iterator {
    friend class Deque<T>;
  public:
    //because it doesn't have dynamic data member
    //only define the typical constructor, using copy and assign constructor
    //created by the compiler
    Iterator(const Deque<T>*);

    //overloading the ++ and * operator
    void operator++();
    T operator*();

  private:
    // The current node position the iterator points to
    Node *node;
  };

  // return an iterator that examines the
  // items in order from front to back
  Iterator iterator();
};

/*
  the implement of the member functions
*/

template <typename T>
Deque<T>::Deque():head(new Node), _size(0) {
  head->prev = head;
  head->next = head;
}

template <typename T>
Deque<T>::Deque(const Deque<T>& dq):head(new Node), _size(0) {
  head->prev = head;
  head->next = head;
  int i;
  Node* dq_current;
  dq_current = dq.head;
  for (i = 0; i<dq._size; i++) {
    dq_current = dq_current->next;
    this->addLast(dq_current->data);
  }
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& dq){
  this->~Deque();
  _size = 0;
  head = new Node;
  head->prev = head;
  head->next = head;
  int i;
  Node* dq_current;
  dq_current = dq.head;
  for (i = 0; i < dq._size; i++) {
    dq_current = dq_current->next;
    this->addLast(dq_current->data);
  }

  return *this;
}

template <typename T>
Deque<T>::~Deque() {
  Node *current  = head->next;
  while (current!=head) {
    current = current->next;
    delete current->prev;
  }
  delete current;
}

template <typename T>
bool Deque<T>::isEmpty() {
  return (head->next==head && head->prev==head);
}

template <typename T>
int Deque<T>::size() {
  return _size;
}

template <typename T>
void Deque<T>::addFirst(T item) {
  Node *new_node = new Node;
  new_node->data = item;
  new_node->next = head->next;
  new_node->prev = head;
  head->next->prev = new_node;
  head->next = new_node;
  _size++;
}

template <typename T>
void Deque<T>::addLast(T item) {
  Node *new_node = new Node;
  new_node->data = item;
  new_node->prev = head->prev;
  new_node->next = head;
  head->prev->next = new_node;
  head->prev = new_node;
  _size++;
}

template <typename T>
T Deque<T>::removeFirst() {
  if(this->isEmpty()) {
    throw runtime_error("Try to remove item from a empty list.");
  }

  T first_data = head->next->data;
  Node *first = head->next;
  head->next = head->next->next;
  head->next->prev = head;
  delete first;
  _size--;
  return first_data;
}

template <typename T>
T Deque<T>::removeLast() {
  if(this->isEmpty()) {
    throw runtime_error("Try to remove item from a empty list.");
  }

  T last_data = head->prev->data;
  Node *last = head->prev;
  head->prev = head->prev->prev;
  head->prev->next = head;
  delete last;
  _size--;
  return last_data;
}

template <typename T>
typename Deque<T>::Iterator Deque<T>::iterator() {
  Iterator itr = Iterator(this);
  return itr;
}

//for the DequeIterator class

template <typename T>
Deque<T>::Iterator::Iterator(const Deque<T>* deque) {
  node = deque->head->next;
}

template <typename T>
void Deque<T>::Iterator::operator++() {
  node = node->next;
}

template <typename T>
T Deque<T>::Iterator::operator*() {
  return node->data;
}


#endif

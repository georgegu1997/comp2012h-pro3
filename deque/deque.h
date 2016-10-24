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
  struct Node {
    T data;
    Node* next;
    Node* prev;
  };
  Node *head;
  int _size;

public:
  Deque();
  ~Deque();
  bool isEmpty();
  int size();
  void addFirst(T);
  void addLast(T);
  T removeFirst();
  T removeLast();

  typedef class DequeIterator {
    friend class Deque<T>;
  public:
    DequeIterator(const Deque<T>*);
    void operator++();
    T operator*();
  private:
    Node *node;
  } Iterator;

  Iterator iterator();
};

template <typename T>
Deque<T>::Deque():head(new Node), _size(0) {
  head->data = NULL;
  head->prev = head;
  head->next = head;
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
Deque<T>::DequeIterator::DequeIterator(const Deque<T>* deque) {
  node = deque->head->next;
}

template <typename T>
void Deque<T>::DequeIterator::operator++() {
  node = node->next;
}

template <typename T>
T Deque<T>::DequeIterator::operator*() {
  return node->data;
}


#endif

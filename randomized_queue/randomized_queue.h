//
// COMP 2012H project#3 Queues @HKUST
// Author: GU Qiao
// Email: qgu@connect.ust.hk
// All rights reserved.
//

#ifndef RANDOMIZED_QUEUE_H
#define RANDOMIZED_QUEUE_H

#include <stdexcept>
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
class RandomizedQueue {
public:

  //declare the class name first
  class Iterator;

  //default constructor
  RandomizedQueue();

  //copy constructor
  RandomizedQueue(const RandomizedQueue<T>& rq);

  // assign constructor
  RandomizedQueue<T>& operator=(const RandomizedQueue<T>& rq);

  //destructor
  ~RandomizedQueue();

  // is the queue empty?
  bool isEmpty();

  // return the number of items on the queue
  int size();

  // add the item
  void enqueue(T);

  // delete and return a random item
  T dequeue();

  // return (but do not delete) a random item
  T sample();

  // return an iterator that returns the items in random order
  Iterator iterator();

  class Iterator {
  public:
    // this Iterator just create a copy of all indexes
    // and then shuffle them as the return item in order

    //default constructor
    Iterator();

    //typical constructor from a RandomizedQueue
    Iterator(T*, int);

    //copy constructor
    Iterator(const Iterator& itr);

    //assign constructor
    Iterator& operator=(const Iterator& itr);

    //destructor
    ~Iterator();

    //overloading the ++ and * operator
    void operator++();
    T operator*();

  private:

    //shufffle the index
    void shuffle();

    //the pointer to the start of the array
    T* _start;

    //the current position in the shuffled index
    //Not the real index
    int _pos;

    //the size of the index
    int max_index;

    //shuffled index
    int *shuffle_index;
  };

private:
  //creat a new array with int size and move the old items into the new one
  void resize (int);

  //the pointer to the start of the array
  T* _start;

  //the number of the items stored in the array
  int _size;

  //The capacity of the array(the real space allocated for the array)
  int _capacity;
};

/*
  the implementation of the member functions
*/

template <typename T>
RandomizedQueue<T>::RandomizedQueue():_size(0),_capacity(2),_start(new T[2]) {}

template <typename T>
RandomizedQueue<T>::RandomizedQueue(const RandomizedQueue<T>& rq):_size(rq._size), _capacity(rq._capacity), _start(new T[rq._capacity]) {
  int i;
  for (i = 0; i<_size; i++){
    this->_start[i] = rq._start[i];
  }
}

template <typename T>
RandomizedQueue<T>& RandomizedQueue<T>::operator=(const RandomizedQueue<T>& rq) {
  this->~RandomizedQueue();
  _size = rq._size;
  _capacity = rq._capacity;
  _start = new T[_capacity];
  int i;
  for (i = 0; i<_size; i++){
    this->_start[i] = rq._start[i];
  }
  return *this;
}

template <typename T>
RandomizedQueue<T>::~RandomizedQueue() {
  delete[] _start;
}

template <typename T>
bool RandomizedQueue<T>::isEmpty() {
  return _size == 0;
}

template <typename T>
int RandomizedQueue<T>::size() {
  return _size;
}

template <typename T>
void RandomizedQueue<T>::resize(int cap) {
  int i;
  T* new_arr = new T[cap];

  for (i = 0;i < _size; i++){
    new_arr[i] = _start[i];
  }

  delete[] _start;
  _start = new_arr;
  _capacity = cap;
}

template <typename T>
void RandomizedQueue<T>::enqueue(T item) {
  if(_size == _capacity) resize(_capacity*2);

  _start[_size] = item;
  _size ++;
}

template <typename T>
T RandomizedQueue<T>::dequeue() {
  if(this->isEmpty()) {
    throw runtime_error("Try to dequeue item from a empty list.");
  }
  int index = rand() % _size;
  T a = _start[index];
  _start[index] = _start[_size - 1];
  _size--;
  if (_size <= _capacity/4) resize(_capacity/2);
  return a;
}

template <typename T>
T RandomizedQueue<T>::sample() {
  int index = rand() % _size;
  return _start[index];
}

template <typename T>
typename RandomizedQueue<T>::Iterator RandomizedQueue<T>::iterator() {
  return Iterator(_start, _size);
}

template <typename T>
RandomizedQueue<T>::Iterator::Iterator() {}

template <typename T>
RandomizedQueue<T>::Iterator::Iterator(T* start, int size): _pos(0), _start(start), max_index(size) {
  shuffle_index = new int[max_index];
  shuffle();
}

template <typename T>
RandomizedQueue<T>::Iterator::Iterator(const Iterator& itr):_pos(itr._pos), _start(itr._start), max_index(itr.max_index) {
  shuffle_index = new int[max_index];

  int i;
  for (i=0; i<max_index; i++){
    shuffle_index[i] = itr.shuffle_index[i];
  }
}

template <typename T>
typename RandomizedQueue<T>::Iterator& RandomizedQueue<T>::Iterator::operator=(const Iterator& itr) {
  this->_pos = itr._pos;
  this->_start = itr._start;
  this->max_index = itr.max_index;
  int i;
  for (i=0; i<max_index; i++){
    this->shuffle_index[i] = itr.shuffle_index[i];
  }
  return *this;
}

template <typename T>
RandomizedQueue<T>::Iterator::~Iterator(){
  delete[] shuffle_index;
}

template <typename T>
void RandomizedQueue<T>::Iterator::operator++() {
  _pos++;
}

template <typename T>
T RandomizedQueue<T>::Iterator::operator*() {
  if (_pos >= max_index) {
    throw runtime_error("Iterator: trying to get a item out of range of array");
  }
  return *(_start+shuffle_index[_pos]);
}

template <typename T>
void RandomizedQueue<T>::Iterator::shuffle() {
  int i;
  int index[max_index];
  int temp_index;

  for (i = 0;i < max_index;i++) {
    index[i] = i;
  }

  for (i = 0;i < max_index;i++) {
    temp_index = rand() % (max_index-i);
    shuffle_index[i] = index[temp_index];
    index[temp_index] = index[max_index-i-1];
  }
}

#endif

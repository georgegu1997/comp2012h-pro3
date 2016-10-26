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
  class Iterator;
  RandomizedQueue();
  ~RandomizedQueue();
  bool isEmpty();
  int size();
  void enqueue(T);
  T dequeue();
  T sample();
  Iterator iterator();

  class Iterator {
  public:
    Iterator();
    Iterator(T*, int);
    ~Iterator();
    void operator++();
    T operator*();
  private:
    void shuffle();
    T* _start;
    int _pos;
    int max_index;
    int *shuffle_index;
  };

private:
  void resize (int);
  T* _start;
  int _size;
  int _capacity;
};

template <typename T>
RandomizedQueue<T>::RandomizedQueue():_size(0),_capacity(2),_start(new T[2]) {}

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
  cout<<"creating: "<< shuffle_index <<endl;
  shuffle();
}

template <typename T>
RandomizedQueue<T>::Iterator::~Iterator(){
  cout<<"deleting: "<< shuffle_index <<endl;
  delete[] shuffle_index;
  //cout<<"delete successfully!"<<endl;
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

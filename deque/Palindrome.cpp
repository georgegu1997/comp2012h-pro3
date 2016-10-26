//
// COMP 2012H project#3 Queues @HKUST
// Author: GU Qiao
// Email: qgu@connect.ust.hk
// All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "deque.h"

using namespace std;

int main() {
  char c;
  char first;
  char last;
  Deque<char> dq;
  int is_palindrome = 1;

  cout<<"Please input the sequence(must be composed by A, T, C, and G):"<<endl;

  while ((c = getchar()) != '\n') {
    // only accept the input with A T C G
    if(c != 'A' && c != 'T' && c != 'C' && c != 'G') {
      cout<<"the input must be a sequence of A, T, C or G"<<endl;
      exit(0);
    }else {
      dq.addLast(c);
    }
  }

  if(dq.size() % 2 == 1){
    cout<<"false"<<endl;
  }else {
    while(!dq.isEmpty()) {
      first = dq.removeFirst();
      last = dq.removeLast();
      if ((first == 'T'&& last !='A') || (first=='A' && last !='T') || (first == 'C' && last !='G') || (first == 'G' && last !='C')){
        is_palindrome = 0;
      }
    }
    if(is_palindrome) cout<<"true"<<endl;
    else cout<<"false"<<endl;
  }
}

//
// COMP 2012H project#3 Queues @HKUST
// Author: GU Qiao
// Email: qgu@connect.ust.hk
// All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include "randomized_queue.h"

using namespace std;

int main(int argc, char ** argv) {
  srand(time(0));

  if (argc < 2) {
    cout<<"usage: "<<argv[0]<<" number"<<endl;
    exit(0);
  }

  string tmp = "";
  char c;
  int i;
  int subset_size = atoi(argv[1]);
  RandomizedQueue<string> rq;

  cout<<"Please input the string elements, splited by ' ':"<<endl;

  while ((c = getchar()) != '\n') {
    if (c == ' '){
      if ( tmp != "" && tmp != " "){
        rq.enqueue(tmp);
        tmp = "";
      }else {
        tmp = "";
      }
    }else {
      tmp += c;
    }
  }

  if(tmp != "") rq.enqueue(tmp);

  if (rq.size() < subset_size) {
    cout<<"The size of the subset is larger than the original set. "<<endl;
    subset_size = rq.size();
    cout<<"The size of subset is set to be "<<subset_size<<endl;
  }

  cout<<"The output is:"<<endl;

  for (i = 0; i < subset_size; i++) {
    cout<<rq.dequeue()<<endl;
  }
}

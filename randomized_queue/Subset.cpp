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

  if (rq.size() < subset_size) {
    subset_size = rq.size();
  }

  for (i = 0; i < subset_size; i++) {
    cout<<rq.dequeue()<<endl;
  }
}

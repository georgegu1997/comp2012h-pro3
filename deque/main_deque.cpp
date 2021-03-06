#include <iostream>
#include <cstdlib>
#include "deque.h"

/*
This main program only checks your class, functions' signatures correct or not.
To check the correctness of your program, you may need to use more complicated examples.
*/

using namespace std;

int main(int argc, char ** argv){
	srand(time(0));

	Deque<char> q;

	cout << "Empty? "<< q.isEmpty() << endl;
	cout << "Size? " << q.size() << endl;
	q.addFirst('a');
	q.addFirst('b');
	q.addLast('c');
	q.addLast('d');
	q.addFirst('e');
	cout << "Empty? " << q.isEmpty() << endl;
	cout << "Size? " << q.size() << endl;

	int i;
	Deque<char>::Iterator itr = q.iterator();
	cout << "deque : " ;
	for(i = 0; i < q.size();i++){
		cout << *itr << " ";
		++itr;
	}
	cout << endl;

	cout << "remove first : " << q.removeFirst() << endl;
	itr = q.iterator();
	cout << "deque : ";
	for(i = 0; i < q.size();i++){
		cout << *itr << " ";
		++itr;
		}
		cout << endl;

		cout << "remove last " << q.removeLast() << endl;
		itr = q.iterator();
		cout << "deque : ";
		for(i = 0; i < q.size();i++){
			cout << *itr << " ";
			++itr;
		}
		cout << endl;

	cout<<"using assign constructor.."<<endl;
	Deque<char> q2 = q;
	cout << "remove first : " << q2.removeFirst() << endl;
	itr = q2.iterator();
	cout << "deque : ";
	for(i = 0; i < q2.size();i++){
		cout << *itr << " ";
		++itr;
		}
		cout << endl;


//  output of 1. is different from 2.'s  , Why?
//1.
		cout <<"remove LFL : " << q.removeLast() << " ";
		cout << q.removeFirst()<<" ";
		cout <<q.removeLast()<<endl;


/*
//2.
		cout <<"remove LFL : " << q.removeLast() << " " << q.removeFirst()<<" "<<q.removeLast()<<endl;
*/
/*
    cout << "testing runtime error"<<endl;
		cout << "remove last " << q.removeLast() << endl;
		cout << "remove last " << q.removeLast() << endl;
		cout << "remove last " << q.removeLast() << endl;
		cout << "remove last " << q.removeLast() << endl;
		cout << "remove last " << q.removeLast() << endl;
		cout << "remove last " << q.removeLast() << endl;
*/
		return 0;
}

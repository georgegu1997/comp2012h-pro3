all: subset palindrome test
subset: randomized_queue/randomized_queue.h randomized_queue/Subset.cpp
	g++ -o subset randomized_queue/Subset.cpp
palindrome: deque/deque.h deque/Palindrome.cpp
	g++ -o palindrome deque/Palindrome.cpp

clean:
	rm *.o

test: test_deque test_randomized_queue
test_randomized_queue: randomized_queue/randomized_queue.h randomized_queue/main_rand.cpp
	g++ -o test_randomized_queue randomized_queue/main_rand.cpp
test_deque: deque/deque.h deque/main_deque.cpp
	g++ -o test_deque deque/main_deque.cpp

/**********************************************************************
 *  Randomized Queues and Deques
 **********************************************************************/

Name: GU Qiao
ID: 20328422
Login: qgu
Hours to complete assignment (optional):


/**********************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **********************************************************************/
PUT YOUR ANSWER HERE

Writing deque, I used the linked list structure. Because the linked list
can make all add and remove operations spend constant time, and use the
space proportional to the number of items currently stored in the deque.
The iterator of linked list just like a node, so it takes constant extra
space.

Writing randomized queue, I used resizing array, which would double its
capacity when the the number of items in the array reach its capacity (2
at first), and shrink its capacity to half when the  number of items
decreases to one fourth of the capacity. The time efficiency will be
proved in the next question. the iterator stores a shuffled list of index,
so it takes linear extra space per iterator.

/**********************************************************************
 *  Briefly describe why any sequence of N randomized queue operations,
 *  starting from an empty randomized queue, takes O(N) time.
 **********************************************************************/
PUT YOUR ANSWER HERE

For convenience, let's call a operation that only takes one copy operation
"small operation", and the operation that takes multiple copy operations
(i.e. involving resizing) "big operation".

In worst case, when the number of the items is increasing, from the last
big operation to the next big operation, there at least exist some small
operations. If the big operation takes 2^m copy actions, then the number
of the small operations must be at least 2^(m-1). Through amortization
analysis, each operation takes 3 copy actions on average. So, the total
time cost is O(3n)=O(n).

If the number of the items is decreasing, from the last big operation to
the next big operation that takes 2^m copy actions, there must be at least
2^m. And on average, each operation takes 2 copy actions. So, the total
time cost is O(2n)=O(n).

So the total time cost must be smaller than 3n, which is O(n).

/**********************************************************************
 *  Briefly describe why each Deque operation takes O(1) time.
 **********************************************************************/
PUT YOUR ANSWER HERE

The structure of the Deque is doubly linked list. It holds pointers both
to the first and the last items. So, it only takes a constant time to
add or remove the first or the last item, which is O(1).


/**********************************************************************
 *  How much memory (in bytes) does your data type use to store N items.
 *  Use tilde notation to simplify your answer. Use the memory requirements
 *  for a "typical machine" given in Lecture. In your analysis, don't include
 *  the memory for the items themselves (as this memory is allocated by
 *  the client and depends on the item type.
 *  For a typical machine, refer to page 11 of
 *  https://www.cs.princeton.edu/courses/archive/spr10/cos226/lectures/02-14Analysis-2x2.pdf
 **********************************************************************/

RandomizedQueue:
  object overhead: 8 bytes
  T *_start: 4 bytes (assume the pointer is an integer)
  int _size: 4 bytes
  int _capacity: 4 bytes
  data array overhead: 16 bytes

  total: 36 bytes
  tilde notation: 36

Dequeue:
  object overhead: 8 bytes
  Node *head: 4 bytes (assume same as integer)
  int _size: 4 bytes
  two pointers per node: 8N bytes (assume pointer the same as integer)

  total: (8N + 16) bytes
  tilde notation: 8N




/**********************************************************************
 *  Known bugs / limitations.
 **********************************************************************/


/**********************************************************************
 *  List whatever help (if any) that you received and from whom,
 *  including help from staff members or lab TAs.
 **********************************************************************/

When I learned the amortized analysis by myself on the wikipedia
(https://en.wikipedia.org/wiki/Amortized_analysis), the pedia
just used the resizing array as an example, and conclude that the average
time for a operation is O(1). So, I actually got my idea of RandomizedQueue
from that.


/**********************************************************************
 *  Describe any serious problems you encountered.
 **********************************************************************/




/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback
 *  on how much you learned from doing the assignment, and whether
 *  you enjoyed doing it.
 **********************************************************************/

# priority_queue
An implementation of priority queues with templates and custom comparators in C++.
It can be easily included in any C++ project and has all the main methods a priority queue should have.
This implementation uses heap data structure for maintaining the priority queue functionality and std::vector as container for the elements.
## Implemented methods
### Inserting an element
- push()
### Deleting an element
- pop()
### Peeking the top element
- top()
### Changing the value of an element by index
This method is not specific to priority queues, so think of it as a bonus.
- change()
### Deciding the priority of the elements
Using templates the priority queue can store any kind of datatypes as far as they are homogeneous and a comparator is defined to decide which element has the higher priority.
There are two predefined comparator classes for min and max priority queues also built in.
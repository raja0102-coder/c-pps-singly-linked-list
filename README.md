# PPS Singly Linked List & Nodal Engine

A Semester 1 Programming for Problem Solving (PPS) C application demonstrating dynamic data structures, self-referential structures (`struct Node`), head pointer references (`Node **`), node insertions, value deletions, linear list traversal, and complete memory cleanup.

## PPS Concepts Covered
* **Self-Referential Structures**: Structs containing pointers pointing to instances of the same structure type.
* **Dynamic Node Allocation**: Allocating individual node memory blocks on the heap via `malloc`.
* **Pointer-to-Pointer Modification (`Node **`)**: Modifying the head pointer variable within functions by passing its memory address.
* **Linear Traversal $O(N)$**: Iterating sequentially through node pointer links (`current = current->next`) until reaching `NULL`.
* **Memory Safety & Deallocation**: Sequentially freeing heap memory for each node to prevent memory leaks.

## How to Compile & Run
```bash
gcc main.c -o singly_linked_list
./singly_linked_list

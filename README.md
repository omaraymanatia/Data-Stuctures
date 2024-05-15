# Data Structures Repository

This repository contains implementations of various data structures in Python.

## Data Structures

### ArrayList

An ArrayList is implemented using a dynamic array. It provides similar functionality to Python's built-in list data structure.

File: `ArrayList.py`

### DLinkedList

A double linked list (DLinkedList) implementation, allowing for efficient insertion, deletion, and traversal of elements.

File: `DLinkedList.py`

### Queue1

A queue implementation using a double linked list (DLinkedList). Queues follow the first-in-first-out (FIFO) principle.

File: `Queue1.py`

### Stack1

A stack implementation using a double linked list (DLinkedList). Stacks follow the last-in-first-out (LIFO) principle.

File: `Stack1.py`

### BinarySearchTree (BST)

A binary search tree (BST) implementation, supporting insertion, deletion, and search operations with logarithmic time complexity.

File: `BinarySearchTree.py`

## How to Use

Each data structure is provided as a separate Python file. You can use these files by importing them into your Python projects or running them directly to see their functionality.

```python
# Example usage of ArrayList
from ArrayList import ArrayList

# Create an instance of ArrayList
arr_list = ArrayList()

# Perform operations on the ArrayList
arr_list.append(1)
arr_list.append(2)
arr_list.append(3)
print(arr_list)

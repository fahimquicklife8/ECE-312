BST312.h - Binary Search Tree (BST) Implementation

Author: Fahim Imtiaz (EID: fmi89)

Description:
BST312.h is a header file containing the implementation of a templated Binary Search Tree (BST) class in C++. 
The class can work with any data type or object. It provides functions for inserting, deleting, and traversing elements in the BST. 
The BST follows the standard rules where elements greater than the current node are placed to the right, and elements less than the current node are placed to the left. 
The provided traversals include pre-order, in-order, and post-order.

Files:
1. BST312.h - Header file with the BST class implementation.

Implementation Details:
- The BST class contains private TreeNode struct representing the individual nodes of the tree.
- Public member functions include insertItem, deleteItem, makeEmpty, isEmpty, isFull, countNodes, and traversals (pre-order, in-order, post-order).
- Helper functions are used for recursion in various operations.
- The copy constructor creates a deep copy of the BST.

Usage:
1. Include BST312.h in your C++ project.
2. Create a BST object with the desired data type: BST_312<DataType> bst;
3. Use insertItem, deleteItem, and traversals to interact with the BST.

Feel free to reach out if you have any questions or need assistance.

Enjoy using the Binary Search Tree (BST) implementation!

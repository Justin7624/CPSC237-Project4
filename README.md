# CPSC237-Project4
# Binary Search Tree Implementation

## Overview
This project implements a **templated Binary Search Tree (BST)** in C++, supporting insertion, deletion, search, and traversal. It includes an **interactive test program** allowing users to manipulate the tree via command-line input.

## Features
- **Templated Binary Search Tree** (`BinarySearchTree.h`, `BinarySearchTree.cpp`)
  - Insert, search, delete nodes
  - Handles duplicate values with a count mechanism
  - In-order, pre-order, post-order, and breadth-first traversal
- **Interactive Test Program** (`Treetest.cpp`)
  - Users can add, remove, and print the tree interactively
- **Input Handling** (`input.txt`, `test1.txt`)
  - Sample test files for automated testing
- **Documentation** (`Doxyfile` for generating documentation)

## Usage
### Compilation
To compile the project, use the provided **Makefile**:
```bash
make
```
This will generate an executable named `tree`.

### Running the Program
Run the interactive test program with:
```bash
./tree
```
### Interactive Menu Options
Upon running, the program provides a menu:
```
A)dd   R)emove   P)rint   T)ree Print   Q)uit
```
Users can input letters (case-insensitive) to interact with the tree.

### Cleaning Up
To remove compiled files:
```bash
make clean
```

## Code Structure
- `BinarySearchTree.h` - Defines the BST class.
- `BinarySearchTree.cpp` - Implements BST operations.
- `Treetest.cpp` - Interactive program for testing BST.
- `input.txt`, `test1.txt` - Sample input files.
- `Doxyfile` - Configuration for generating documentation.
- `makefile` - Compilation and cleanup rules.

## Error Handling
- Handles **duplicate values** by keeping a count instead of rejecting duplicates.
- Provides **user prompts** for removing single or all copies of a value.
- Ensures **valid input handling** in interactive mode.
- Prevents **deletion of non-existent values** with appropriate messages.

## Author
- **Justin Allen**

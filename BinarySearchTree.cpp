/*!   \file BinarySearchTree.cpp
*         \brief Binary Tree ADT implemented with TreeNode linked structures
*     
*    This file contains the implementation of the 
*    BinarySearchTree class, which is a binary tree ADT       
*    implemented using TreeNode linked structures.
*/

/*******************************************************************/
/*    Author:        Justin Allen                                  */
/*    Course:        CSC237                                        */
/*    Date:          4/20/24                                       */
/*    Filename:      BinarySearchTree.cpp                          */
/*    Description:   This file contains the implementation of the  */
/*    BinarySearchTree class, which is a binary tree ADT           */
/*    implemented using TreeNode linked structures.                */
/*                                                                 */
/*******************************************************************/
#include <iostream>
#include <string>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

// Constructor
/*!
   \brief Constructor for BinaryTree class.
  
   \tparam treeEltType The type of elements stored in the tree.
 */
template <typename treeEltType>
BinaryTree<treeEltType>::BinaryTree() {
    root = nullptr;
}

// Place Element into Tree
// Returns 1 if inserted, 0 if data already in tree
// Note any changes to this function here:
// None
/*!
   \brief Inserts an element into the tree.
  
   \tparam treeEltType The type of elements stored in the tree.
   \param data The element to be inserted.
   \return int 1 if inserted, 0 if data already in tree.
 */
template <typename treeEltType>
int BinaryTree<treeEltType>::insertToTree(const treeEltType &data) {
    if (root == nullptr) { // Empty Tree
        root = new TreeNode<treeEltType>(data);
        return 1;
    }
    // Search for spot to put data; We only stop when we get to the bottom (nullptr)
    TreeNode<treeEltType> *t = root, *parent;
    while (t != nullptr) {
        if (t->info == data) { // Data already in Tree
            t->count++;
            return 0;
        }
        parent = t; // Set the trail pointer to the ancestor of where we're going
        if (data < t->info)
            t = t->left;
        else
            t = t->right;
    }
    // Found the spot; insert node.
    if (data < parent->info)
        parent->left = new TreeNode<treeEltType>(data);
    else
        parent->right = new TreeNode<treeEltType>(data);
    return 1;
}

// Search for Element in Tree
// Assumes == is defined for treeEltType
// Returns Ptr to Elt if Found, NULL otherwise
// Note any changes to this function here:
// None
/*!
   \brief Searches for an element in the tree.
   
   \tparam treeEltType The type of elements stored in the tree.
   \param key The element to search for.
   \return treeEltType* Pointer to the element if found, nullptr otherwise.
 */
template <typename treeEltType>
treeEltType *BinaryTree<treeEltType>::treeSearch(const treeEltType &key) {
    TreeNode<treeEltType> *t = root;
    while (t && t->info != key) {
        if (key < t->info)
            t = t->left;
        else
            t = t->right;
    }
    if (t)
        return &(t->info);
    return nullptr;
}

// Retrieve Element from Tree (leaving Tree Intact)
// Precondition: Item is in Tree
// Note any changes to this function here:
// None
/*!
 * \brief Retrieves an element from the tree, leaving the tree intact.
 * 
 * \tparam treeEltType The type of elements stored in the tree.
 * \param key The element to retrieve.
 * \return treeEltType& Reference to the retrieved element.
 */
template <typename treeEltType>
treeEltType &BinaryTree<treeEltType>::retrieveFromTree(const treeEltType &key) {
    TreeNode<treeEltType> *t;
    for (t = root; t->info != key;) {
        if (key < t->info)
            t = t->left;
        else
            t = t->right;
    }
    return t->info;
}

// Remove an Element from the tree
// Precondition: Element is in the Tree
// Note any changes to this function here:
// Added check for existence of value being deleted,
// handles cases where the value is not found.
//
// Added handling for when there are multiple copies of the same element,
// prompts user to choose whether to remove one(O) or all(A) copies.
//
// Added handling of one child(left or right), and handling of two children.
//
// Added handling of deleting the root node.
/*!
   \brief Removes an element from the tree.
  
   Precondition: Element is in the Tree
  
   \tparam treeEltType The type of elements stored in the tree.
   \param data The element to be removed.
 */
template <typename treeEltType>
void BinaryTree<treeEltType>::deleteFromTree(const treeEltType &data) {
    TreeNode<treeEltType> *nodeWithData, *nodeToDelete, *t = root, *trailT = nullptr;
    // Find spot
    while (t->info != data) {  // Safe because of precondition
        trailT = t;
        if (data < t->info)
            t = t->left;
        else
            t = t->right;

        // Check if the value does not exist in the tree
        if (!t) {
            cout << "Value not found in the tree." << endl;
            return;
        }
    }
    nodeWithData = t; // Hold onto the data Node for later deletion

    // Handle multiple copies removal
    if (nodeWithData->count > 1) {
        char choice;
        cout << "There are " << nodeWithData->count << " copies of " << data << ". Remove One (O) or All (A)? ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'O') {
            nodeWithData->count--;
            return;
        } else if (choice == 'A') {
            nodeWithData->count = 0;
            return;
        }
    }

    // Case 1: Leaf node
    if (!nodeWithData->left && !nodeWithData->right) {
        if (nodeWithData == root)
            root = nullptr;
        else if (trailT->right == nodeWithData)
            trailT->right = nullptr;
        else
            trailT->left = nullptr;
        nodeToDelete = nodeWithData;
    } 
    // Case 2: One child
    else if (!nodeWithData->left) {
        if (!trailT) {
            nodeToDelete = root;
            root = root->right;
        } else {
            if (trailT->right == nodeWithData)
                trailT->right = nodeWithData->right;
            else
                trailT->left = nodeWithData->right;
            nodeToDelete = nodeWithData;
        }
    } else if (!nodeWithData->right) {
        if (!trailT) {
            nodeToDelete = root;
            root = root->left;
        } else {
            if (trailT->right == nodeWithData)
                trailT->right = nodeWithData->left;
            else
                trailT->left = nodeWithData->left;
            nodeToDelete = nodeWithData;
        }
    } 
    // Case 3: Two children
    else {
        TreeNode<treeEltType> *temp = nodeWithData->left;
        TreeNode<treeEltType> *trailTemp = nullptr;
        while (temp->right) {
            trailTemp = temp;
            temp = temp->right;
        }
        nodeWithData->info = temp->info;
        if (trailTemp)
            trailTemp->right = temp->left;
        else
            nodeWithData->left = temp->left;
        nodeToDelete = temp;
    }

    delete nodeToDelete;
}

// Need Helper to Recursively Print the Tree
// Note any changes to this function here:
// Added a check for multiple copies of the same element (t->count > 1) and modified the 
// print statement accordingly to include the count of copies if applicable.
template <typename treeEltType>
void BinaryTree<treeEltType>::printInorder(TreeNode<treeEltType> *t) const {
    if (t) {
        printInorder(t->left);
        if (t->count > 1) {
            cout << t->info << " (" << t->count << ")" << endl;
        } else {
            cout << t->info << endl;
        }
        printInorder(t->right);
    }
}

// Display Tree using InOrder Traversal
/*!
   \brief Perform an inorder traversal of the binary tree.

   This function traverses the binary tree in inorder fashion, visiting nodes
   in the order left, root, right.

   \tparam treeEltType The type of elements stored in the tree.
 */
template <typename treeEltType>
void BinaryTree<treeEltType>::inorder() const {
    printInorder(root);
}

// Need Helper to Recursively Print the Tree
// Note any changes to this function here:
// None
template <typename treeEltType>
void BinaryTree<treeEltType>::printPreorder(TreeNode<treeEltType> *t) const {
    if (t) {
        cout << t->info << endl;
        printPreorder(t->left);
        printPreorder(t->right);
    }
}

// Display Tree using PreOrder Traversal
/*!
   \brief Perform a preorder traversal of the binary tree.

   This function traverses the binary tree in preorder fashion, visiting nodes
   in the order root, left, right.

   \tparam treeEltType The type of elements stored in the tree.
 */
template <typename treeEltType>
void BinaryTree<treeEltType>::preorder() const {
    printPreorder(root);
}

// Need Helper to Recursively Print the Tree
template <typename treeEltType>
void BinaryTree<treeEltType>::printPostorder(TreeNode<treeEltType> *t) const {
// Note any changes to this function here:
// None
    if (t) {
        printPostorder(t->left);
        printPostorder(t->right);
        cout << t->info << endl;
    }
}

// Display Tree using PostOrder Traversal
/*!
   \brief Perform a postorder traversal of the binary tree.

   This function traverses the binary tree in postorder fashion, visiting nodes
   in the order left, right, root.

   \tparam treeEltType The type of elements stored in the tree.
 */
template <typename treeEltType>
void BinaryTree<treeEltType>::postorder() const {
    printPostorder(root);
}
/*!
   \brief Print the binary tree using a queue-based traversal.

   This function prints the binary tree using a queue-based approach,
   ensuring that nodes are printed level by level.

   \tparam treeEltType The type of elements stored in the tree.
 */
template <typename treeEltType>
void BinaryTree<treeEltType>::treePrint() const {
    treePrintHelper(root);
}
// Brief description: This function uses a queue-based approach to traverse and print the tree.
// Nodes are printed with their data, and if a node has multiple copies, the count is displayed 
// in parentheses next to the data.
// Note any changes to this function here:
// Display the tree with node counts in parentheses for multiple data
/*!
   \brief Display Tree using InOrder Traversal
   
   \tparam treeEltType The type of elements stored in the tree.
   \param t Pointer to the current node being visited during traversal.
 */
template <typename treeEltType>
void BinaryTree<treeEltType>::treePrintHelper(TreeNode<treeEltType> *root) const
{
    queue<TreeNode<treeEltType> *> Q;
    TreeNode<treeEltType> *dummy = new TreeNode<treeEltType>(-1);
    if (root) {
        Q.push(root);
        Q.push(dummy);
    }
    TreeNode<treeEltType> *t = root;
    while (!Q.empty()) {
        t = Q.front();
        Q.pop();
        if (t == dummy) {
            if (!Q.empty())
                Q.push(dummy);
            cout << endl;
        } else if (t) {
            // Print the node info with count in parentheses for multiple data
            if (t->count > 1)
                cout << t->info << "(" << t->count << ")" << " ";
            else
                cout << t->info << " ";

            Q.push(t->left);
            Q.push(t->right);
        }
    }
}


template class BinaryTree<int>;  // Explicit instantiation for int type

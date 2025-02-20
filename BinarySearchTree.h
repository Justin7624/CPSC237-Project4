/*!   \file BinarySearchTree.h
 *        \brief A header file containing Binary Tree ADT defined using Linked Structures
 *
 *  
 */
/*******************************************************************/
/*    Author:       Justin Allen                                   */
/*    Course:       CSC237                                         */
/*    Date:         4/20/24                                        */
/*    Filename:     BinarySearchTree.h                             */
/*    Description:  Binary Tree ADT defined using Linked Structures*/
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <queue>

template <typename treeEltType> class BinaryTree;
/*!
   \brief TreeNode class representing a node in a binary tree.
   
   \tparam eltType The type of element stored in the node.
 */
template <typename eltType>
class TreeNode {
private:
    eltType info;
    int count;  // Number of copies of info in the tree
    TreeNode<eltType> *left, *right;
/*!
     \brief Private constructor for TreeNode class.
     
     \param data The data to be stored in the node.
     \param lChild Pointer to the left child node.
     \param rChild Pointer to the right child node.
   */
    TreeNode(const eltType &data, TreeNode<eltType> *lChild = nullptr, TreeNode *rChild = nullptr)
        : info(data), count(1), left(lChild), right(rChild) {}

    friend class BinaryTree<eltType>;
};
/*!
   \brief BinaryTree class representing a binary search tree.
   
   \tparam treeEltType The type of elements stored in the tree.
 */
template <typename treeEltType>
class BinaryTree {
public:
    // Constructor
    BinaryTree();

    // Place Element into Tree
    // Returns 1 if inserted, 0 if Data already in tree
    int insertToTree(const treeEltType &data);

    // Search for Element in Tree
    // Assumes == is defined for treeEltType
    // Returns pointer to data, or NULL, according to success
    treeEltType *treeSearch(const treeEltType &data);

    // Retrieve Element from Tree (leaving Tree Intact)
    // Precondition: Item is in Tree
    treeEltType &retrieveFromTree(const treeEltType &data);

    // Remove an Element from the tree
    // Pre: Element is in the Tree
    void deleteFromTree(const treeEltType &data);

    // Display Tree using InOrder Traversal
    void inorder() const;

    // Display Tree using PreOrder Traversal
    void preorder() const;

    // Display Tree using PostOrder Traversal
    void postorder() const;

    // Breadth-first print
    void treePrint() const;

private:
    TreeNode<treeEltType> *root;

    // Helper functions for tree operations
    void printInorder(TreeNode<treeEltType> *) const;
    void printPreorder(TreeNode<treeEltType> *) const;
    void printPostorder(TreeNode<treeEltType> *) const;
    void treePrintHelper(TreeNode<treeEltType> *) const;
};

#endif

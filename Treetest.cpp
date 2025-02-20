/*!   \file TreeTest.cpp
*         \brief Driver for Binary Tree ADT
*         
*        This file contains the test driver for the Binary Search Tree.
 */
/*******************************************************************/
/*    Author:        Justin Allen                                  */
/*    Course:        CSC237                                        */
/*    Date:          4/20/24                                       */
/*    Filename:      Treetest.cpp                                  */
/*    Description:                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/
#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

typedef BinaryTree<int> IntTree;

char getChoice(string ok);
void addToTree(IntTree &TheTree);
void removeFromTree(IntTree &TheTree);

/*!
   \brief Reverses the input string.
   
   \param str The string to be reversed.
   \return The reversed string.
 */
string reverse_string(string str) {
    return string(str.rbegin(), str.rend());
}

int main() {
    IntTree Tree;
    int entry;
    char Choice;
    do {
        cout << "Select: A)dd    R)emove     P)rint     T)ree Print     Q)uit\n";
        Choice = getChoice("ARPTQ");
        switch (Choice) {
            case 'A':
                addToTree(Tree);
                break;
            case 'P':
                cout << "The Tree:" << endl;
                Tree.inorder();
                break;
            case 'R':
                removeFromTree(Tree);
                break;
            case 'T':
                cout << "The tree, as it appears (sort of)..\n";
                Tree.treePrint();
                break;  // Added break statement here
        }
    } while (Choice != 'Q');
}
/*!
   \brief Reads a character from input and checks if it is in the given string.
   
   \param ok A string containing valid characters.
   \return The valid character entered by the user.
 */
char getChoice(string ok) {
    char ch = ' ';
    do ch = toupper(cin.get()); while (ok.find(ch) == string::npos);
    cin.get(); // eat CR
    return (toupper(ch));
}
/*!
   \brief Prompts the user to enter an integer and adds it to the tree.
   
   \param TheTree The binary search tree to add the integer to.
 */
void addToTree(IntTree &TheTree) {
    int entry;
    cout << " Enter an Integer >";
    cin >> entry;
    TheTree.insertToTree(entry);
}
/*!
   \brief Prompts the user to enter an integer and removes it from the tree.
   
   \param TheTree The binary search tree to remove the integer from.
 */
void removeFromTree(IntTree &TheTree) {
    int entry;
    cout << "Value to Delete? >";
    cin >> entry;
    TheTree.deleteFromTree(entry);  // Updated to handle multiple copies removal
}

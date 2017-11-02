/*PA2
 *Name 1: Khelsey Gozum // A12070231
 *Name 2: Eliott Ham // A13186685
 *Date: October 26, 2017
 *Overview of DictionaryBST.h: Declare the functions necessary for the cpp file
 * and add data member of bst
 */
#ifndef DICTIONARY_BST_H
#define DICTIONARY_BST_H
#include <set>
#include <string>

/**
 *  The class for a dictionary ADT, implemented as a BST
 * When you implement this class, you MUST use a balanced binary
 * search tree in its implementation.  The C++ set implements 
 * a balanced BST, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryBST
{
public:

  /* Create a new Dictionary that uses a BST back end */
  DictionaryBST();

  /* Insert a word into the dictionary. */
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryBST();

private:
  // Add your own data members and methods here
  set<string> *bst;
};

#endif // DICTIONARY_BST_H

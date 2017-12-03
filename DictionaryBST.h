/*
 *Overview of DictionaryBST.h: Declare the functions necessary for the cpp file
 * and add data member of bst
 */

#ifndef DICTIONARY_BST_H
#define DICTIONARY_BST_H
#include <set>
#include <string>

/**
 * The class for a dictionary ADT, implemented as a BST
 * When you implement this class, you MUST use a balanced binary
 * search tree in its implementation.  The C++ set implements 
 * a balanced BST, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryBST
{
public:

  /* create a new Dictionary that uses a BST back end */
  DictionaryBST();

  /* insert a word into the dictionary. */
  bool insert(std::string word);

  /* return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* destructor */
  ~DictionaryBST();

private:
  set<string> *bst;
};

#endif // DICTIONARY_BST_H

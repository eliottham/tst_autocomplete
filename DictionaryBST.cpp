/*PA2
 *Name 1: Khelsey Gozum // A12070231
 *Name 2: Eliott Ham // A13186685
 *Date: October 26, 2017
 *Overview of DictionaryBST.cpp: Implemetnation of a balanced binary search
 *  tree to store and find words in the dictionary.  Utilizes C++ set to 
 *  store and find the words in the dictionary
 */

using namespace std;
#include "util.h"
#include "DictionaryBST.h"
#include <set>
#include <string>

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
  bst = new set<string>;
}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  //initializes the iterator and the retainer, which is a set and a bool
  set<string>::iterator it;
  pair<set<string>::iterator,bool> ret;
  
  //calls insert into the retainer 
  ret = bst->insert(word);

  return ret.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  //iterates through the iterator to find the word
  set<string>::iterator inBST = bst->find(word);

  //if it reaches past the end, it did not find the word, returns false
  if(inBST == bst->end()){
    return false;
  }
  else{
    return true;
  }
}

/* Destructor */
DictionaryBST::~DictionaryBST(){
  //deletes the bst object
  delete bst;
}

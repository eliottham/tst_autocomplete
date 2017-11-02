/*PA2
 *Name 1: Khelsey Gozum // A12070231
 *Name 2: Eliott Ham // A13186685
 *Date: October 26, 2017
 *Overview of DictionaryHashtable.cpp: Uses a hashtable data structure to 
 *  store words in a dictionary.  Implements C++ STL unordered_set to store
 *  and find the words in the dictionary. 
 */

using namespace std;
#include "util.h"
#include "DictionaryHashtable.h"
#include <unordered_set>
#include <utility>
#include <string>

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
  hash = new unordered_set<string>;
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(string word){
  //initialize the retainer and inserts the word in the dictionary
  auto ret = hash->insert(word);
  return ret.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(string word) const{
  //iterator iterates through to find the word in the dictionary
  unordered_set<string>::iterator inHashTable = hash->find(word);
  if(inHashTable == hash->end()){
    return false;
  }
  else{
    return true;
  }
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){
  //deletes the hash object
  delete hash;
}

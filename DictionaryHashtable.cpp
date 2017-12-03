/*
 * Overview of DictionaryHashtable.cpp: Uses a hashtable data structure to 
 * store words in a dictionary.  Implements C++ STL unordered_set to store
 * and find the words in the dictionary. 
 */

using namespace std;
#include "util.h"
#include "DictionaryHashtable.h"
#include <unordered_set>
#include <utility>
#include <string>

/* create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
  hash = new unordered_set<string>;
}

/* insert a word into the dictionary. */
bool DictionaryHashtable::insert(string word){
  //initialize the retainer and inserts the word in the dictionary
  auto ret = hash->insert(word);
  return ret.second;
}

/* return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(string word) const{
  // iterator iterates through to find the word in the dictionary
  unordered_set<string>::iterator inHashTable = hash->find(word);
  if(inHashTable == hash->end()){
    return false;
  }
  else{
    return true;
  }
}

/* destructor */
DictionaryHashtable::~DictionaryHashtable(){
  //deletes the hash object
  delete hash;
}

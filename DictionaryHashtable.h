/*
 * Overview of DictionaryHashtable.h: Declare the functions necessary for 
 * the cpp file and add data member of the hashtable
 */

#ifndef DICTIONARY_HASHTABLE_H
#define DICTIONARY_HASHTABLE_H

#include <string>
#include <unordered_set>
/**
 * The class for a dictionary ADT, implemented as a Hashtable
 * When you implement this class, you MUST use a Hashtable
 * in its implementation.  The C++ unordered_set implements 
 * a Hashtable, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryHashtable
{
public:

  /* create a new Dictionary that uses a Hashset back end */
  DictionaryHashtable();

  /* insert a word into the dictionary. */
  bool insert(std::string word);

  /* return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* destructor */
  ~DictionaryHashtable();

private:
  unordered_set <string> *hash;
};

#endif // DICTIONARY_HASHTABLE_H

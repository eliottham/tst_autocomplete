/*PA2
 *Name 1: Khelsey Gozum // A12070231
 *Name 2: Eliott Ham // A13186685
 *Date: October 26, 2017
 *Overview of DictionaryHashtable.h: Declare the functions necessary for 
 * the cpp file and add data member of the hashtable
 */

#ifndef DICTIONARY_HASHTABLE_H
#define DICTIONARY_HASHTABLE_H

#include <string>
#include <unordered_set>
/**
 *  The class for a dictionary ADT, implemented as a Hashtable
 * When you implement this class, you MUST use a Hashtable
 * in its implementation.  The C++ unordered_set implements 
 * a Hashtable, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryHashtable
{
public:

  /* Create a new Dictionary that uses a Hashset back end */
  DictionaryHashtable();

  /* Insert a word into the dictionary. */
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryHashtable();

private:
  // Add your own data members and methods here
  unordered_set <string> *hash;
};

#endif // DICTIONARY_HASHTABLE_H

/*
 * Overview of DictionaryTrie.h: Declare the functions necessary for the cpp file
 * and add data member of TST.  Implementation of a TSTNode class to use for 
 * the nodes in the TST
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H
using namespace std;
#include <vector>
#include <string>

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class TSTNode
{
  public: 
    char value;
  	TSTNode* left;
  	TSTNode* right;
  	TSTNode* middle;
  	bool endOfString;
  	unsigned int frequency;
  	//constructor
  	TSTNode(const char &d);
};

class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  
  /* Destructor */
  ~DictionaryTrie();

private:
  TSTNode* root;
  void deleteAll(TSTNode* n);
};

/*Helper function for predictCompletions: compares freqs of words*/
bool sortHelper(const pair<string, unsigned int> &pair1, const pair<string, unsigned int> &pair2);
#endif // DICTIONARY_TRIE_H

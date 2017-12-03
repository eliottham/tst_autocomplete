/*
 * Overview of DictionaryTrie.cpp: Implemetnation of a ternary search tree to 
 * store words in the dictionary and also find those words.
 */

using namespace std;
#include "util.h"
#include "DictionaryTrie.h"
#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

/* create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie() : root(nullptr) {}

/* initialize constructor */
TSTNode::TSTNode(const char &d) : value(d), left(0), right(0), middle(0), 
                 endOfString(false), frequency(0) {}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  // check for if the word length to be inserted is empty
  if(word.length() == 0){
    return false;
  }
 
  // set TSTNode to root
  TSTNode * current = root;
  
  // if there is no root
  if(!root) {
    // create the root with the value of the first letter of the word
    root = new TSTNode(word[0]);
    current = root;

    /* traverse through the word and create nodes for each letter after the 
       initial first letter */ 
    for(unsigned int k = 1; k < word.length(); k++) {
      current->middle = new TSTNode(word[k]);
      current = current->middle;
      
      // once you reach the last letter, set the words frequency and denotes
      // the end of the string
      if((k == word.length() - 1)) {
	     current->frequency = freq;
	     current->endOfString = true;
        return true;
      }
    }      
  }

  unsigned int i = 0;

  while(1){
    /* compare to see if the current letter of the word is of smaller value
     * than the current nodes value*/
    if(word[i] < current->value) {

      // set current to current-> left if theres a left child
      if(current->left) { 
        current = current->left;
        continue;
      }
  
      // create a new node if there is no possible left child for the word
      current->left = new TSTNode(word[i]);
      current = current->left;
      i++;
      break;

    }

    /* compare to see if the current letter of the word is of greater value 
     * than the current nodes value*/
    if(word[i] > current->value) {

      // set current to current-> if theres a right child      
      if(current->right) {
	     current = current->right;
	     continue;
      }

      // create a new node if there is no possible right child for the word
      current->right = new TSTNode(word[i]);
      current = current->right;
      i++;
      break;
    }

    /* check if the current letter equal the current value*/ 
    if(word[i] == current->value) {
      if((i == word.length() - 1) && current->endOfString == true) {
        // switch frequencies depending if duplicate has greater freq
	     if(current->frequency > freq) {
	       return false;
        }
        // if the new frequency is greater, change to this frequency
      current->frequency = freq;
	     return false;
      }

      // if i is on the last letter of the word break out of the loop
      if(i == word.length() - 1) {
        i++;
        break;
      }  
      // if the current node has a middle child change current to that child 
      // and continue
      if(current->middle) {
	     current = current->middle;
        i++;
	     continue;
      }
      // if not increment i so that we are at the next level and break
      i++;
      break;
    }
  }
 
  // if i is the length of the word or the word is 1 letter
  if(i == word.length()|| word.length() == 1) {
    // we make the current node a word node 
    current->endOfString = true;
    current->frequency = freq;
    return true;
  }
  
  // we add on the new nodes to the existing prefix
  for(unsigned int j = i; j < word.length(); j++) {
    current->middle = new TSTNode(word[j]);      
    current = current->middle;
    // we create the word node as the last letter of the word
    if(j == word.length() - 1) {
      current->frequency = freq;
      current->endOfString = true;
      return true;
    }
  }

  return false;
}

/* return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  TSTNode * current = root;
  
  // if the tree is empty 
  if(!root){
    return false;
  }

  // set the counter to 0
  unsigned int i = 0;
  
  while(1) {
    // if the letter at  the index is less than current's value, traverse to 
    // the left of the tree 
    if(word[i] < current->value) {
      if(current->left) { 
        current = current->left;
	      continue;
      }
      break;
    }

    // if the letter at  the index is greater than current's value, traverse to 
    // the right of the tree 
    if(word[i] > current->value) {
      if(current->right) {
        current = current->right;
	      continue;
      }
      break;
    }
    
    // if the letter at  the index is equal than current's value, traverse to 
    // the middle of the tree 
    if(word[i] == current->value) {
      // if it matches till the word's last value and end of string is denoted
      // word has been found
      if((i == word.length() - 1) && current->endOfString) {
        return true;
      }
    
      // continue to interate, changing the current till above if stmt is holds
      i++;
      if(current->middle) {
        current = current->middle;
	      continue;
      }
      break;
    }
  }

  
  return false;
}

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
vector<string> DictionaryTrie::predictCompletions(string prefix, unsigned int num_completions)
{
  vector<string> words;
  vector<pair<string,unsigned int>> wordPairs;

  /*Invalid input checks*/

  // case where the prefix is an empty string 
  if(prefix.empty()){
    cerr << "Invalid Input. Please retry with correct input" << endl;
    return words;
  }

  // case where num_completions is less than 0
  if(num_completions < 0){
    cerr << "Invalid Input. Please retry with correct input" << endl;
    return words;
  }

  // case where prefix contains non-dictionary characters
  for(unsigned int i = 0; i < prefix.length(); i++){
    if((char)prefix[i] < 'a' || (char)prefix[i] > 'z'){
      cerr << "Invalid Input. Please retry with correct input" << endl;
      return words;
    }
  }

  TSTNode * current = root;
  
  // set the counter to 0
  unsigned int i = 0;

  while(1) {
    // if the letter at  the index is less than current's value, traverse to 
    // the left of the tree 
    if(prefix[i] < current->value) {
      if(current->left) { 
        current = current->left;
	      continue;
      }
      return words;
    }

    // if the letter at  the index is greater than current's value, traverse to 
    // the right of the tree 
    if(prefix[i] > current->value) {
      if(current->right) {
        current = current->right;
	      continue;
      }
      return words;
    }
    
    // if the letter at  the index is equal than current's value, traverse to 
    // the middle of the tree 
    if(prefix[i] == current->value) {
      i++;
      // breaks out of while when we found the prefix in the tree 
      if(i == prefix.length()) {
	    break;
      }
      // continues to iterate if there is a middle child
      if(current->middle) {
        current = current->middle;
	      continue;
      }
      break;
    }

  }

  // initialize queue
  queue<TSTNode*> q;
  string suffix = "";
  
  // pushes current-> middle to the queue
  if(current->middle) {
    q.push(current->middle);
  }  

  // computes while the queue is not empty
  while(!q.empty()) {
    // set to an empty string
    suffix = "";
   
    current = q.front();
    q.pop();
   
    // recursively push available left children 
    if(current->left) {
      q.push(current->left);
    }

    // recursively push available right children
    if(current->right) {
      q.push(current->right);
    }

  
    while(1){
      // append the suffix
      suffix = suffix + current->value;

      // we know its the end of the word, we add the word and freq to a vector  
      if(current->endOfString) { 
        wordPairs.push_back(make_pair((prefix + suffix), current->frequency));
      }

      // continues to iterate if theres a middle child, breaks if not
      if(!current->middle) {
	     break;
      }
      current = current->middle;
    }
  }
  
  // sorts the elements in the vector by frequency
  sort(wordPairs.begin(), wordPairs.end(), sortHelper);
  
  // adds the sorted words into the vector
  for(unsigned int i = 0; i < wordPairs.size(); i++) {
    words.push_back(wordPairs[i].first);
    if(i == num_completions - 1) {
      break;
    }
  }

  return words;
}    
  

/* Sort Helper
 *  Purpose: helper method to compare the frequencies of the words
 *  Input: pair<string, unsigned int>
 *  Output: bool indicating if first pair has greater freq than second
 * */
bool sortHelper(const pair<string, unsigned int> &pair1, const pair<string, unsigned int> &pair2)
{
  return pair1.second > pair2.second;
}

/* Destructor Helper */
void DictionaryTrie::deleteAll(TSTNode* n)
{
  if(n == nullptr){
    return;
  }

  // recursively delete while n has a left child
  if(n->left){
   deleteAll(n->left);
  }

  // recursively delete while n has a right child
  if(n->right){
   deleteAll(n->right);
  }

  // recursively delete while n has a middle child
  if(n->middle){
    deleteAll(n->middle);
  }

  delete n;

  n = nullptr;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
  deleteAll(root);
}

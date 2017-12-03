/* Overview of benchhash.cpp: Compare the efficiency of two different hash functions. */

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <typeinfo>
using namespace std;

// first hash function
unsigned int hash_1(string str, unsigned int table_size);

// second hash function and constants used in it
unsigned int hash_2(string str, unsigned int table_size);
#define A 54059
#define B 76963
#define FIRSTH 37

// helper function to print the statistics of each hash function
void hash_stats(vector<int> index_hits, const unsigned int table_size, int fn_id);

int main(int argc, char* argv[])
{

  // check for proper number of arguments 
  if(argc != 3) {
    cerr << "Expected arguments: ./benchhash dictfile num_words" << endl;
    return -1;
  }

  // file used to gain words
  string dictfile = argv[1];

  // number of words to get from the dictionary
  char* endPtr;
  unsigned int num_words = strtol(argv[2], &endPtr, 10);

  // initialize ifstream
  ifstream infile;
  
  // check that dictfile is a valid file  
  infile.open(dictfile, ios::binary);
  if(!infile.good()) { 
    cerr << "Please use a valid file for dictfile." << endl;
    return -1;
  }
 
  // check that num_words is a valid int
  if(*(endPtr + 1) == NULL) {
    cerr << "Please use a valid number for num_words." << endl;
    return -1;
  }
 
  // variable to gain word from file and store into words vector
  string word;
  vector<string> words;

 /*---------------------------------------------------------------------------------
 The following commented out code was to verify the expected output of each function.
 ----------------------------------------------------------------------------------*/
/*
  // compare hash indexes returned by hash_1 to those done by hand
  cout << "\n~~~ Testing expected hash values for hash_1, table size 4. ~~~" << endl;

  vector<pair<string, int>> word_vals;
  
  // push in strings with the hash index gained from the code by hand
  word_vals.push_back(make_pair("cat", 2));
  word_vals.push_back(make_pair("dogs", 3));
  word_vals.push_back(make_pair("hash", 2));

  for(unsigned int i = 0; i < word_vals.size(); i++) {
    if(hash_1(word_vals[i].first, 4) == word_vals[i].second) {
      cout << "String '" << word_vals[i].first << "' returns expected value." << endl;
    }
    else {
      cout << "String '" << word_vals[i].first << "' did not return expected value." << endl;
    }
  }

  cout << "End of testing for hash_1." << endl;

  // compare hash indexes returned by hash_2 to those done by hand 
  cout << "\n~~~ Testing expected hash values for hash_2, table size 4. ~~~" << endl;
  
  word_vals.clear();
  
  // push in strings with the hash index gained from the code by hand
  word_vals.push_back(make_pair("cat", 3));
  word_vals.push_back(make_pair("dogs", 2));
  word_vals.push_back(make_pair("hash", 1));

  for(unsigned int i = 0; i < word_vals.size(); i++) {
    if(hash_2(word_vals[i].first, 4) == word_vals[i].second) {
      cout << "String '" << word_vals[i].first << "' returns expected value." << endl;
    }
    else {
      cout << "String '" << word_vals[i].first << "' did not return expected value." << endl;
    }
  }

  cout << "End of testing for hash_2." << endl;
*/
  // taking a collection of words from the dictionary
  for(unsigned int i = 0; i < num_words; i++) {
    getline(infile, word);
    words.push_back(word);
  }

  infile.close();

  // printing statistics of each hash function
  
  int index; // calculated index of the hash table
  const unsigned int table_size = 2 * num_words; // size of the simulated hash table
  vector<int> index_hits(table_size); // the # of hits a given index gets mapped to

  // calculate the index of each string
  for(unsigned int i = 0; i < words.size(); i++) {
    index = hash_1(words[i], table_size); 
    index_hits[index] += 1;  // increment # strings that map to a given index
  }

  hash_stats(index_hits, table_size, 1); // print stats for hash_1

  // calculating statistics for hash function 2
  index_hits.clear();
  index_hits.resize(table_size);

  // calculate the index of each string
  for(unsigned int i = 0; i < words.size(); i++) {
    index = hash_2(words[i], table_size);
    index_hits[index] += 1; // increment # strings that map to a given index
  }

  hash_stats(index_hits, table_size, 2); // print stats for hash_2
  
  return 1;  
} 

void hash_stats(vector<int> index_hits, const unsigned int table_size, int fn_id)
{
  vector<int> table_hits(table_size);
  // count the # of slots that are hit i times
  for(unsigned int i = 0; i < table_size; i++) {
    // calculate the number of slots in the table that have index_hits  
    table_hits[index_hits[i]] += 1;
  }

  /* printing the results of the table collisions */
  cout << "\nPrinting statistics for hash function " << fn_id
       << " with table size " << table_size << endl;
  cout << "#hits\t#slots receiving that #hits" << endl;  

  // print the number of slots that had i hits
  unsigned int max_hit;
  for(unsigned int i = 0; i < table_size; i++) {
    if(table_hits[i] == 0) {
      max_hit = i - 1;
      break;
    }
    cout << i << "\t" << table_hits[i] << endl;
  }

  // calculate the average number of steps
  float avg_steps = 0;
  unsigned int step_sum = 0;
  for(unsigned int j = 1; j <= max_hit; j++) {
    for(unsigned int k = j; k <= max_hit; k++) {
      step_sum += table_hits[k];
    }
    avg_steps += step_sum * j;
    step_sum = 0;
  }

  avg_steps = avg_steps/(table_size/2);
  cout << "The average number of steps in a successful search for hash function "
           << fn_id << " would be " << avg_steps << endl;
  cout << "The worst case steps that would be needed to find a word is "
       << max_hit << endl;
}

/* first hash function taken from stackoverflow */
unsigned int hash_1(string str, unsigned int table_size)
{
  unsigned int hashval = 0;
  
  for(unsigned int i = 0; i < str.size(); i++) {
    hashval = (unsigned int)str[i] + 31 * hashval;
  }
  
  return hashval % table_size;
}

/* second hash function taken from stackoverflow */
unsigned int hash_2(string str, unsigned int table_size)
{
  unsigned int h = FIRSTH;
  for(unsigned int i = 0; i < str.size(); i++) {
    h = (h * A) ^ (str[i] * B);
  }

  return h % table_size;
}
  

/* Overview of benchdict.cpp: to test out the running times of each dictionary type. */

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<set>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"

using namespace std;

int main(int argc,char* argv[]) {

   // check if contains proper amount of arguments
   if(argc != 5){
       cerr << "Expected arguments: ./benchdict min_size step_size"
               " num_iterations dictfile" << endl;
       return -1;
   }

   // using stoi to get the inputted arguments as strings / ints
   int min_size = stoi(argv[1],nullptr);
   int step_size =stoi(argv[2],nullptr);
   int num_iterations = stoi(argv[3],nullptr);
   string dictfile = argv[4];

   // for when the word is taken from the stream and created as a word
   string word;

   // for the size of the dictionary file
   int dictsize = 0;

   // initialize data structures
   DictionaryBST* d_bst = new DictionaryBST();
   DictionaryHashtable* d_ht = new DictionaryHashtable();
   DictionaryTrie* dt = new DictionaryTrie();
   int t_bst, t_ht, tt;

   // initialize words
   vector<std::string> words;
   vector<string>::iterator wit;
   vector<string>::iterator wen;

   // initialize the ifstream
   ifstream infile;

   // initialize timer
   Timer dict_timer;

   // benching for the BST class
   cout << "DictionaryBST" << endl;
   for(int i = 0; i < num_iterations; i++){
       // open the file
       infile.open(dictfile, ios::binary);

       // load min_size + i*step_size words from the beginning of the dictionary file
       Utils::load_dict(*d_bst, infile, min_size + (i * step_size));

       // read the next 100 words from the dictionary file
       for(int i = 0; i < 100; i++){
           // extracts characters from infile and stores them into word
           getline(infile, word);

           // add the word to the vector of strings
           words.push_back(word);
       }

       /*Using the same 100 words, repeat the find process
       many times and take the average time of all the runs. 
       Be sure to time only the part when you are
       looking for the words in the dictionary.*/

       // start the timer
       // dict_timer.begin_timer();
       dictsize = min_size + i*step_size;
       wit = words.begin();
       wen = words.end();

       long time_BST = 0;

       // calculate the running time
       for(int i = 0; i < 20; i++) {
         wit = words.begin();
         wen = words.end();
         dict_timer.begin_timer();
         for(; wit != wen; ++wit) {
	         d_bst->find(*wit);
         }
         time_BST += dict_timer.end_timer();
       }

       // the avg is computed by dividing by amount of iterations inputted
       long avg_BST = ((time_BST) / 20);

       /* print the dictsize and the running time you calculated in step two to 
          standard out, separated by a tab (\t) */
       cout << dictsize << "\t" << avg_BST << endl;

       // close the file
       infile.close();
   }
   // delete dictionary object 
   delete d_bst;

   cout << "DictionaryHashtable" << endl;
   for(int i = 0; i < num_iterations; i++){
       // open the file
       infile.open(dictfile, ios::binary);

       // load min_size + i*step_size words from the beginning of the dictionary file
       Utils::load_dict(*d_ht, infile, min_size + (i * step_size));

       // read the next 100 words from the dictionary file
       for(int i = 0; i < 100; i++){
           // extracts characters from infile and stores them into word
           getline(infile, word);

           // add the word to the vector of strings
           words.push_back(word);
       }

       /*Using the same 100 words, repeat the find process
       many times and take the average time of all the runs. Be sure to time 
       only the part when you are
       looking for the words in the dictionary.*/

       dictsize = min_size + i*step_size;
       wit = words.begin();
       wen = words.end();

       long time_HT = 0;

       // calculate the running time 
       for(int i = 0; i < 20; i++) {
         wit = words.begin();
         wen = words.end();
         dict_timer.begin_timer();
         for(; wit != wen; ++wit) {
	         d_ht->find(*wit);
         }
         time_HT += dict_timer.end_timer();
       }

       // the avg is computed by dividing by amount of iterations inputted
       long avg_HT = ((time_HT) / 20);

       /* print the dictsize and the running time you calculated in step two to 
          standard out, separated by a tab (\t) */
       cout << dictsize << "\t" << avg_HT << endl;

       // close the file
       infile.close();
   }
   delete d_ht;


   cout << "DictionaryTrie" << endl;
   for(int i = 0; i < num_iterations; i++){
       // open the file
       infile.open(dictfile, ios::binary);

       // load min_size + i*step_size words from the beginning ofdictionary file
       Utils::load_dict(*dt, infile, min_size + (i * step_size));

       // read the next 100 words from the dictionary file
       for(int i = 0; i < 100; i++){
           // extracts characters from infile and stores them into word
           getline(infile, word);

           // add the word to the vector of strings
           words.push_back(word);
       }

       /*Using the same 100 words, repeat the find process
       many times and take the average time of all the runs. Be sure to 
       time only the part when you are
       looking for the words in the dictionary.*/

       dictsize = min_size + i*step_size;
       wit = words.begin();
       wen = words.end();

       long time_TT = 0;

       // find the running time 
       for(int i = 0; i < 20; i++) {
         wit = words.begin();
         wen = words.end();
         dict_timer.begin_timer();
         for(; wit != wen; ++wit) {
	         dt->find(*wit);
         }
         time_TT += dict_timer.end_timer();
       }

       // the avg is computed by dividing by amount of iterations inputted
       long avg_TT = ((time_TT) / 20);

       /* print the dictsize and the running time you calculated in step two to 
          standard out, separated by a tab (\t) */
       cout << dictsize << "\t" << avg_TT << endl;

       //close the file
       infile.close();
   }
   delete dt;
}



#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{

  // initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  // initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  // initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");
  words.push_back("harr");
  words.push_back("zoo");
  words.push_back("apple");
  words.push_back("p");
  words.push_back("harrys");
  
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      cout << t_bst << " " << t_ht << " "<< tt << "... ";
      
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      
      if(!tt)
	{
	  cout << "FAILED for DictionaryTrie... ";
	  cout << endl;
	}
      if(tt)
	{
          cout << endl;
	  cout << "insert PASSED for DictionaryTrie";
	  cout << endl;
	}
      
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl; 

    }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
        
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(!tt)
        {
	  cout << endl;
          cout << *wit << " PASSED for DictionaryTrie... ";
	  cout << endl;
        }
      if(tt)
        {
	  cout << endl;
          cout << *wit << " FAILED for DictionaryTrie... ";
	  cout << endl;
        }

      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;
/*
t_bst = d_bst.find("harr");
if(t_bst) {
  cout << "found harr" << endl;
}
t_bst = d_bst.find("apple");
if(t_bst) {
  cout << "found harry" << endl;
}
t_bst = d_bst.find("sriram");
if(t_bst) {
  cout << "found sriram" << endl;
}
t_bst = d_bst.find("crucio");
if(t_bst) {
  cout << "found crucio" << endl;
}
t_bst = d_bst.find("autocomplete");
if(t_bst) {
  cout << "found autocomplete" << endl;
} */
/*You are supposed to add more test cases in this file */
/*
tt = dt.find("harr");
 if(tt){
   cout << "found harr" << endl;
 }
 tt = dt.find("harry");
 if(tt){
   cout << "harry" << endl;
 } 
 tt = dt.find("harrys");
 if(tt){
   cout << "found harrys" << endl;
 } tt = dt.find("p");
 if(tt){
   cout << "found p" << endl;
 } tt = dt.find("autocomplete");
 if(tt){
   cout << "found autocomplete" << endl;
 }


tt= dt.find("hello");
if(!tt){
cout << "cannot find hello " << endl;
}
*/
  dt.insert("harry", 10);
  dt.insert("harr", 9); 
  dt.insert("harrys", 5);

tt = dt.find("cup");
if(tt){
  cout << "found cup" << endl;
}
tt = dt.find("cups");
if(tt){
  cout << "found cups" << endl;
}


tt = dt.find("");
if(tt){
  cout << "found the empty string " << endl;
}
  vector<string> predictions;

  predictions = dt.predictCompletions("ha", 10);

  cout << predictions.size() << endl;
  for(unsigned int i = 0; i < predictions.size(); i++) {
    cout << predictions[i] << endl;
  }
  
  return 0;
}

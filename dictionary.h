#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>
#include  <stdlib.h>

#include  "hashset.h"
#include  "hashset.cpp"

using namespace std;

class hash_function
{
public:

	unsigned int operator()(const string& s)  const
	{
		unsigned int hash = 0;
		unsigned int p = 26;

		for (int i = 0; i < s.length(); ++i)
		{
			p *= 26;
			hash += p * (s[i] - 'a' + 1);
		}
		return hash;
	}
};

class equality
{
public:
	equality() {}
	bool  operator()(const string& A, const string& B)  const
	{
		return  (A == B);
	}
};

class Dictionary : public HashSet<string, hash_function, equality>
{
public:
	Dictionary(string filename);

	void tryCorrect(string word);

	void transposing(string word, vector<string>& mas);
	void removal(string word, vector<string>& mas);
	void replacement(string word, vector<string>& mas);
	void inserting(string word, vector<string>& mas);

};
#endif // _DICTIONARY_H_
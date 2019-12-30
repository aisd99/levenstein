#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"


Dictionary::Dictionary(string filename)
{
	ifstream in(filename);

	if (!in.is_open())
		throw invalid_argument("File does not exist!");

	string word;

	while (in)
	{
		in >> word;
		insert(word);
	}

	in.close();
}

bool find(string str, vector<string> mas)
{
	for (int i = 0; i < mas.size(); ++i)
		if (mas[i] == str) return true;

	return false;
}

void Dictionary::transposing(string word, vector<string>& mas)
{
	for (int i = 0; i < word.length(); ++i)
	{
		string curr = word;
		curr[i] = word[i + 1];
		curr[i + 1] = word[i];

		if (!find(curr, mas) && this->search(curr))
		{
			mas.resize(mas.size() + 1);
			mas[mas.size() - 1] = curr;
		}
	}
}



void Dictionary::removal(string word, vector<string>& mas)
{
	for (int i = 0; i < word.length(); ++i)
	{
		string curr = "";
		for (int j = 0; j < word.length(); ++j)
			if (j != i)
				curr += word[j];

		if (!find(curr, mas) && this->search(curr))
		{
			mas.resize(mas.size() + 1);
			mas[mas.size() - 1] = curr;
		}
	}
}

void Dictionary::replacement(string word, vector<string>& mas)
{
	for (int i = 0; i < word.length(); ++i)
	{
		string curr = word;
		for (char j = 'a'; j <= 'z'; ++j)
		{
			curr[i] = j;
			if (!find(curr, mas) && this->search(curr))
			{
				mas.resize(mas.size() + 1);
				mas[mas.size() - 1] = curr;
			}
		}
	}
}

void Dictionary::inserting(string word, vector<string>& mas)
{
	for (int i = 0; i <= word.length(); ++i)
	{
		for (char j = 'a'; j <= 'z'; ++j)
		{
			string curr = "";
			for (int k = 0; k <= word.length(); ++k)
			{
				if (i == k) curr += j;
				if (k < word.length())
					curr += word[k];
			}
			if (!find(curr, mas) && this->search(curr))
			{
				mas.resize(mas.size() + 1);
				mas[mas.size() - 1] = curr;
			}
		}
	}
}

void Dictionary::tryCorrect(string word)
{
	cout << "possible corrections:" << endl;

	vector<string> mas;

	transposing(word, mas);
	removal(word, mas);
	replacement(word, mas);
	inserting(word, mas);

	if (mas.size() == 0)
		cout << "this word has no corrections";
	else
	{
		int j = 0;
		for (int i = 0; i < mas.size(); ++i)
		{
			cout << "\"" << mas[i] << "\" ";
			if (++j == 4)
			{
				j = 0;
				cout << endl;
			}
		}
	}
	cout << endl;
}
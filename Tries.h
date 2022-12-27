#pragma once
#include<iostream>
#include<string>
#include <string>

const int Size = 26;



struct TriesNode
{
	TriesNode* child[Size];
	bool isEndOfWord;
	TriesNode()
	{
		for (int i = 0; i < Size; i++)
		{
			child[i] = NULL;
			isEndOfWord = false;
		}
	}
};
class Tries
{
	TriesNode* root[Size];
	void deleteNodes(TriesNode* ptr);
public:
	Tries()
	{
		for (int i = 0; i < Size; i++)
		{
			root[i] = NULL;
		}
	}
	~Tries()
	{
		for (int i = 0; i < Size; i++)
		{
			deleteNodes(root[i]);
		}
	}
	void insert(string word);
	bool search(string word);
	void Delete(string word);
};


#include "Tries.h"
using namespace std;
void Tries::insert(string word)
{
	for (uint32_t i = 0; i < word.length(); i++)
	{
		word[i] -= 'a';
	}
	if (root[word[0]]==NULL)
	{
		root[word[0]] = new TriesNode();
	}
	TriesNode* p = root[word[0]];
	for (uint32_t i = 0; i < word.length(); i++)
	{
		if (p->child[word[i]]==NULL)
		{
			p->child[word[i]] = new  TriesNode();
		}
	}
	p->isEndOfWord = true;
}

bool Tries::search(string word)
{
	for (uint32_t i = 0; i < word.length(); i++) word[i] -= 'a';

	TriesNode* p = root[word[0]];
	for (uint32_t i = 1; p && i < word.length(); i++) {
		p = p->child[word[i]];
	}
	return p && p->isEndOfWord;
}

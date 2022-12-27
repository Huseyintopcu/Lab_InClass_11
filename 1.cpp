#include<iostream>
#include<string>


const int Size = 26;

using namespace std;

struct TriesNode
{
	TriesNode* child[Size];
	bool isEndOfWord;
};
struct TriesNode* getNode(void)
{
	struct TriesNode* pNode = new TriesNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < Size; i++)
		pNode->child[i] = NULL;

	return pNode;
}
void insert(struct TriesNode* root, string word);
bool search(struct TriesNode* root, string word);
bool isEmpty(struct TriesNode* root);
TriesNode* Delete(struct TriesNode* root, string word, int depth = 0);
int main()
{
	TriesNode* trie = getNode();
	insert(trie, "run");
	insert(trie, "runner");
	insert(trie, "there");
	insert(trie, "result");
	insert(trie, "rise");
	insert(trie, "theme");
	insert(trie, "bye");
	insert(trie, "their");
	insert(trie, "champion");
	insert(trie, "Championship");

	search(trie, "runner") ? cout << "Yes\n" : cout << "No\n";
	search(trie, "these") ? cout << "Yes\n" : cout << "No\n";

	Delete(trie, "runner");
	search(trie, "runner") ? cout << "Yes\n" : cout << "No\n";
	search(trie, "run") ? cout << "Yes\n" : cout << "No\n";
}
void insert(struct TriesNode* root, string word)
{
	struct TriesNode* p = root;

	for (int i = 0; i < word.length(); i++) {
		word[i] -= 'a';
		if (!p->child[word[i]])
		{
			p->child[word[i]] = getNode();
		}
		p = p->child[word[i]];
	}
	p->isEndOfWord = true;
}
bool search(TriesNode* root, string word)
{
	struct TriesNode* p = root;

	for (int i = 0; i < word.length(); i++) {
		word[i]-= 'a';
		if (!p->child[word[i]])
			return false;

		p = p->child[word[i]];
	}
	return p && p->isEndOfWord;
}
bool isEmpty(struct TriesNode* root)
{
	for (int i = 0; i < Size; i++)
		if (root->child[i])
			return false;
	return true;
}
TriesNode* Delete(struct TriesNode* root, string word, int depth)
{
	// If tree is empty
	if (!root)
		return NULL;

	// If last character of key is being processed
	if (depth == word.size()) {

		// This node is no more end of word after
		// removal of given key
		if (root->isEndOfWord)
			root->isEndOfWord = false;

		// If given is not prefix of any other word
		if (isEmpty(root)) {
			delete (root);
			root = NULL;
		}

		return root;
	}

	// If not last character, recur for the child
	// obtained using ASCII value
	int index = word[depth] - 'a';
	root->child[index] =
		Delete(root->child[index], word, depth + 1);

	// If root does not have any child (its only child got
	// deleted), and it is not end of another word.
	if (isEmpty(root) && root->isEndOfWord == false) {
		delete (root);
		root = NULL;
	}

	return root;
}
#ifndef UNTITLED22_TRIE_H
#define UNTITLED22_TRIE_H
#include <stdbool.h>

#define N 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INDEX_TO_CHAR(i)(char)((int)'a' + i)
typedef struct TrieNode TrieNode;

struct TrieNode {
    char data;
    TrieNode* children[N];
    int endofWord;
};

TrieNode*  make_trie(char data);

TrieNode * insert(TrieNode* root, char*  word);

bool leafNode(TrieNode *root);

void complete(TrieNode *root, char prefix []);

int search_prefix(TrieNode * trie, char prefix []);

#endif //UNTITLED22_TRIE_H


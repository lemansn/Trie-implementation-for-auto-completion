#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "trie.h"

TrieNode*  make_trie(char data){
    TrieNode* node = ( TrieNode *)malloc(sizeof(TrieNode));
    for (int i = 0; i < N; ++i) {
        node->children[i]=NULL;
    }
    node->endofWord= 0;
    node->data= data;
    return node;
}

TrieNode * insert(TrieNode* root, char*  word){
    TrieNode * temp = root;

    for (int i = 0; word[i] !='\0'; ++i) {
        int index = (int) word[i] -'a';
        if (temp->children[index] ==NULL){
            temp->children[index] = make_trie(word[i]);
        }
        temp = temp->children[index];
    }
    temp->endofWord = 1;
    return root;
}

bool leafNode(TrieNode *root) {
    int i;
    for(i = 0; i < N; i++) {
        if(root->children [i] != NULL)
            return false;
    }
    return true;
}

void complete(TrieNode *root, char prefix []) {

    if(root->endofWord){
        printf("%s\n", prefix);}

    if(leafNode(root)) {
        return;
    }

    for(int i = 0; i < N; i++) {
        if(root->children [i]) {

            char newPrefix [N];
            strcpy(newPrefix, prefix);
            strcat(newPrefix,(char [2]){INDEX_TO_CHAR(i), '\0'});
            complete(root->children [i], newPrefix);
        }
    }
}

int search_prefix(TrieNode * trie, char prefix []) {

    for(int i = 0; i < strlen(prefix); i++) {
        int index = CHAR_TO_INDEX(prefix [i]);
        if(!trie->children [index])
            return 0;
        else
            trie = trie->children [index];
    }

    bool isWord = trie->endofWord;
    bool isLast = leafNode(trie);

    if(isWord && isLast) {
        printf("%s", prefix);
        return -1;
    }

    if(!isLast) {
        complete(trie, prefix);
        return 1;
    }

    return 0;
}

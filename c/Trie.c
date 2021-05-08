#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct Trie{
    int isend;
    struct Trie *children[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *arr =(Trie *) malloc(sizeof(Trie));
    memset(arr->children, 0, sizeof(arr->children));
    arr->isend = false;
    return arr;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        int ch = word[i]-'a';
        if(obj->children[ch] == NULL)
            obj->children[ch] = trieCreate();
        obj = obj->children[ch]; 
    }
    obj->isend = true;
}

/** Returns if the word is in the trie. */
int trieSearch(Trie* obj, char * word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int ch = word[i] - 'a';
        if (obj->children[ch] == NULL) {
            return false;
        }
        obj = obj->children[ch];
    }
    return obj->isend;
}
/** Returns if there is any word in the trie that starts with the given prefix. */
int trieStartsWith(Trie* obj, char * prefix) {
    int len = strlen(prefix);
    for (int i = 0; i < len; i++) {
        int ch = prefix[i] - 'a';
        if (obj->children[ch] == NULL) {
            return false;
        }
        obj = obj->children[ch];
    }
    return true;
}

void trieFree(Trie* obj) {
    int i;
    for(i = 0; i < 26; i++)
    {
        if(obj->children[i] != NULL)
            trieFree(obj->children[i]);
    }
    free(obj);
}

int main()
{
    Trie *trie;
    trie = trieCreate();
    char words[100];
    while(1)
    {
        printf("*");
        memset(words, 0, sizeof(words));
        scanf("%s", words);
        if(!strcmp(words, "exit"))
            break;
        trieInsert(trie, words);
    }
    while(1)
    {
        printf("**");
        memset(words, 0, sizeof(words));
        scanf("%s", words);
        if(!strcmp(words, "exit"))
            break;
        int ice = trieSearch(trie, words);
        if(ice) printf("yes\n");
        else printf("no\n");
    }

    trieFree(trie);
    return 0;
}
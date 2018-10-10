#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct trie
{
    struct trie *arr[26];
    bool isEndOfWord;
} trie;

trie *createNode()
{
    trie *nn = (trie *)malloc(sizeof(trie));
    int i;
    for (i = 0; i < 26; i++)
        nn->arr[i] = NULL;
    nn->isEndOfWord = false;
    return nn;
}

void insert(trie *root, char str[])
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        int j = str[i] - 'a';
        if (!root->arr[j])
            root->arr[j] = createNode();
        root = root->arr[j];
    }
    root->isEndOfWord = true;
}

bool search(trie *root, char str[], int index)
{
    if (index == strlen(str))
        return root->isEndOfWord;
    int j = str[index] - 'a';
    if (!root->arr[j])
        return false;
    return search(root->arr[j], str, index + 1);
}

bool delete (trie *root, char str[], int index)
{
    if (index == strlen(str))
    {
        if (!root->isEndOfWord)
            return false;
        root->isEndOfWord = false;
        int i;
        for (i = 0; i < 26; i++)
            if (root->arr[i])
                return false;
        return true;
    }
    int j = str[index] - 'a';
    if (!root->arr[j])
        return false;
    bool var = delete (root->arr[j], str, index + 1);
    if (var)
    {
        root->arr[j] = NULL;
        if (root->isEndOfWord)
            return false;
        else
        {
            int i;
            for (i = 0; i < 26; i++)
                if (root->arr[i])
                    return false;
            return true;
        }
    }
}

int main()
{
    trie *o = createNode();
    insert(o, "hello");
    insert(o, "hell");
    printf("%d", search(o, "helloo", 0));
    return 0;
}
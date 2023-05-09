#include "../20__Tries_and_Huffman_coding/01_TrieNode_class.h"
#include<string>

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWordHelper(TrieNode* root, string word){
        // Base case
        if (word.size() == 0){
            root->isTerminal = true;
            return;
        }

        // small calculation
        int index = word[0] -'a';
        TrieNode* child;
        if(root->children[index] != nullptr){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->children[index]->isTerminal = true;
        }

        // recursive call
        insertWordHelper(child, word.substr(1));
    }

    void inserWord(string word){
    insertWordHelper(root, word);
    }

    // To search the word
    bool searchWordHelper(TrieNode* root, string word){
        if (word.size() == 0 and root->isTerminal){
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != nullptr){
            child = root->children[index];
        }else{
            return false;
        }

        return searchWordHelper(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchWordHelper(root, word);
    }

};


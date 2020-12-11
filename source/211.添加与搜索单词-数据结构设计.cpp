/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */
#include "cpp_includes.h"
// @lc code=start
struct TrieNode {
    bool isWord;
    TrieNode* children[26];

    TrieNode() {
        isWord = false;
        memset(children, 0, sizeof(children));
    }
};

class WordDictionary {
   public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) { return search(word.c_str(), root); }

   private:
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node->children[word[i] - 'a'];
            } else {
                auto temp = node;
                for (int j = 0; j < 26; j++) {
                    node = temp->children[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node->isWord;
    }

   private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

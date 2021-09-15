/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */
#include "cpp_includes.h"
// @lc code=start
class Trie {
   public:
    bool is_word;
    Trie* children[26];

    Trie() {
        is_word = false;
        memset(children, 0, sizeof(children));
    }
};

class WordDictionary {
   public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new Trie(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }

        node->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) { return search(word.c_str(), root); }

   private:
    bool search(const char* word, Trie* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node->children[word[i] - 'a'];
            } else {
                auto tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp->children[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node->is_word;
    }

   private:
    Trie* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "cpp_includes.h"
// @lc code=start
class Trie {
    bool _isEnd;
    Trie* _next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        _isEnd = false;
        memset(_next, NULL, sizeof(_next));
    }

    ~Trie() {
        for (auto n : _next) {
            if (n != NULL) delete n;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = this;
        for (char c : word) {
            if (node->_next[c-'a'] == NULL) {
                node->_next[c-'a'] = new Trie();
            }
            node = node->_next[c-'a'];
        }
        node->_isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = this;
        for (char c : word) {
            node = node->_next[c-'a'];
            if (node == NULL)
                return false;
        }
        return node->_isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = this;
        for (char c : prefix) {
            node = node->_next[c-'a'];
            if (node == NULL)
                return false;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


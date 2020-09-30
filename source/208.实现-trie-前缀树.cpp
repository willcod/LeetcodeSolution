/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "cpp_includes.h"
// @lc code=start
class Trie {
    bool _isEnd;
    vector<Trie *> _next;

   public:
    /** Initialize your data structure here. */
    Trie() : _isEnd(false), _next(26, NULL) {}
    ~Trie() {
        for (auto n : _next) {
            if (n) delete n;
        }
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto t = this;
        for (char c : word) {
            if (t->_next[c - 'a'] == NULL) t->_next[c - 'a'] = new Trie();
            t = t->_next[c - 'a'];
        }
        t->_isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto t = this;
        for (char c : word) {
            if (t->_next[c - 'a'] == NULL) return false;
            t = t->_next[c - 'a'];
        }
        return t->_isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        auto t = this;
        for (char c : prefix) {
            if (t->_next[c - 'a'] == NULL) return false;
            t = t->_next[c - 'a'];
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

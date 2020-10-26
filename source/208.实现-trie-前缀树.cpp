/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "cpp_includes.h"
// @lc code=start
class Trie {
  public:
    /** Initialize your data structure here. */
    Trie() {
        _isEnd = false;
        memset(_next, NULL, sizeof(_next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto t = this;
        for (auto c : word) {
            if (t->_next[c - 'a'] == NULL)
                t->_next[c - 'a'] = new Trie();
            t = t->_next[c - 'a'];
        }
        t->_isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto t = this;
        for (auto c : word) {
            t = t->_next[c - 'a'];
            if (t == NULL)
                return false;
        }
        return t->_isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        auto t = this;
        for (auto c : prefix) {
            t = t->_next[c - 'a'];
            if (t == NULL)
                return false;
        }
        return true;
    }

  private:
    bool _isEnd;
    Trie *_next[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

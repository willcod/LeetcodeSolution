/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "cpp_includes.h"
// @lc code=start
class Trie {
  Trie* next[26];
  bool isEnd;

 public:
  /** Initialize your data structure here. */
  Trie() {
    memset(next, NULL, sizeof(next));
    isEnd = false;
  }

  ~Trie() {
    for (auto t : next) {
      if (t) delete t;
    }
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie* node = this;
    for (char c : word) {
      if (node->next[c - 'a'] == NULL) node->next[c - 'a'] = new Trie();

      node = node->next[c - 'a'];
    }
    node->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie* node = this;
    for (char c : word) {
      node = node->next[c - 'a'];
      if (node == NULL) {
        return false;
      }
    }
    return node->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    auto node = this;
    for (char c : prefix) {
      node = node->next[c - 'a'];
      if (node == NULL) return false;
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

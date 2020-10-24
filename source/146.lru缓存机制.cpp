/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
#include "cpp_includes.h"
// @lc code=start
class LRUCache {
  public:
    LRUCache(int capacity) : n(capacity) {}

    int get(int key) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            keylist.erase(it->second.second);
            keylist.push_back(key);
            hash[key].second = --keylist.end();

            return it->second.first;
        }

        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            hash[key].first = value;
            return;
        }

        if (hash.size() == n) {
            auto removekey = keylist.front();
            keylist.pop_front();
            hash.erase(removekey);
        }
        insert(key, value);
    }

  private:
    void insert(int key, int value) {
        keylist.push_back(key);
        hash[key] = {value, --keylist.end()};
    }

  private:
    int n;
    list<int> keylist;
    unordered_map<int, pair<int, list<int>::iterator>> hash;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

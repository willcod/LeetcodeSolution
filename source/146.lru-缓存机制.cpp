/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include "cpp_includes.h"
// @lc code=start
class LRUCache {
   public:
    LRUCache(int capa) : capacity(capa) {}

    int get(int key) {
        auto kv = keymap.find(key);
        if (kv != keymap.end()) {
            keylist.erase(kv->second.second);
            keylist.push_back(key);
            keymap[key].second = --keylist.end();
            return kv->second.first;
        }

        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            keymap[key].first = value;
            return;
        }

        if (keymap.size() < capacity) {
            insert(key, value);
        } else {
            auto removekey = keylist.front();
            keylist.pop_front();
            keymap.erase(removekey);
            insert(key, value);
        }
    }

   private:
    void insert(int key, int value) {
        keylist.push_back(key);
        keymap[key] = {value, --keylist.end()};
    }

   private:
    list<int> keylist;
    unordered_map<int, pair<int, list<int>::iterator>> keymap;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

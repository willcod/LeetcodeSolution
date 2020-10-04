/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
#include "cpp_includes.h"
// @lc code=start
class LRUCache {
   public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = _keyMap.find(key);
        if (it == _keyMap.end()) return -1;

        _keyList.erase(it->second.second);
        _keyList.push_back(key);
        _keyMap[key].second = --_keyList.end();

        return it->second.first;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            _keyMap[key].first = value;
            return;
        }

        if (_keyMap.size() < _capacity) {
            insert(key, value);
        } else {
            int removeKey = _keyList.front();
            _keyList.pop_front();
            _keyMap.erase(removeKey);
            insert(key, value);
        }
    }

   private:
    void insert(int key, int value) {
        _keyList.push_back(key);
        _keyMap[key] = {value, --_keyList.end()};
    }

   private:
    int _capacity;
    list<int> _keyList;
    unordered_map<int, pair<int, list<int>::iterator>> _keyMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */
#include "cpp_includes.h"
// @lc code=start
class MyHashSet {
   public:
    /** Initialize your data structure here. */
    MyHashSet() : table(1000001, 0) {}

    void add(int key) { table[key] = 1; }

    void remove(int key) { table[key] = 0; }

    /** Returns true if this set contains the specified element */
    bool contains(int key) { return table[key]; }

   private:
    vector<bool> table;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet({bank.begin(), bank.end()});
        if (!bankSet.count(end)) return -1;

        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(start);
        tail.insert(end);

        int change = 1;
        string types = "ACGT";

        while (!head.empty() && !tail.empty()) {
            if (head.size() <= tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                ptail = &head;
                phead = &tail;
            }

            unordered_set<string> next;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string gene = *it;
                for (int i = 0; i < gene.size(); i++) {
                    char g = gene[i];
                    for (char t : types) {
                        gene[i] = t;

                        if (ptail->count(gene)) return change;

                        if (bankSet.count(gene)) {
                            bankSet.erase(gene);
                            next.insert(gene);
                        }
                    }
                    gene[i] = g;
                }
            }
            phead->swap(next);
            change++;
        }

        return -1;
    }
};
// @lc code=end

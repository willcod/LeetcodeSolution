/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        vector<vector<string>> res;
        vector<string> path(1, beginWord);
        if (beginWord == endWord) {
            res.push_back(path);
            return res;
        }

        unordered_set<string> dict{wordList.begin(), wordList.end()};
        if (!dict.count(endWord)) return {};

        unordered_set<string> head, tail;
        head.insert(beginWord);
        tail.insert(endWord);

        unordered_map<string, vector<string>> nexts;
        bool ishead = false;
        if (findLaddersHelper(head, tail, dict, nexts, ishead))
            getPath(beginWord, endWord, nexts, path, res);
        return res;
    }

    bool findLaddersHelper(
        std::unordered_set<std::string> &head,
        std::unordered_set<std::string> &tail,
        std::unordered_set<std::string> &dict,
        std::unordered_map<std::string, std::vector<std::string>> &nexts,
        bool &isHead) {
        isHead = !isHead;
        if (head.empty()) return false;
        if (head.size() > tail.size())
            return findLaddersHelper(tail, head, dict, nexts, isHead);
        for (auto it = head.begin(); it != head.end(); ++it) dict.erase(*it);
        for (auto it = tail.begin(); it != tail.end(); ++it) dict.erase(*it);
        std::unordered_set<std::string> temp;
        bool reach = false;
        for (auto it = head.begin(); it != head.end(); ++it) {
            std::string word = *it;
            for (int i = 0; i < word.length(); i++) {
                char tmp = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;

                    if (tail.find(word) != tail.end()) {
                        reach = true;
                        isHead ? nexts[*it].push_back(word)
                               : nexts[word].push_back(*it);
                    } else if (!reach && dict.find(word) != dict.end()) {
                        temp.insert(word);
                        isHead ? nexts[*it].push_back(word)
                               : nexts[word].push_back(*it);
                    }
                }
                word[i] = tmp;
            }
        }
        return reach || findLaddersHelper(tail, temp, dict, nexts, isHead);
    }

    void getPath(
        std::string beginWord, std::string &endWord,
        std::unordered_map<std::string, std::vector<std::string>> &nexts,
        std::vector<std::string> &path,
        std::vector<std::vector<std::string>> &paths) {
        if (beginWord == endWord)
            paths.push_back(path);
        else {
            for (auto it = nexts[beginWord].begin();
                 it != nexts[beginWord].end(); ++it) {
                path.push_back(*it);
                getPath(*it, endWord, nexts, path, paths);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

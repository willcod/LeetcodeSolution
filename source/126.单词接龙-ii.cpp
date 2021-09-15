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
                                       vector<string>& wordList) {
        unordered_set<string> dict({wordList.begin(), wordList.end()});
        if (!dict.count(endWord)) return {};

        vector<vector<string>> res;
        vector<string> path(1, beginWord);

        unordered_map<string, vector<string>> nexts;
        if (buildNexts(beginWord, endWord, dict, nexts)) {
            buildAns(beginWord, endWord, nexts, path, res);
        }
        return res;
    }

    bool buildNexts(string start, string end, unordered_set<string>& dict,
                    unordered_map<string, vector<string>>& nexts) {
        unordered_set<string> head, tail;
        head.insert(start);
        tail.insert(end);

        bool headIsFront = true, found = false;

        while (!head.empty() && !tail.empty()) {
            if (head.size() > tail.size()) {
                swap(head, tail);
                headIsFront = !headIsFront;
            }

            unordered_set<string> temp;
            for (auto word : head) {
                dict.erase(word);
                string headWord = word;
                for (int i = 0; i < word.length(); i++) {
                    char t = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (tail.count(word)) {
                            headIsFront ? nexts[headWord].push_back(word)
                                        : nexts[word].push_back(headWord);
                            found = true;
                        } else if (!found && dict.count(word)) {
                            headIsFront ? nexts[headWord].push_back(word)
                                        : nexts[word].push_back(headWord);
                            temp.insert(word);
                        }
                    }
                    word[i] = t;
                }
            }
            if (found) return true;
            for (auto word : temp) dict.erase(word);

            head = temp;
        }
        return false;
    }

    void buildAns(string start, string end,
                  unordered_map<string, vector<string>>& nexts,
                  vector<string>& path, vector<vector<string>>& ans) {
        if (start == end) {
            ans.push_back(path);
            return;
        }

        for (auto s : nexts[start]) {
            path.push_back(s);
            buildAns(s, end, nexts, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end

#
# @lc app=leetcode.cn id=126 lang=python
#
# [126] 单词接龙 II
#

# @lc code=start
class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        wordList = set(wordList)
        res = []
        layer = {}
        layer[beginWord] = [[beginWord]]

        while layer:
            newlayer = collections.defaultdict(list)
            for w in layer:
                if w == endWord:
                    res.extend(k for k in layer[w])
                else:
                    for i in range(len(w)):
                        for c in 'abcdefghijklmnopqrstuvwxyz':
                            new_w = w[:i]+c+w[i+1:]
                            if new_w in wordList:
                                newlayer[new_w] += [j+[new_w] for j in layer[w]]

            wordList -= set(newlayer.keys())
            layer = newlayer
        
        return res;
            
# @lc code=end


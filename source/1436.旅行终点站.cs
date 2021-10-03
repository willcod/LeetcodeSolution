/*
 * @lc app=leetcode.cn id=1436 lang=csharp
 *
 * [1436] 旅行终点站
 */
using csharpnaming;
// @lc code=start
public class Solution {
    public string DestCity(IList<IList<string>> paths) {
        var startCities = new HashSet<string>();
        var endCities = new HashSet<string>();

        foreach(var path in paths) {
            startCities.Add(path[0]);
            endCities.Add(path[1]);
        }

        foreach(var city in endCities) {
            if (startCities.Contains(city) == false) {
                return city;
            }
        }

        return string.Empty;
    }
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=1797 lang=csharp
 *
 * [1797] 设计一个验证系统
 */

// @lc code=start
public class AuthenticationManager {

    int _timeToLive;
    Dictionary<string, int> _dic =new();
    public AuthenticationManager(int timeToLive) {
        _timeToLive = timeToLive;
    }
    
    public void Generate(string tokenId, int currentTime) {
        _dic.Add(tokenId, currentTime);
    }
    
    public void Renew(string tokenId, int currentTime) {
        if (_dic.ContainsKey(tokenId)){
            if(_dic[tokenId] + _timeToLive > currentTime){
                _dic[tokenId] = currentTime;
            }
        }
    }
    
    public int CountUnexpiredTokens(int currentTime) {
        return _dic.Count(e => e.Value + _timeToLive > currentTime);
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.Generate(tokenId,currentTime);
 * obj.Renew(tokenId,currentTime);
 * int param_3 = obj.CountUnexpiredTokens(currentTime);
 */
// @lc code=end


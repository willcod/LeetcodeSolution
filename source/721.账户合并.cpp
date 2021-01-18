/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */
#include "cpp_includes.h"
// @lc code=start
class UnionFind{
private:
    unordered_map<string,string> father;
    // 根节点所在集合的所有账户
    unordered_map<string,vector<string>> accounts;

public:
    unordered_map<string,string> get_father(){
        return father;
    }
    
    unordered_map<string,vector<string>> get_accounts(){
        return accounts;
    }
    
    string find(string s){
        if(father[s] == "root") return s;
        
        // 递归的路径压缩处理
        father[s] = find(father[s]);
        
        return father[s];
    }
    
    void merge(string x,string y){
        string root_x = find(x);
        string root_y = find(y);
        
        if(root_x == root_y) return;
        
        // 按秩合并，更新根节点和所属的账户
        if(accounts[root_x].size() < accounts[root_y].size()){
            father[root_x] = root_y;
            for(auto& account: accounts[root_x])
                accounts[root_y].push_back(account);
            accounts.erase(root_x);
        }else{
            father[root_y] = root_x;
            for(auto& account: accounts[root_y])
                accounts[root_x].push_back(account);
            accounts.erase(root_y);
        }
        
    }
    
    void add(string x){
        if(!father.count(x)){
            father[x] = "root";
            accounts[x] = {x};
        }
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf;
        // email -> name
        unordered_map<string,string> email_to_name;
        
        for(auto& v: accounts){
            // 找到姓名和主账户
            string name = v[0];
            string master = v[1];
            email_to_name[master] = name;
            uf.add(master);
            
            // 和其余的账户一一合并
            for(int i = 2;i < v.size();i++){
                email_to_name[v[i]] = name;
                uf.add(v[i]);
                uf.merge(master,v[i]);
            }
        }
        
        vector<vector<string>> res;
        unordered_map<string,string> father = uf.get_father();
        unordered_map<string,vector<string>> acc = uf.get_accounts();
        
        for(auto& p: father){
            // 是根节点
            if(p.second == "root"){
                // 添加user
                vector<string> user_account = {email_to_name[p.first]};
                
                // 添加账户
                sort(acc[p.first].begin(),acc[p.first].end());
                for(auto& email: acc[p.first])
                    user_account.push_back(email);
                
                res.push_back(user_account);
            }
        }
        
        return res;

    }
};
// @lc code=end


#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void solve(string& digits, string& temp, int i, unordered_map<char,vector<char>>& mp, vector<string>& ans){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }

        for(int j=0;j<mp[digits[i]].size();j++){
            temp+= mp[digits[i]][j];
            solve(digits,temp,i+1,mp,ans);
            temp.pop_back();
        }



    }

public:
    vector<string> letterCombinations(string digits) {
         if(digits.empty()) {
            return {};
        }

        unordered_map<char,vector<char>> mp;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};

        string temp="";
        vector<string> ans;

        solve(digits,temp,0,mp,ans);

        return ans;
        

        
    }
};

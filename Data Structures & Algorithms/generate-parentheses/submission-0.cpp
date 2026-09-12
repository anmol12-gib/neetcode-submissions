#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string& s, int n, int open, int close, int i,  vector<string>& ans){
        if(i==2*n){
            ans.push_back(s);
            return;
        }

        

        if(open<n){
            s+='(';
            solve(s,n,open+1,close,i+1,ans);
            s.pop_back();
        }

        if(close<open){
            s+=')';
            solve(s,n,open,close+1,i+1,ans);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";

        solve(s,n,0,0,0,ans);

        return ans;
        
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool palindrome(string x){
        string y=x;
        reverse(y.begin(),y.end());
        return y==x;
    }

    void solve(string& s, vector<string>& pp ,int i, vector<vector<string>>& ans){
        if(i==s.size()){
            ans.push_back(pp);
            return;
        }

        for(int j = i; j < s.size(); j++) {

            string temp = s.substr(i, j - i + 1);

            if(palindrome(temp)) {
                pp.push_back(temp);

                solve(s, pp, j + 1, ans);

                pp.pop_back();
            }
        }


    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pp;

        solve(s, pp, 0, ans);

        return ans;
        
    }
};

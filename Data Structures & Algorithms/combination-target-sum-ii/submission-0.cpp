
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int>& candidates, int target, vector<int> temp, int sum, int i, vector<vector<int>>& ans){

        if(sum==target){
            ans.push_back(temp);
            return;
        }

        if(i>=candidates.size() || sum>target){
            return;
        }

        
        
        if(sum+candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(candidates,target,temp,sum+candidates[i],i+1,ans);
            temp.pop_back();
        }

        int idx=i+1;

        while(idx<candidates.size() && candidates[idx]==candidates[i]) idx++;

        solve(candidates,target,temp,sum,idx,ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, temp, 0, 0, ans);

        return ans;
        
    }
};

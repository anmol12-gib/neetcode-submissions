#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void getSubsets(vector<int>& nums, vector<int>& temp, int i, vector<vector<int>>& ans){
        

        int n=nums.size();
        if(i==n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        getSubsets(nums,temp,i+1,ans);

        temp.pop_back();

        int idx=i+1;

        while(idx<n && nums[idx]==nums[idx-1]) idx++;

        getSubsets(nums,temp,idx,ans);

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        getSubsets(nums,temp,0,ans);

        return ans;
        
    }
};

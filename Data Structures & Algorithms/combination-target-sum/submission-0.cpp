class Solution {
private:
    void solve(vector<int>& nums, int target, vector<int> temp, int sum, int i, vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        if(i>=nums.size() || sum>target){
            return;
        }

        
        
        if(sum+nums[i]<=target){
            temp.push_back(nums[i]);
            solve(nums,target,temp,sum+nums[i],i,ans);
            temp.pop_back();
        }

        solve(nums,target,temp,sum,i+1,ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int sum=0;
        vector<int> temp;

        solve(nums,target,temp,sum,0,ans);

        return ans;    
    }
};

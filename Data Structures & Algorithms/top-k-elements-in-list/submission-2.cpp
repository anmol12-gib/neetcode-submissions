#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;
        unordered_map<int,int> mp;

        for(auto it : nums){
            mp[it]++;
        }

        priority_queue<pair<int,int>> pq;

        for(const auto& [key,value] : mp){
            pq.push({value, key});
        }

        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for(int x : st) {
            
            // x is the beginning of a sequence
            if(st.find(x - 1) == st.end()) {
                
                int cnt = 1;
                int curr = x;

                while(st.find(curr + 1) != st.end()) {
                    curr++;
                    cnt++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
        
    }
};

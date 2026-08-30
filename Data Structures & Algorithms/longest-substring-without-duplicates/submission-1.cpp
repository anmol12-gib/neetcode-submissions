#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.size();
        int l=0,r=0;

        unordered_set<char> st;

        while(r<n){
            if(!st.count(s[r])){
                st.insert(s[r]);
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                while(st.count(s[r])){
                    st.erase(s[l]);
                    l++;
                }
            }
        }

        return ans;
    }
};

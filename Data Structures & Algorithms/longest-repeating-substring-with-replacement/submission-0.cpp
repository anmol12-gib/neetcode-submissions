#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();

        int l=0,r=0;
        int ans=0;

        unordered_map<char,int> mp;

        while(r<n){
            mp[s[r]]++;

            int p=r-l+1;

            int max_f=0;

            for(auto [key,value] : mp){
                max_f=max(max_f,value);
            }

            int replacements=p-max_f;

            if(replacements<=k){
                ans=max(ans,p);
            }
            else{
                mp[s[l]]--;
                l++;
            }

            r++;
        }

        return ans;
    }
};
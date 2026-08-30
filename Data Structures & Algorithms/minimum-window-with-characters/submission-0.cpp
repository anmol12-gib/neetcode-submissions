#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();

        unordered_map<char,int> mp;

        for(auto ch:t){
            mp[ch]++;
        }

        int l=0,r=0;
        int cnt=0;

        int start=0;
        int len=INT_MAX;

        while(r<n){

            if(mp[s[r]]>0){
                cnt++;
            }

            mp[s[r]]--;

            while(cnt==t.size()){

                if(r-l+1<len){
                    len=r-l+1;
                    start=l;
                }

                mp[s[l]]++;

                if(mp[s[l]]>0){
                    cnt--;
                }

                l++;
            }

            r++;
        }

        if(len==INT_MAX) return "";

        return s.substr(start,len);
    }
};
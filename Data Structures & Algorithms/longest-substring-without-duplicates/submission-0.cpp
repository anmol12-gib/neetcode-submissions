#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                string s1=s.substr(i,j-i+1);

                unordered_set<char> st;

                st.insert(s1.begin(),s1.end());

                if(st.size()==s1.size()){
                    ans=max(ans,(int)s1.size());
                }
            }
        }

        return ans;
        
    }
};

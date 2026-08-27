#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            if(!isalnum(s[i])){
                s.erase(s.begin()+i);
                i--;
            }
        }

        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
        }


        string t=s;
        reverse(t.begin(),t.end());
        return s==t;
        
    }
};

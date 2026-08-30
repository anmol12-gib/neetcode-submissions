#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1=s1.size();

        for(int i=0;i<s2.size();i++){
            string temp=s2.substr(i,n1);
            if(is_permutation(s1.begin(),s1.end(),temp.begin(),temp.end())) return true;
        }

        return false;


        
    }
};

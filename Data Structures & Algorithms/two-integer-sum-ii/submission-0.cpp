#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();

        int l=0,h=n-1;

        while(l<h){
            int sum=numbers[l]+numbers[h];

            if(sum==target) return {l+1,h+1};

            else if(sum>target){
                h--;
            }

            else l++;

        }
        
        return {};
    }
};

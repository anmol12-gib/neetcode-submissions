#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> ans;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int x : nums) {
            ans.push(x);

            if(ans.size() > k)
                ans.pop();
        }
    }

    int add(int val) {
        ans.push(val);

        if(ans.size() > k)
            ans.pop();

        return ans.top();
    }
};
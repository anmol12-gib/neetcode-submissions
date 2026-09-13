#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> temp;

        for(auto it : points) {
            int xc = it[0];
            int yc = it[1];

            int dist = xc * xc + yc * yc;

            temp.push_back({dist, xc, yc});
        }

        priority_queue<vector<int>,
                       vector<vector<int>>,
                       greater<vector<int>>> pq;

        for(auto it : temp) {
            pq.push(it);
        }

        vector<vector<int>> ans;

        while(!pq.empty() && k--) {
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }

        return ans;
    }
};
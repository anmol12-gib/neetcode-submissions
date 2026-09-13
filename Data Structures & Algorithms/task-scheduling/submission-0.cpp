#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for(char c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<int> pq;

        for(int x : freq) {
            if(x > 0)
                pq.push(x);
        }

        queue<pair<int, int>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            // If a task is available again, put it back
            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }

            // Execute the task with highest frequency
            if(!pq.empty()) {
                int cnt = pq.top();
                pq.pop();

                cnt--;

                if(cnt > 0) {
                    // Can be executed again after n intervals
                    q.push({cnt, time + n + 1});
                }
            }
        }

        return time;
    }
};
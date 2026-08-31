class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        priority_queue<pair<int,int>> pq;

        

        vector<int> ans;

        while(r<n){

            pq.push({nums[r],r});

            if(r-l+1 ==k){
                while(!pq.empty() && pq.top().second < l){
                    pq.pop();

                }   

                ans.push_back(pq.top().first);

                l++;   
            }
            r++;
            
            






        }

        return ans;
        
    }
};

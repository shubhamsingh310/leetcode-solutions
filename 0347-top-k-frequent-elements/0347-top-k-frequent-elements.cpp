class Solution {
public:
    typedef pair<int, int> p;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //step 1 creating min-heap
        priority_queue<p, vector<p>, greater<p>> pq;
        
        //step 2 count frequency of each element
        
        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        
        //step 3 Push in min-heap and maintain size k
        for(auto it:mp) {
            pq.push({it.second, it.first});
            
            
            if(pq.size() > k)
                pq.pop();
        }
        
        
        // step 4 Pick all top K elements
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
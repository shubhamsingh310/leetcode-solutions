class Solution {
    struct comp{
        char operator()(pair<int,int> &x,pair<int,int> &y){
        return y.first+y.second>x.first+x.second;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, comp> pq;

        int i,j,c=0;
        for(i=0;i<nums1.size();i++)
        {
            for(j=0;j<nums2.size();j++)
            {
                if(pq.size() < k)          
    		{
    			pq.push({nums1[i],nums2[j]});
			}
			else if(pq.size()==k and (nums1[i]+nums2[j]) < pq.top().first+pq.top().second)  
			{
				pq.pop();
				pq.push({nums1[i],nums2[j]});
			}
			else if(pq.size()==k and (nums1[i]+nums2[j]) > pq.top().first+pq.top().second)   
			{
				break;
			}
            }
        }

        vector<vector<int>> v;
        
        while(!pq.empty())
        {
            v.push_back({pq.top().first,pq.top().second});
           
            pq.pop();
        }
    return v;
    }
};
typedef pair<int,int> p;
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
	   
        priority_queue<p, vector<p>, greater<p>> minHeap;
	
        priority_queue<p> maxHeap;
		
        for(int i=0;i<Profits.size();i++){
            minHeap.push(make_pair(Capital[i], Profits[i]));
        }
	
        for(int i=0;i<k;i++){
            while(minHeap.size()>0 and minHeap.top().first<=W){
                pair<int,int> p=minHeap.top();
                maxHeap.push(make_pair(p.second,p.first));
                minHeap.pop();
            }
            if(maxHeap.size()>0){
                W+=maxHeap.top().first;
                maxHeap.pop();
            }
        }
        return W;
    }
};
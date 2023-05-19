class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len =graph.size();
        vector<int>v(len,0);
        for(int i=0;i<len;i++){
            if(v[i]==1 ||v[i]==-1)continue;
            queue<int>q;
            q.push(i);
            v[i]=1;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(int next:graph[curr]){
                    if(v[next]==0){
                        v[next]=-v[curr];
                        q.push(next);
                    }
                    if(v[next]==v[curr])return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> result;
    vector<int> countSubTrees(int num_nodes, vector<vector<int>>& edges, string labels) {
        vector<int> adjacency_list[num_nodes];
        for(auto &edge:edges){
            int node1=edge[0],node2=edge[1];
            adjacency_list[node1].push_back(node2);
            adjacency_list[node2].push_back(node1);
        }
        result.resize(num_nodes,0);
        vector<int> letter_count(26,0);
        traverse(0,-1,letter_count,adjacency_list,labels);
        return result;
    }
    void traverse(int current_node,int parent_node,vector<int>& letter_count,vector<int> adjacency_list[],string &labels){
        for(auto &neighbor:adjacency_list[current_node]){
            if(neighbor!=parent_node){
                vector<int> counting(26,0);
                traverse(neighbor,current_node,counting,adjacency_list,labels);
                for(int i=0;i<26;i++){
                    letter_count[i]=letter_count[i]+counting[i];
                }
            }
        }
        letter_count[labels[current_node]-'a']++;
        result[current_node]=letter_count[labels[current_node]-'a'];
    }
};

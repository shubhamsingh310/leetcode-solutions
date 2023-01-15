class Solution {
public:
		int findParent(vector<int>& parents,int node) //Finds parent of a node
		{
			if(node==parents[node])
				return node;
			parents[node]=findParent(parents,parents[node]);
			return parents[node];

		}
		int numberOfGoodPaths(vector<int>& values, vector<vector<int>>& edges) {
			int numNodes = values.size();
			vector<int> parents(numNodes);
			map<int,int> maxVal;
			map<int,int> countVal;

			for(int i=0;i<numNodes;i++){
				parents[i]=i;
				maxVal[i]=values[i];
				countVal[i]=1;
			}

			sort(edges.begin(),edges.end(),[&](const vector<int>& a,vector<int>& b)
				 {
					 int maxA = max(values[a[0]],values[a[1]]);
					 int maxB = max(values[b[0]],values[b[1]]);
					 return maxA<maxB;
				 });


			int ans=numNodes;

			for(auto& edge: edges)
			{
				int parentNode1=findParent(parents,edge[0]);
				int parentNode2=findParent(parents,edge[1]);
				if(maxVal[parentNode1]!=maxVal[parentNode2])
				{
					if(maxVal[parentNode1]>maxVal[parentNode2])
					{
						parents[parentNode2]=parentNode1;
					}
					else{
						parents[parentNode1]=parentNode2;
					}
				}
				else
				{
					parents[parentNode1]=parentNode2;
					ans+=countVal[parentNode1]*countVal[parentNode2];
					countVal[parentNode2]+=countVal[parentNode1];
				}
			}
			return ans;
		}
	};

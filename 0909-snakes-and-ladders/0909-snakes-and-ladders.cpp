class Solution {
    void getCoordinate(int size, int currentPos, int &row, int &col){
        row = size-1-(currentPos-1)/size;
        col = (currentPos-1)%size;
        
        if((size%2==1 && row%2==1)||(size%2==0 && row%2==0))
            col = size-1-col;
    }
public:
    int snakesAndLadders(vector<vector<int>>& gameBoard) {
        int size = gameBoard.size();
        vector<bool> visited(size*size+1,false);
		visited[1] = true;
        
        queue<pair<int,int>> positionQueue;
		positionQueue.push({1,0});
        
        while(!positionQueue.empty()){
            pair<int,int> current = positionQueue.front();positionQueue.pop();
            
            int row,col,currentPos = current.first, distance = current.second;
            
            if(currentPos == size*size)
                return distance;
            
            
            for(int i=1;currentPos+i<=size*size && i<=6;i++){                
                getCoordinate(size,currentPos+i,row,col);
                
                int finalPos = gameBoard[row][col]==-1?currentPos+i:gameBoard[row][col]; 
                
                if(visited[finalPos]==false){
                    visited[finalPos] = true;
                    positionQueue.push({finalPos,distance+1});
                }                
            }
        }
        return -1;
    }
};

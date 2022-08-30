class Solution {
    void bfs(int row,int col,vector<vector<char>> grid,vector<vector<int>> &visited,int deltaRow[],int deltaCol[]){
        queue<pair<int,int>> qu;
        int n=grid.size();
        int m=grid[0].size();
        qu.push({row,col});
        
        while(qu.size()){
            int rowE=qu.front().first;
            int colE=qu.front().second;
            qu.pop();
           
            for(int i=0;i<4;i++){
                int rowVirtual=rowE+deltaRow[i];
                int colVirtual=colE+deltaCol[i];
                
                if(rowVirtual>=0 && rowVirtual<n && colVirtual>=0 && colVirtual<m && grid[rowVirtual][colVirtual]=='1' && visited[rowVirtual][colVirtual]==0){
                    qu.push({rowVirtual,colVirtual});
                    visited[rowVirtual][colVirtual]=1;
                }
                
            }
            
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {  
        int numOfIsland=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        /*
        int *deltaRow=new int[4]{-1,0,1,0};
        int *deltaCol=new int[4]{0,1,0,-1};
        */
        
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    bfs(i,j,grid,visited,delta_row,delta_col);
                    numOfIsland++;
                }
            }
        }
        
        return numOfIsland;
    }
};
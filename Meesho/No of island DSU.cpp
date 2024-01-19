class Disjoint{
private:
    vector<int>parent;
    vector<int>size;
public:
    Disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int findParent(int i){
        if(parent[i]==i)
            return i;
        return parent[i] = findParent(parent[i]);
    }

    void unionSize(int u, int v){
        int x = findParent(u);
        int y  = findParent(v);
        if(x==y)
            return;
        if(size[x]>=size[y]){
            size[x]+=size[y];
            parent[y] = x;
        }
        else{
            size[y]+=size[x];
            parent[x] = y;
        }
    }

    int knowParent(int u){
        return parent[u];
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        Disjoint ds(n*m);
        vector<int>row = {-1,0,1,0};
        vector<int>col = {0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    for(int k=0;k<4;k++){
                        int x = i + row[k];
                        int y = j + col[k];
                        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1'){
                            ds.unionSize((m*i+j),(m*x+y));
                        }
                    }
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k = m*i+j;
                if(grid[i][j]=='1' && ds.knowParent(k)==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
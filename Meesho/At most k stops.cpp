class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src]==0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop = q.front().first;
            int index = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            for(auto it:adj[index]){
                int x = it.first;
                int cost = it.second;
                cost+=price;
                if(x==dst && dist[x]>cost)
                    dist[dst]=cost;
                else if(k>=stop+1 && dist[x]>cost){
                    dist[x]=cost;
                    q.push({stop+1,{x,cost}});
                }
            }
        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};
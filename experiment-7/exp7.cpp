class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto &it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<tuple<int,int,int>> q; 
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        q.push({src, 0, 0});
        
        while(!q.empty()){
            auto [node, cost, stops] = q.front();
            q.pop();
            
            if(stops > k) continue;
            
            for(auto &it : adj[node]){
                int next = it.first;
                int price = it.second;
                
                if(cost + price < dist[next]){
                    dist[next] = cost + price;
                    q.push({next, dist[next], stops + 1});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

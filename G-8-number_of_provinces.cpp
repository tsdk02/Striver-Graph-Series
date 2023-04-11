#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool>vis = vector<bool>(205, false);
    vector<int> adj[205];
    void dfs(int i){
        vis[i]=true;
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected[i][j]==1)
                adj[i].push_back(j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i);
            }
        }
        return count;
    }
};
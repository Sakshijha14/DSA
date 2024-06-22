/*
topological sorting : linear ordering of vertices such that if there is an edge between u & v
u appears before v in the ordering.
question:0={}
         1={}
         2={3}
         4={0,1}
         5={0,2} 
kahn's is not excatly bfs slightly modified version of itwe use indegree: no. of incoming edges of nodes.
 */
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> kahn(int V,vector<int> adj[]){
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            //node is in topo sort
            //so remove it from indegree

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        return topo;
        
          
    }


};

int main(){

    vector<int> adj[6]={{},{},{3},{0,1},{0,2}};
    int V=6;
    Solution obj;
    vector<int>answer=obj.kahn(V,adj);
    for(auto node: answer){
        cout<<node<<" ";
    }
    cout<<endl;

    


    return 0;
}
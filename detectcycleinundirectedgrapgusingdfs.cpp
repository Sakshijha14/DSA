/**
 * given an undirected graph with V vertices and E edges , check whether it contain any cycle or not
 * Input: V=8, E=7
 * Output=No
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:


    bool dfs(int node,int parent,int visited[],vector<int> adj[]){

        visited[node]=1;
        //we run through unvisited adjacent nodes using adjacent list and call recuesive dfs. marking nodes as visited.

        for(auto adjacentNode:adj[node]){
            
            if(!visited[adjacentNode]){
                if(dfs(adjacentNode,node,visited,adj)==true)
                return true;
            }
            //visited node but not a parent node
            else if(adjacentNode!=parent)
            return true;
        }
        return false;
    }
    bool isCycle(int V,vector<int> adj[]){
        int visited[]={0}; //initialize visited array as 0

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,visited,adj)==true)
                return true;
            }
        }
        return false;
    }
};
int main(){

    vector<int> adj[4]={{},{2},{1,3},{2}};
    Solution obj;
    bool answer=obj.isCycle(4,adj);
    if(answer)
    cout<<"1\n";
    else
    cout<<"0\n";

    return 0;
}
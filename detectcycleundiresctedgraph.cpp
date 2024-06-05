/*
Problem Statement: Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
input: vertices=8,edges=7
output=0 */



#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool detect (int source,vector<int>adj[],int vis[]){
        vis[source]=1;
        queue<pair<int,int>>q;//one int for value other for it came from
        q.push({source,-1});//we assume source came from no where

        //traversal
        while(!q.empty()){

            int node=q.front().first;
            int parentnode=q.front().second;
            q.pop();
            

            //adjacent node
            for(auto adjacentNode:adj[node]){
                if(!vis[adjacentNode]){//if adjacentnode is not visited then marked it visited and put them in queue
                    vis[adjacentNode]=1;
                    q.push({adjacentNode,node});
                }
                else if(parentnode!=adjacentNode){
                    //if someone is visited and does not come from parent
                    return true;//yes it is cyclic
                }

            }
        }
        return false;
    }
    public:
    bool iscyclic(int graphnode,vector<int>adj[]){
        //vis is initialize as unvisited
        int vis[]={0};
        for(int i=0;i<graphnode;i++){
            if(!vis[i]){
                if(detect(i,adj,vis))
                return true;
            }
        }
        return false;
    }
};
int main(){

    vector<int>adj[4]={{},{2},{1,3},{2}};
    Solution obj;
    bool answer=obj.iscyclic(4,adj);
    if(answer){
        cout<<"1\n";
    }
    else{
        cout<<"0\n";
    }
    


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int>bfsTraversal(int V,vector<int> adj[]){
        int visi[V]={0};
        visi[0]=1;
        queue<int> q;
        //push first node in queue
        q.push(0);
        //vector to store data of input
        vector<int> bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            //traverse neighbours
            for(auto it:adj[node]){
                if(!visi[it]){//if not marked.Then mark it and push in visi
                    visi[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector<int>& answer){
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}

int main(){

    vector<int> adj[6];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);

    Solution obj;
    vector<int> answer=obj.bfsTraversal(5,adj);
    printAns(answer);


    return 0;
}
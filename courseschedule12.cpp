/*this question requires only detect toptsort using bfs */
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> findorder(int Vertices,int Edges,vector<vector<int>>prerequisites){
        vector<int> adj[Vertices];
        for(auto it:prerequisites){//detect directed
            adj[it[1]].push_back(it[0]);
        }

        int indegree[Vertices]={0};
        for(int i=0;i<Vertices;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<Vertices;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
            indegree[it]--;
                if(indegree[it]==0){
                q.push(it);
                }
            }

        }
        if(topo.size()==Vertices){
            return topo;
        }
        return{};
    }

};

int main(){

    int N=4;
    int M=3;

    vector<vector<int>> prerequisites(3);
    prerequisites[0].push_back(0);
    prerequisites[0].push_back(1);

    prerequisites[1].push_back(1);
    prerequisites[1].push_back(2);

    prerequisites[2].push_back(2);
    prerequisites[2].push_back(3);

    Solution obj;
    vector<int> answer=obj.findorder(N,M,prerequisites);

    for(auto task:answer){
        cout<<task<<" ";
    }
    cout<<endl;


    return 0;
}
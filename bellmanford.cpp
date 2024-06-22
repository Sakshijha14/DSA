#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    vector<int>bellman_ford(int V,vector<vector<int>> &edges,int S){
        vector<int> distance(V,1e8);
        distance[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int weight=it[2];
                if(distance[u]!=1e8 && distance[u]+weight<distance[v]){
                    distance[v]=distance[u]+weight;
                }
            }
        }
        //for negative cycle
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int weight=it[2];
            if(distance[u]!=1e8 && distance[u]+weight<distance[v]){
                return {-1};
            }
        }

        return distance;
    }







};

int main(){

    int V=6;
    vector<vector<int>> edges(7,vector<int>(3));
    edges[0]={3,2,6};
    edges[1]={5,3,1};
    edges[2]={0,1,5};
    edges[3]={1,5,-3};
    edges[4]={1,2,-2};
    edges[5]={3,4,-2};
    edges[6]={2,4,3};

    int S=0;
    Solution obj;
    vector<int> distance=obj.bellman_ford(V,edges,S);
    for(auto d:distance){
        cout<<d<<" "; 
    }
    cout<<endl;


    return 0;
}
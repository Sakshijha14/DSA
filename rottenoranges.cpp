/*
Problem Statement: Given a grid of dimension N x M where each cell in the grid can have values 0, 1, or 2 which has the following meaning:

0: Empty cell

1: Cells have fresh oranges

2: Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges.

 A rotten orange at index [i,j] can rot other fresh oranges at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.
Bfs we want to rotten them simantanously
1.queue {no.of rooten initially (2,0),(0,2)};variable added(0)for time
2.visited 2D matrix,mark them 2
3.go to its neighbour,if fresh put in queue time ++,rotten it in matrix
eg: 0 1 2
    0 1 1
    2 1 1
output:0 2 2 
       0 2 2
       2 2 2
       time=2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:

int orangesrotting(vector<vector<int>> &matrix){

    int n=matrix.size();
    int m=matrix[0].size();

    //queue to track
    queue<pair<pair<int,int>,int>> q;//row,col,time
    int vis[n][m];
    int countFresh=0;//counting number of fresh oranges
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==2){//rotten oranges
            q.push({{i,j},0});//time is 0 initially
            vis[i][j]=2;//mark visited array 2 i.e. rotten
            }
            else{
            vis[i][j]=0;//mark 0 if not rotten
        }
        if(matrix[i][j]==1)//counting number of fresh oranges
        countFresh++;
        }
    }
    int time=0;

    //location of row and col that are neighbours of rotten

    int drow[]={-1,0,+1,0};
    int dcol[]={0,1,0,-1};
    int count=0;

    //Bfs traversal until queue is empty
    while(!q.empty()){
        int rowqueue=q.front().first.first;
        int colqueue=q.front().first.second;
        int tqueue=q.front().second;
        time=max(tqueue,time);
        q.pop();

        //there is neighbour 
        for(int i=0;i<4;i++){
            int neighbourrow=rowqueue+drow[i];
            int neighbourcol=colqueue+dcol[i];
            //if cell is valid and unvisited fresh orange
            if(neighbourrow>=0 && neighbourrow<n && neighbourcol>=0 && neighbourcol<m && vis[neighbourrow][neighbourcol]!=2&&matrix[neighbourcol][neighbourcol]==1){
                q.push({{neighbourrow,neighbourcol},tqueue+1});
                vis[neighbourrow][neighbourcol]=2;//mark vivted matrix 
                count++;
            }
        }
        
        }
        //if all oranges are not rotten
        if(count!=countFresh){
            return -1;
        }

        return time;
        
    }

};
int main(){

    vector<vector<int>>matrix{{0 ,1, 2},{0, 1, 1},{2, 1, 1}};
    Solution obj;
    int answer=obj.orangesrotting(matrix);
    cout<<answer<<"\n";
    


    return 0;
}
// BFS Shortest Distance 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+10; 
vector<int>graph[N];
bool vis[N]; // visited array
int dis[N]; // distance array

void bfs(int src, int dest){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    dis[src]=0;
    while(q.size()){
        int par=q.front();
        q.pop();
        for(auto child:graph[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                dis[child]=dis[par]+1;
                if(child==dest) return; // stop BFS if destination is found
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e; cin>>n>>e;
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x); // if directed graph, remove this line
    }

    int S,D; cin>>S>>D;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    bfs(S, D);
    if(dis[D]==-1) cout<<-1<<endl; // no path found
    else cout<<dis[D]<<endl; 
}


/*
Problem satement:
You will be given an undirected graph 
as input. Then you will be given source S and
destination D. You need to print the shortest 
distance between S and D. If there is no path
 from S to D, print -1.

Input
6 7

0 1
0 2
1 2
0 3
4 2
3 5
4 3

0 5

Output 
2

*/
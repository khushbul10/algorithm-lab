
// BFS (Breadth-First Search)
// Visits all the nodes of a graph in breadth first manner
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
vector<int>graph[N];
bool vis[N];

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(q.size()){
        int par=q.front();
        q.pop();
        cout<<par<<endl; // Print the node
        for(auto child:graph[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
            }
        }
    }
}

int main(){
    // n=number of nodes, e=number of edges
    int n,e; cin>>n>>e;
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);;
        graph[y].push_back(x);;
    }
    int src; cin>>src;
    memset(vis,false,sizeof(vis));
    bfs(src);
}
// 7 8
// 0 1 
// 1 2 
// 0 4 
// 1 3 
// 2 0
// 3 4
// 1 5
// 3 6

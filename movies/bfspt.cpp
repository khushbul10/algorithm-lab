// BFS Path Print
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
bool vis[N];
int parent[N]; // parent array to store the path
int dis[N];

void bfs(int src, int des){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    dis[src]=0;
    parent[src] = -1;
    while(q.size()){
        int par=q.front();
        q.pop();
        for(auto child:graph[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                dis[child]=dis[par]+1;
                parent[child]=par;
                
            }
        }
    }
}

int main(){
    int n,e; cin>>n>>e;
    while(e--){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);;
        graph[y].push_back(x);;
    }
    int src, des; cin>>src>>des;
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    
    bfs(src, des);
    if(dis[des]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
    // Constructing the path from source to destination
    vector<int>path;
    int x=des;
    while(x!=-1){
        path.push_back(x);
        x=parent[x];
    }
    reverse(path.begin(),path.end());
    cout<<dis[des]+1<<endl;
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
/*


// Input
7 8
0 1 
1 2 
0 4 
1 3 
2 0
3 4
1 5
3 6

2 6


Output
4
2 1 3 6

*/
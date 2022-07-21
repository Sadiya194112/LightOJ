#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
vector<int> g[N];   //As u and v can be maximum=20000
bool vis[N]={};     //Initializes with 0
bool type[N]={};

void clr(){
    memset(vis, false, sizeof(vis));
    memset(vis, false, sizeof(type));
    for(int i=0; i<N; i++){
        g[i].clear();
    }
}
long long int bfs(int x){
    long long int lykan=0, vampire=0;
    queue<int> q;
    q.push(x);
    vis[x]=1;
    type[x]=1;  //1 means lykan and 0 means vampire
    ++lykan;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++){
            int v=g[u][i];
            if(vis[v]==0){
                q.push(v);
                vis[v]=1;
                if(type[u]==1){ //if parent of v is lykan then childs of u are vampire
                    type[v]=0;
                    ++vampire;
                }
                else{
                    type[v]=1;
                    ++lykan;
                }
            }
        }
    }
    long long int mx = max(vampire, lykan);
    return mx;
}
int main(){
    int tc,u,v,n,Case=1; cin>>tc;
    while(tc--){
        clr();
        scanf("%d", &n);
        long long int sum=0;
        for(int i=0; i<n; i++){
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=0; i<N; i++){
            if(vis[i]==0 && !g[i].empty()){
                sum+=bfs(i);
            }
        }
        cout<<"Case "<<Case++<<": "<<sum<<endl;
    }
    return 0;
}

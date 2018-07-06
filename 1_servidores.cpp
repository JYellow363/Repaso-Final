#include <bits/stdc++.h>
using namespace std;
#define inf 99999

struct Edge{
    int u;
    int v;
    int w;
};

int bellman_ford(Edge *edges, int n, int m, int s, int t){
    int d[n];
    for(int i=0;i<n;i++) d[i]=inf;
    d[s]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(d[edges[j].u]+edges[j].w<d[edges[j].v])
                d[edges[j].v]=d[edges[j].u]+edges[j].w;
        }
    }
    return d[t];
}

int main(){
    freopen("in_1.txt", "r", stdin);
    int casos, n, m, s, t ,a, b, w;
    cin>>casos;
    for(int i=0;i<casos;i++){
        cin>>n>>m>>s>>t;
        Edge edges[2*m];
        for(int j=0;j<(2*m);j++){
            cin>>a>>b>>w;
            edges[j].u=a;
            edges[j].v=b;
            edges[j].w=w;
            j++;
            edges[j].u=b;
            edges[j].v=a;
            edges[j].w=w;
        }
        int aux=bellman_ford(edges, n, 2*m, s, t);
        cout<<"Case #"<<i+1<<": ";
        if(aux!= inf) cout<<aux<<endl;
        else cout<<"unreachable"<<endl;
    }
    return 0;
}

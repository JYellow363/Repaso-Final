#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class DijSet{
    private:
        int n;
        int *rank;
        int *parent;
    public:
        DijSet(int n){
            this->n=n;
            rank=new int[n];
            parent=new int[n];
            for(int i=0;i<n;i++){
                rank[i]=0;
                parent[i]=i;
            }
        }
        int find(int a){
            if(parent[a]==a) return a;
            else parent[a]=find(parent[a]);
        }
        void union_find(int a, int b){
            int x=parent[a];
            int y=parent[b];
            if(x!=y){
                if(rank[x]>rank[y]){
                    parent[y]=x;
                    rank[x]++;
                }
                else{
                    parent[x]=y;
                    rank[y]++;
                }
            }
        }
};

class Grafo{
    private:
        int n;
        vector<pair<int, iPair>> edges;
    public:
        Grafo(int n){
            this->n=n;
        }
        void add_edge(int a, int b, int w){
            edges.push_back({w,{a,b}});
        }
        void kruskal(){
            int w_total=0;
            DijSet dj(n);
            sort(edges.begin(),edges.end());
            for(int i=0;i<edges.size();i++){
                int u=edges[i].second.first;
                int v=edges[i].second.second;
                int set_u=dj.find(u);
                int set_v=dj.find(v);
                if(set_u!=set_v){
                    cout<<u<<" - "<<v<<endl;
                    w_total+=edges[i].first;
                    dj.union_find(u,v);
                }
            }
            cout<<"MST: "<<w_total;
        }
};

int main(){
    freopen("in_4.txt","r",stdin);
    int n, m;
    int a, b, w;
    cin>>n>>m;
    Grafo g(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        g.add_edge(a,b,w);
    }
    g.kruskal();
    return 0;
}

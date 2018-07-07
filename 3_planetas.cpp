#include <bits/stdc++.h>
using namespace std;
#define inf 99999
vector<vector<int>> v;
vector<vector<int>> recor;

void floyd_warshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][k]+v[k][j]<v[i][j]){
                    v[i][j]=v[i][k]+v[k][j];
                    recor[i][j]=k;
                }
            }
        }
    }
}

void recorrido(int s, int f){
    if(recor[s][f]==f) return;
    else{
        cout<<(char)(recor[s][f]+65)<<" ";
        recorrido(s, recor[s][f]);
    }
}

int main(){
    freopen("in_3.txt","r",stdin);
    int n, m;
    int w;
    char a,b;
    int x, y;
    int casos;
    cin>>n>>m;
    v=vector<vector<int>>(n);
    recor=vector<vector<int>>(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v[i].push_back(inf);
            recor[i].push_back(j);
        }
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j) v[i][j]=0;

    
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        x=a-65;
        y=b-65;
        v[x][y]=w;
        v[y][x]=w;
    }
    
    floyd_warshall(n);
    cin>>casos;
    for(int i=0;i<casos;i++){
        cin>>a>>b;
        x=a-65;
        y=b-65;
        cout<<a<<" ";
        recorrido(x,y);
        cout<<b<<endl;
    }
    return 0;
}

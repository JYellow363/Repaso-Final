#include <bits/stdc++.h>
using namespace std;

#define inf 99999

vector<vector<int>> v2(21);

void floyd_warshall(vector<vector<int>> v, int n){
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v2[i].push_back(inf);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v2[i][j]=v[i][j];
    
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(v2[i][k]+v2[k][j]<v2[i][j])
                    v2[i][j]=v2[i][k]+v2[k][j];
}

int main(){
    freopen("in_2.txt","r",stdin);
    int aux=2;
    int n=20;
    int m, b, x, y;
    for(int k=0;k<2;k++){
        cout<<"Test Set #"<<k+1<<": "<<endl;
        vector<vector<int>> v(n+1);
        
        for(int i=0;i<n+1;i++)
            for(int j=0;j<n+1;j++)
                v[i].push_back(inf);
        
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==j) v[i][j]=0;
                else v[i][j]=inf;
            }
        }
        
        for(int i=1;i<n;i++){
            cin>>m;
            for(int j=0;j<m;j++){
                cin>>b;
                v[i][b]=1;
                v[b][i]=1;
            }
        }
         
        floyd_warshall(v, n+1);
        int casos;
        cin>>casos;
        for(int i=0;i<casos;i++){
            cin>>x>>y;
            cout<<x<<" to "<<y<<": "<<v2[x][y]<<endl;
        }
    }
    return 0;
}

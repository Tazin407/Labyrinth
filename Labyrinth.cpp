#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N= 1e3+10;
int n,m;
typedef pair<int,int>pii;
vector<string>g;
int visited[N][N];
int level[N][N];
pii parent[N][N];
vector<pii>direct={{0,1},{0,-1},{1,0},{-1,0}};

bool isvalid(int i, int j){
        bool x= (i>=0 && i<n);
        bool y= (j>=0 && j<m);
        return (x&&y);
}

void bfs(int si, int sj){
    queue<pii>q;
    q.push({si,sj});
    visited[si][sj]=true;
    level[si][sj]=0;

    while(!q.empty()){
        pii upair= q.front();
        int i= upair.first;
        int j= upair.second;
        q.pop();
        for(auto d: direct){
            int ni= i+d.first;
            int nj= j+d.second;
        if(isvalid(ni,nj) && !visited[ni][nj] && g[ni][nj]!= '#'){
            q.push({ni,nj});
            visited[ni][nj]=true;
            parent[ni][nj]={i,j};
            level[ni][nj]= level[i][j]+1;

        }
        }

    }

}


int main(){

    //int n,m;
    int si,sj, di,dj;//Source ar destination
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        for (int j = 0; j < m; j++)
        {
            if(x[j]=='A'){
                si=i; sj=j;//source peye gelam
            }
            if(x[j]=='B'){
                di=i; dj=j;//destination peye gelam
            }
        }
        g.push_back(x);
        

    }
    bfs(si, sj);


   if(level[di][dj]!=0){
        cout<<"YES"<<endl;
        cout<<level[di][dj]<<endl;;
        vector<pii> path;
      pii curr= {di,dj};

      while(!(curr.first==si && curr.second==sj)){
         path.push_back(curr);
      curr= parent[curr.first][curr.second];//push korar porei declare korte hobe, 
      //push korar age korle wrong answer dekhabe
          
      }
      path.push_back({si,sj});
     reverse(path.begin(), path.end());

     for(int i= 1; i< path.size(); i++){
        if(path[i-1].first==path[i].first){
            if(path[i-1].second==path[i].second-1){
                cout<<"R";
            }
            else cout<<"L";
        }
        else{
            if(path[i-1].second==path[i].second){
                if(path[i-1].first==path[i].first-1){
                    cout<<"D";
                }
                else cout<<"U";
            }
        }
     }
    
   }
   else{
    cout<<"NO";
   }
   
return 0;
}
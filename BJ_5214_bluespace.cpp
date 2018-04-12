//  BFS, Input
//  stdio.h 했을 때 시간초과남

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector<int> g[200002];
bool isVisited[200002];
queue<int> q;

int N,K,M;
int ans=1;

int main()
{
    scanf("%d %d %d", &N,&K,&M);
    for(int i = 0,t; i < M; ++i)
        for(int j = 0; j < K; ++j){
            scanf("%d",&t);
            g[N+i+1].push_back(t);
            g[t].push_back(N+i+1);
        }
    
    q.push(1);
    isVisited[1] = true;
    
    while(!q.empty()){
        int qs = q.size();
        for(int i = 0; i < qs; ++i){
            int v = q.front();
            q.pop();
            
            if(v == N){
                printf("%d\n",ans);
                return 0;
            }
            
            for(int j = 0; j < g[v].size(); ++j){
                int v_t = g[v][j];
                if(isVisited[v_t])  continue;
                isVisited[v_t] = true;
                for(int k = 0; k < g[v_t].size(); ++k){
                    if(isVisited[g[v_t][k]])    continue;
                    q.push(g[v_t][k]);
                    isVisited[g[v_t][k]] = true;
                }
            }
        }
        ans++;
    }
    printf("-1\n");
            
    return 0;
}

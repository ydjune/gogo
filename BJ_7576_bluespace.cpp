//	BFS, Graph

#include <cstdio>
#include <queue>
#include <utility>  //pair

using namespace std;

int map[1000][1000];
int N,M;

queue<pair<int,int>> q;
int cnt = 0, total;
int days = -2;

int main()
{
    scanf("%d %d", &N, &M);
    total = N*M;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j){
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1){
                q.push({ i, j });
                map[i][j] = 0;
            }
            else if (map[i][j] == -1)
                total--;
        }
    
    
    while (!q.empty()){
        int qs = q.size();
        for (int i = 0; i < qs; ++i){
            auto v = q.front();
            q.pop();
            
            if (v.first < 0 || v.second < 0 || v.first >= M || v.second >= N || map[v.first][v.second] != 0)	continue;
            
            map[v.first][v.second] = 1;
            cnt++;
            q.push({ v.first + 1, v.second });
            q.push({ v.first, v.second + 1 });
            q.push({ v.first - 1, v.second });
            q.push({ v.first, v.second - 1 });
        }
        days++;
    }
    
    if (cnt == total)
        printf("%d\n", days);
    else
        printf("-1\n");
    
    return 0;
}

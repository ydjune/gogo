//	BFS

#include <cstdio>
#include <queue>
#include <cstring>	// memset

using namespace std;

struct Pos{
    int y, x;
    Pos operator+(const Pos& a){
        return {a.y+y, a.x+x};
    }
    bool operator==(const Pos& a){
        return (a.y == y && a.x == x);
    }
};

int tc;
int l;
Pos s, e;

int dist[300][300];

const Pos m[8] = { { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 } };

bool check(Pos& p){
    if (p.y < 0 || p.x < 0 || p.y >= l || p.x >= l || dist[p.y][p.x])
        return false;
    return true;
}

int main()
{
    scanf("%d", &tc);
    while (tc--){
        scanf("%d", &l);
        scanf("%d %d", &s.y, &s.x);
        scanf("%d %d", &e.y, &e.x);
        
        queue<Pos> q;
        q.push(s);
        dist[s.y][s.x] = 1;
        
        while (!q.empty()){
            Pos& n = q.front();
            q.pop();
            
            if (n == e){
                printf("%d\n", dist[n.y][n.x] - 1);
                break;
            }
            
            for (int i = 0; i < 8; ++i){
                Pos gone = n + m[i];
                if (!check(gone))	continue;
                
                dist[gone.y][gone.x] = dist[n.y][n.x] + 1;
                
                q.push(gone);
            }
        }
        memset(dist, 0, sizeof(dist));
    }
    
    return 0;
}

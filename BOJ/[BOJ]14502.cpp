#include <iostream>
using namespace std;

#include <iostream>
#include <queue>

using namespace std;

int N; int M;
int MAP[10][10];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

queue < pair<int, int>> bfsQu;

int DfsWall(int y, int x, int n_wall);
int BfsVirus();

int BfsVirus(int **bfsmap)
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (bfsmap[i][j] == 2) bfsQu.push(make_pair(i, j));
        }
    }
    
    while (bfsQu.size() > 0)
    {
        pair<int, int> here = bfsQu.front();  bfsQu.pop();
        int here_y = here.first;
        int here_x = here.second;
        
        for (int i = 0; i < 4; i++)
        {
                if (here_y + dy[i]<1 || here_x + dx[i]<1 || here_y + dy[i]>N || here_x + dx[i]>M)
                    continue;
                if (bfsmap[here_y + dy[i]][here_x + dx[i]] == 0)
                {
                    bfsmap[here_y + dy[i]][here_x + dx[i]] = 2;
                    bfsQu.push(make_pair(here_y + dy[i], here_x + dx[i]));
                }
        }
    }
    
    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (bfsmap[i][j] == 0) count++;
        }
    }
    
    return count;
}

int DfsWall(int y, int x, int n_wall)
{
    int ret = 0;
    if (n_wall == 3)
    {
        int **bfsmap = new int*[N+1]();
        for(int i=0;i<=N;i++)
            bfsmap[i]= new int[M+1];
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                bfsmap[i][j] = MAP[i][j];
            }
        }
        return BfsVirus(bfsmap);
    }
    
    int wall_y = y;
    int wall_x = x;
    
    for (int i = wall_y; i <= N; i++)
    {
        if( i != wall_y) wall_x =1;
        for (int j = wall_x; j <= M; j++)
        {
            if (MAP[i][j] == 0)
            {
                MAP[i][j] = 1;
                ret = max(ret, DfsWall(i, j, n_wall + 1));
                MAP[i][j] = 0;
            }
        }
    }
    return ret;
}

int main(int argc, const char * argv[])
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> MAP[i][j];
    
    //벽을 넣을 수 있는 경우의 수를 구하라
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (MAP[i][j] == 0)
            {
                ans = max(DfsWall(i, j, 0), ans);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}

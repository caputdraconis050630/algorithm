#include <bits/stdc++.h>
using namespace std;

typedef struct building
{
    int x, y, z;
} building;

int L, R, C;
int sx, sy, sz, ex, ey, ez; // start point(starts with s), ending point(starts with e)
char a[35][35][35];
int dist[35][35][35];

const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};

void bfs()
{
    queue<building> q;
    building _building = {sx, sy, sz};
    q.push(_building);
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, z = q.front().z;
        q.pop();
        if (x == ex && y == ey && z == ez)
        {
            printf("Escaped in %d minute(s).\n", dist[x][y][z]);
            return;
        }
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C)
                continue;
            if (dist[nx][ny][nz] || a[nx][ny][nz] == '#')
                continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;

            building tmp = {nx, ny, nz};
            q.push(tmp);
        }
    }
    printf("Trapped!\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> L >> R >> C;
        if (L == 0)
            break;
        memset(dist, 0, sizeof(dist));
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> a[i][j][k];
                    if (a[i][j][k] == 'S')
                        sx = i, sy = j, sz = k;
                    else if (a[i][j][k] == 'E')
                        ex = i, ey = j, ez = k;
                }
            }
        }
        bfs();
    }
    return 0;
}
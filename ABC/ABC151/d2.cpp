#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(){
    long long h, w;
    cin >> h >> w;

    char maze[h][w];

    for(long long i = 0; i < h; i++){
        for(long long j = 0; j < w; j++){
            cin >> maze[i][j];
        }
    }

    long long maxv = 0;
    for(long long sy = 0; sy < h; sy++){
        for(long long sx = 0; sx < w; sx++){
            for(long long gy = 0; gy < h; gy++){
                for(long long gx = 0; gx < w; gx++){
                    if(maze[gy][gx] == '#' || maze[sy][sx] == '#') continue;
                    queue<pair<long long, long long> > q;
                    vector<vector<long long> > distance(h, vector<long long> (w, -1));
                    q.push(make_pair(sy, sx));
                    distance[sy][sx] = 0;
                    long long dy[] = {1, -1, 0, 0};
                    long long dx[] = {0, 0, 1, -1};

                    while(!q.empty()){
                        pair<long long, long long> top;
                        top = q.front();
                        q.pop();

                        for(long long i = 0; i < 4; i++){
                            if(0 <= top.first+dy[i] and top.first+dy[i] < h and 0 <= top.second+dx[i] and top.second+dx[i] < w and distance[top.first+dy[i]][top.second+dx[i]] == -1 and maze[top.first+dy[i]][top.second+dx[i]] == '.'){
                                distance[top.first+dy[i]][top.second+dx[i]] = distance[top.first][top.second] + 1;
                                q.push(make_pair(top.first+dy[i], top.second+dx[i]));
                            }
                        }
                    }
                    maxv = max(maxv, distance[gy][gx]);
                }
            }
        }
    }

    cout << maxv << endl;
    return 0;
}
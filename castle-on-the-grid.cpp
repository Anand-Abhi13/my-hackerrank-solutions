#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>
using namespace std;
char mark = 'X';

int main() {
    int n;
    cin >> n;
    
    char c, m[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c;
            m[i][j] = c;
        }
    }
    
    int xs, ys, xd, yd;
    cin >> xs >> ys >> xd >> yd;

    queue<int> dist;
    queue<pair<int, int>> q;
    q.push(make_pair(xs, ys));
    dist.push(0);
    m[xs][ys] = mark;
    
    vector<pair<int, int>> mv = { make_pair(-1, 0), make_pair(0, +1), make_pair(+1, 0), make_pair(0, -1) };
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        
        if (cur.first == xd && cur.second == yd) {
            cout << dist.front() << endl;
            break;
        }
        
        for (int i = 0; i < mv.size(); ++i) {
            int newX = cur.first + mv[i].first;
            int newY = cur.second + mv[i].second;
            
            while (newX >= 0 && newX < n && newY >= 0 && newY < n && m[newX][newY] != mark) {                
                q.push(make_pair(newX, newY));
                dist.push(dist.front() + 1);
                m[newX][newY] = mark;
                
                newX += mv[i].first;
                newY += mv[i].second;
            }
        }
        
        q.pop();
        dist.pop();
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
#define NN 300
#define INF 10000000
 
//adjacency matrix
int cap[NN][NN];
 
// flow network
int fnet[NN][NN];
 
//BFS
int q[NN], qf,qb, prv[NN];
 
int fordFulkerson(int n, int s, int t)
{
   memset(fnet, 0, sizeof(fnet));
   int flow = 0;
   while(true)
   {
      // find the augmenting path
      memset(prv, -1, sizeof(prv));
      qf = qb = 0;
      prv[q[qb++] = s] = -2;
      // perform BFS on the graph for the given flow
      while(qb > qf && prv[t] == -1)
      {
         for(int u = q[qf++], v = 0; v < n; v++)
         {
            if(prv[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v])
            {
                prv[v] = u;
                q[qb++] = v;
            }
         }
      }
      if(prv[t] == -1)
         break;
      int bot = 0x7FFFFFFF;
      // parsing the path from target to source
      // to find the minimum flow possible across the path
      for(int v = t, u = prv[v]; u >= 0; v = u, u = prv[v])
      {
          bot =  min(bot, cap[u][v] - fnet[u][v] + fnet[v][u]);
      }
      // parsing the path from target to source
      // to add mininum flow possible
      for(int v = t, u = prv[v]; u >= 0; v = u, u = prv[v] )
      {
          fnet[u][v] += bot;
      }
      flow += bot;
   }
   return flow;
}
 
#define A(x) ((x) * 2 + 2)
#define B(x) ((x) * 2 + 3)
#define source 0
#define target 1
 
int c, n, m, t, a, b;
int main()
{
  for(cin >> c; c--;)
  {
      cin >> n >> t >> m;
      memset(cap, 0, sizeof(cap));
      // form a bridge from even to odd
      for(int i = 0; i < m; i++)
      {
          cin >> a >> b;
          cap[A(a)][B(b)] = INF;
          cap[A(b)][B(a)] = INF;
      }
      // form a bridge from source to even
      // form a bridge from odd to target
      for(int i = 0; i < n; i++)
      {
          // source to even flow = t
          cap[source][A(i)] = t;
          // odd to target flow = 1
          cap[B(i)][target] = 1;
      }
      int result = fordFulkerson(2 * n + 2, source, target);
      cout << result << endl;
  }
  return 0;
}

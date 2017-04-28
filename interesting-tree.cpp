#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[100005]={false};
int height[100005]={0},diameter[100005]={0};
vector<int> graph[100005];
int dfs(int root)
{
    visited[root]=true;
    vector<int>::iterator it;
    int temp1=0,temp2=0,temp3=0;
    if(graph[root].size()==0)
        {
            height[root]=0;
            diameter[root]=0;
            return 0;
        }
    for(it=graph[root].begin();it!=graph[root].end();it++)
    {
        if(visited[*it]==true)
        continue;
     diameter[*it]=dfs(*it);
     if(height[*it]>temp1)
     {
         temp2=temp1;
         temp1=height[*it];
     }
     else if(height[*it]>temp2)
     {
         temp2=height[*it];
     }
     temp3=max(temp3,diameter[*it]);
    }
    height[root]=temp1+1;
    return max(1+temp1+temp2,temp3);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
 int n,i,u,v,r,q,a;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin>>r;
    diameter[r]=dfs(r);
    cin>>q;
    while(q--)
    {
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        cin>>a;
        //cout<<a;
        cout<<diameter[a]-1<<endl;
    }
    return 0;
}

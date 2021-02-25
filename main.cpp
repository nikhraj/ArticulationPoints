#include <bits/stdc++.h>
using namespace std;
vector <int> ans;
unordered_map <int,vector <int>> m;

int components(int n,int vertex)
{
    int c=0;
    vector <bool> vis(n,0);
    vis[vertex]=true;
    for(int i=0;i<n;i++)
    {
        if(vis[i])
        {
            continue;
        }
        else
        {
            c++;
            queue <int> q;
            q.push(i);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int v:m[u])
                {
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v]=1;
                    }
                }
            }
        }
    }
    return c;
}

void mincutvertices(int n,vector <vector <int>> &edgeList)
{
    
    for(auto i:edgeList)
    {
        m[i[0]].push_back(i[1]);
        m[i[1]].push_back(i[0]);
    }

    for(int i=0;i<n;i++)
    {
        int temp=components(n,i);
       // cout<<temp<<" ";
        if(temp>1)
        {
            ans.push_back(i);
        }
    }

}

int main()
{
    int edges,vertices;
    ifstream input;
    input.open("input2.txt");
    input>>edges;
    input>>vertices;
    vector <vector <int>> edgeList;
    for(int i=0;i<edges;i++)
    {
        int p,q;
        input>>p;
        input>>q;
        edgeList.push_back({p,q});
    }
    
    mincutvertices(vertices,edgeList);
    cout<<"All possible cut vertices are : "<<endl;

    for(auto i:ans)
    {
        cout<<i<<endl;
    }
    return 0;
}
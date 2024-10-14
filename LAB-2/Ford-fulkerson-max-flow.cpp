#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int MaxFlow(vector < vector <int> > , int , int );
bool Bfs(vector < vector <int> > , int , int ,vector <int> &);
void Print(vector <vector <int> >);
void Print1d(vector <int>);
void PrintTheResult(vector <vector <int> >);

int main(){
    int n;
    cin>>n;
    vector < vector <int> > g(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)     // inputing the graph 
    {
        for (int j = 0; j < n; j++)
        {
            cin>>g[i][j];
        }
    }
    // cout<<"!111\n";
    int maxFlow = MaxFlow(g,0,n-1);
    cout<<"The MaxFlow is : "<<maxFlow<<endl;
    return 0;
}

int MaxFlow(vector < vector <int> > g, int source_node, int sink_node){
    int max_flow=0;
    int n = g.size();
    int bottle_neck_capacity=0,u;
    int i=0;

    vector < vector <int> > rgraph =g;
    vector < vector <int> > matToPrint(n,vector<int>(n,0));
    vector <int> parent (g.size(),0);
    
    while (Bfs(rgraph,source_node,sink_node,parent) && i<6)
    {
        bottle_neck_capacity=INT32_MAX;

        for(int v = sink_node ; v != source_node ; v = parent[v])   // fingind the bottleneck of the path
        {
            u=parent[v];
            bottle_neck_capacity = min(rgraph[u][v],bottle_neck_capacity);
        }
        
        for(int v = sink_node ; v != source_node ; v = parent[v])   // subtracting and adding the bottleneck from forward edge and backward edge respectively 
        {
            u=parent[v];
            matToPrint[u][v]+=bottle_neck_capacity;
            rgraph[u][v]-=bottle_neck_capacity;
            rgraph[v][u]+=bottle_neck_capacity;
        }
        max_flow += bottle_neck_capacity;
        i++;
    }
    PrintTheResult(matToPrint);
    return max_flow;
}

bool Bfs(vector < vector <int> > rgraph, int source_node, int sink_node,vector <int> &parent){
    vector <int> visited(rgraph.size(),0);
    queue <int> q;
    int u,v,n=rgraph.size();

    q.push(source_node);
    
    visited[source_node]=1;
    parent[source_node]=-1;
    
    while(!q.empty()){
        u=q.front();q.pop();
        for ( v = 0; v < n; v++)
        {
            if(visited[v] == 0 && rgraph[u][v]>0)
            {
                if(v == sink_node)
                {
                    parent[v]=u;
                    return true;
                }

                q.push(v);
                visited[v]=1;
                parent[v]=u;
            }
        }
    }
    return false;
}

void Print(vector <vector <int> >a){
    cout<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Print1d(vector <int>a){
    cout<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void PrintTheResult(vector <vector <int> >a){
    cout<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size();j++)
        {
            if(a[i][j] !=0){
                cout<<i<<"->"<<j<<" : ";
                cout<<a[i][j]<<"";
                cout<<endl;
            }
        }
        // cout<<endl;
    }
    cout<<endl;
}
#include<iostream>
#include<vector>
using namespace std;


void print(vector < vector<int> > a){
    for(int i =0;i<a.size();i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print( vector<int>  a){
    for(int i =0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

vector <vector<int> > fill_edges(vector<vector<int> > mat){
    // this function is has the of covering the undirected graph
    vector <vector<int> > edges;
    for(int i =0;i<mat.size();i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if(mat[i][j] == 1 && mat[j][i] == 1){
                mat[i][j]=0;
                mat[j][i]=0;
                vector<int> d;
                d.push_back(1);
                d.push_back(i);
                d.push_back(j);
                edges.push_back(d);
            }
        }
    }
    return edges;

}

int Find(int u,  vector <int>  &parent){
    if(u == parent[u]){
        return u;
    }
    return parent[u] = Find(parent[u],parent);
}

bool can_we_stop(vector <int> parent){
    vector <int> d;
    int dd,f;
    for(int i =0;i<parent.size();i++)
    {
        dd=Find(i,parent);
        f =0;
        for (int j = 0; j < d.size(); j++)
        {
            if(d[j] == dd){
                f=1;
                break;
            }
        }
        if(!f){;
            d.push_back(dd);
        }
    }
    if(d.size() == 2){
        return true;
    }
    else
        return false;    
}

void Union(int u, int v , vector <int>  &parent){
    u = Find(u,parent);
    v = Find(v,parent);
    parent[v]=u;
}

int select_edge(vector<vector<int> > &edges){
    // random number of edge using random() function
    srand(time(0));
    int randomEdge;
    do{
        int random=rand()%edges.size();
        // cout<< "random variable"<< random<<endl;
        randomEdge = random;
    }while(edges[randomEdge][0]!=1);
    edges[randomEdge][0]=0;
    return randomEdge;
}

void mincut(vector <vector <int> > mat,vector <vector <int> > &edges,vector <int>  &parent){
    while(!can_we_stop(parent)){
        // st 1 pick a random edge
        int e = select_edge(edges);
        // st 2 remove that edge and merge the vertice connected by the edge i.e by union and find 
        if(Find(edges[e][1],parent) != Find(edges[e][2],parent)){
            Union(edges[e][1],edges[e][2],parent);
        }
        /*else{
            //self loop block
            // st 3 check for self loop and remove it
            // no need do anything to detect self loop as i am going to display only those edges who are still not marked
            // randomly selected edge is by default marked by the function of selecting the edge 
            // upon reaching here i check whether the vertices connected by this edge is in same set i.e. have same parent or not
            // if it has different parent then i do union of that two vertices that collapsing the edge
            // if it has same parent i.e. it is self loop then i don't do anything and random edge func marked that edge as visited by default 
            // so need to maintain extra data structure and processing for finding the self loop
            // added extra security at last printing if there is any self loop remaining then dont print it and it is fulfilled using find method()
        }*/
        for (int i = 0; i < parent.size(); i++)
        {
            Find(i,parent);
        }
    }
    // run untill there are 2 set of vertices
}

int main(){
    int n;
    cin>>n; // enter the number of nodes
    vector <vector <int> > mat(n,vector<int>(n,0));
    vector <int> parent(n,0);
    for(int i =0;i<n;i++){
        parent[i]=i;
        for (int j = 0; j < n ;j++)
            cin>>mat[i][j];
    }
    vector <vector<int> > edges=fill_edges(mat);
    mincut(mat,edges,parent);
    int d=0;
    for (int i = 0; i < edges.size(); i++)
    {
        if(edges[i][0] == 1 && (Find(edges[i][1],parent) != Find(edges[i][2],parent))){
            cout<<edges[i][1]<<"->"<<edges[i][2]<<endl;
            d++;
        }
    }
    cout<<"The min cut set size is : "<<d<<endl;
    cout<<"Parent : ";
    print(parent);
    
    return 0;
}
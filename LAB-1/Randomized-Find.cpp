#include<iostream>
#include<vector>
using namespace std;
// RandomizedQuickSort & QuickSort ma st and end are inclusive i.e. for(i = st; i <= end ;i++){}
int RandomizedFind(vector <int> &,int ,int,int);
int RandomPartition(vector <int> &,int ,int );
void Print(vector <int>);
int GetARandomIndex(int ,int );
int Partition(vector <int> &,int, int);

int main(){
    int n;
    cin>>n;
    vector <int> array(n,0);
    for (int i = 0; i < array.size(); i++)
        cin>>array[i];  
    RandomizedFind(array,0,n-1,n-2);
    cout<<array[n-2]<<endl;
    Print(array);
    return 0;
}

int RandomizedFind(vector <int>&a,int st,int end,int index){
        int partition = RandomPartition(a,st,end);
    if(partition == index)
        return partition;
    else if(partition>index)
        RandomizedFind(a,st,partition-1,index);
    else if(partition<index)        
        RandomizedFind(a,partition+1,end,index);
    
}

int RandomPartition(vector <int> & a,int st, int end){
    if(st<end){
        int randVar=GetARandomIndex(st,end);
        swap(a[randVar],a[end]);
        return Partition(a,st,end);
    }
}

int Partition(vector <int> &a,int st, int end){
    int i,j=st-1;
    for ( i = st; i <end ; i++)
    {
        if(a[i] < a[end]){ // pivot karta nana element
            j++;
            swap(a[i],a[j]);
        }
    }
    swap(a[j+1],a[end]);
    return j+1;

}
int GetARandomIndex(int start_limit,int end_limit){
    int n = ( rand() % ( end_limit - start_limit + 1 ) ) + start_limit;
    return n;
}
void Print(vector <int>a){
    cout<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
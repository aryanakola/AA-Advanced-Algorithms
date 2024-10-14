#include<iostream>
#include<vector>
using namespace std;
// RandomizedQuickSort & QuickSort ma st and end are inclusive i.e. for(i = st; i <= end ;i++){}
void RandomizedQuickSort(vector <int> &,int ,int);
void QuickSort(vector <int> &,int ,int );
void Print(vector <int>);
int GetARandomIndex(int ,int );
int Partition(vector <int> &,int, int);

int main(){
    int n;
    cin>>n;
    vector <int> array(n,0);
    for (int i = 0; i < array.size(); i++)
        cin>>array[i];  
    RandomizedQuickSort(array,0,n-1);
    Print(array);
    return 0;
}

void RandomizedQuickSort(vector <int>&a,int st,int end){
    if(st<end){
        int randVar=GetARandomIndex(st,end);
        swap(a[randVar],a[end]);
        QuickSort(a,st,end);
    }
}

void QuickSort(vector <int> & a,int st, int end){
    if(st<end){
        int partition = Partition(a,st,end);
        RandomizedQuickSort(a,st,partition-1);
        RandomizedQuickSort(a,partition+1,end);
    }
}

void Print(vector <int>a){
    cout<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int GetARandomIndex(int start_limit,int end_limit){
    int n = ( rand() % ( end_limit - start_limit + 1 ) ) + start_limit;
    return n;
}
// partition function typed by me ready 
// but testing done
// working very well
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
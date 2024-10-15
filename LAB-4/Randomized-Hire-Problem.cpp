#include<iostream>
#include<vector>
using namespace std;

void Print(vector <int> );
int GetARandomTalent(int,int);

int main(){
    srand(time(0));
    int n;
    cin>>n;
    vector <int> candidate(n,0);
    for (int i = 0; i < n; i++)
    {
        candidate[i] = GetARandomTalent(1,n);
    }
    // Print(candidate);

    int best = 0;
    int hired =0;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(best<candidate[i]){
            best = candidate[i];
            hired=i;
            count++;
        }
    }
    cout<<hired<<" "<<best<<endl<<count;
    
    return 0;
}

int GetARandomTalent(int start_limit,int end_limit)
{
    int n = ( rand() % ( end_limit - start_limit + 1 ) ) + start_limit;
    return n;
}

void Print (vector <int> a){
    cout<<endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
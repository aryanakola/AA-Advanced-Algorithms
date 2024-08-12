// using 0/1 Knapsack algo with have find the sum of subset

#include<iostream>
#include<vector>
using namespace std;

void print2(vector <vector <int> > t){
    for ( int i = 0; i < t.size(); i++)
    {
        for ( int j = 0; j < t[0].size(); j++)
        {
            cout<<t[i][j]<<" ";
        }cout<<endl;

    }cout<<endl;
}

bool knapsack(vector <int> profit,vector <int> weight,int profitBound, int weightBound){
    // cout<<"Profit array : ";
    // for(int i=0;i<profit.size();i++){
    //     cout<<profit[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"Weight array : ";
    // for(int i=0;i<weight.size();i++){
    //     cout<<weight[i]<<" ";
    // }
    // cout<<endl;
    // int t[weight.size()+1][weightBound+1];
    int m=weight.size()+1,n=weightBound+1;
    vector <vector<int> > t (m,vector <int> (n));
    int i,j;
    // cout<<weight.size()+1<<endl;
    // cout<<weightBound+1<<endl;
    for ( i = 0; i <weightBound+1 ; i++)
    {
        t[0][i]=0;
    }
    for ( i = 0; i <weight.size()+1 ; i++)
    {
        t[i][0]=0;
    }
    for ( i = 1; i < weight.size()+1; i++)
    {
        for ( j = 1; j < weightBound+1; j++)
        {        
            if(j<weight[i-1]){
                t[i][j]=t[i-1][j];
            }
            if(j>= weight[i-1]){
                t[i][j]=max(t[i-1][j],profit[i-1]+t[i-1][j-weight[i-1]]);
            }
        }
        // the error which was occuring was due to not taking weight and profit of index i-1 instead i was taking it of i
    }
    // print2(t);
    // cout<<t[weight.size()][weightBound]<<endl;
    if(t[weight.size()][weightBound] >= profitBound)
        return true;
    else
        return false;
}


bool sos(vector <int> s,int sum){
    // for(int i=0;i<s.size();i++){
    //     cout<<s[i]<<" ";
    // }
    vector <int> profit = s;
    vector <int> weight = s;
    int profitBound =sum;
    int weightBound=sum;
    if(knapsack(profit,weight,profitBound,weightBound)){
        return true;
    }
    else
        return false;
}

int main()
{
    vector<int>s;
    int sum;
    int n,x;
    cout<<"enter the size of array\n";
    cin>>n;
    cout<<"enter the element of the sos array\n";
    for (int  i = 0; i < n; i++)
    {
        cin>>x;
        s.push_back(x);
    }
    cout<<"enter the sum you want to find : ";
    cin>>sum;
    cout<<"the answer is ";
    if(sos(s,sum))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
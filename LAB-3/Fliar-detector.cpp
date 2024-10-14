// program to find fliar and its probability of occuring
#include<iostream>
#include<bitset>
using namespace std;

void FliarDetection(int ,int );
int FermatsLittleTheorem(int ,int ,int);

int main()
{
    int n;
    cin>>n;
    FliarDetection(n,n-2);
    // cout<<n<<" is a prime = "<<a;
    return 0;
}

void FliarDetection(int n,int k)
{
    int fliar=0,fwitness=0;
    while(k>1){
        if(FermatsLittleTheorem(k,n-1,n) == 1){
            cout<<"Falsy value : "<<k<<endl; 
            fliar++;
        }
        else    
            fwitness++;
        k--;
    }
    float f = fliar /(float)(n-3);
    cout<<"Probability of F-liar is : "<<f<<endl;
}

int FermatsLittleTheorem(int a,int m,int n){
    // from  here we remaining
    // a^m % n = 1
    // using bitset to convert m into binary
    bitset <32> mm (m);
    int count;
    for (int i = 30; i >= 0; i--)
    {
        if(mm[i]==1){
            count =i;
            break;
        }
    }
    int res=1;
    for (int i = count; i >=0; i--)
    {
        res = (res * res) % n ;
        if (mm[i] == 1)
            res = (res * a)%n;
    }
    return res;
}
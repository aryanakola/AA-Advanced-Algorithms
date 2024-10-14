#include<iostream>
#include<bitset>
using namespace std;

bool RandomizedPrimalityTesting(int ,int );
int GetARandomA(int ,int);
int Gcd(int,int);
int FermatsLittleTheorem(int ,int ,int);

int main()
{
    int n,k=100;
    cin>>n;
    
    bool a = RandomizedPrimalityTesting(n,k);
    cout<<n<<" is a prime = "<<a;
    return 0;
}

bool RandomizedPrimalityTesting(int n,int k)
{
    while(k>0){
        int a = GetARandomA(2,n-1);
        if(Gcd(n,a) !=1){
            return false;
        }
        if(FermatsLittleTheorem(a,n-1,n) != 1){
            return false;
        }
        k--;
    }
    return true ;
}

int GetARandomA(int start_limit,int end_limit)
{
    int n = ( rand() % ( end_limit - start_limit + 1 ) ) + start_limit;
    return n;
}

int Gcd(int a,int b)
{
    if( b==0){
        return a;
    }
    return Gcd(b,a%b);
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
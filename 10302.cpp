#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll a[100100];
ll n;

void go()
{
   
   while(cin >> n){
       ll t=  (n*(n+1))/2;
       t = t*t;
       cout << t << endl;
   }
}


int main()
{
    NeedForSpeed 

    int t = 1;
    
    while (t--)
        go();
}
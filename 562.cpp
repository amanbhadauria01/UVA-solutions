#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 1000100;
bool t[2][N];
ll a[N];

void go()
{   
   ll n;
   cin >> n ;
   for(int i = 0 ; i < n ; i++) cin >> a[i];
   ll w = 0;
   for(int i = 0 ;i < n ; i++) w += a[i];
//    memset(t,false,sizeof(t));
   ll sum = w;
    w= w/2;
   for(int i = 0 ; i <= w  ; i++){
       t[0][i] = false;
   }
   t[0][0] = true;
   t[1][0] = true;
   for(int i = 1 ; i <= n ; i++){
       for(int j = 1 ; j <= w ; j++){
           // taken 
            if(a[i-1] <= j){
                t[i%2][j] = (t[(i-1)%2][j] || t[(i-1)%2][j-a[i-1]]);
            }
           // no taken
           else {
               t[i%2][j] = t[(i-1)%2][j];
           }
       }
   }
   ll mi = 0;
   for(int j = 0 ; j <= w ; j++){
       if(t[(n%2)][j]==true) mi = j;
   }
   cout << sum - 2*mi ;
}


int main()
{
    NeedForSpeed 

    ll t = 1;
    cin >> t;
    while (t--){
        go();
        cout << endl;
    }
       
}   
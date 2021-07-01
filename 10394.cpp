#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll const N = 2e7 + 10;
bool prime[N];
int tp[N];

void filler(){
  memset(prime,true,sizeof(prime));
  for(int i = 2;  i*i < N; i++){
      if(prime[i]==true){
          for(int p = i*i ; p < N ; p += i ){
             prime[p] = false; 
          }
      }
  }
}

void filler2(){
    int j = 0;
    for(int i = 2 ; i < N-2 ; i++){
        if(prime[i]==true && prime[i+2]==true){
           tp[j] = i;
           j++;   
        }
    }
    // cout << j << endl;
}

void go()
{
    int t;
    while(cin >> t){
        cout << "(" <<  tp[t-1] << ", " << tp[t-1]+2 << ")" ;
        if(t!=0) cout << endl;
    }
}

int main()
{
    NeedForSpeed int t = 1;
    // cin >> t;
    filler();
    filler2();
    while (t--)
        go();
}
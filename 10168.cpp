#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll const N = 1e7+10;
bool prime[N];
vector<int> p;


void filler(){
  memset(prime,true,sizeof(prime));
  for(int i = 2 ; i*i < N ; i++){
     if(prime[i]==true){
         for(int p = i*i ; p < N ; p += i){
             prime[p] = false;
         }
     }
  }
  for(int i = 2 ; i < N ; i++){
      if(prime[i]){
         p.push_back(i);
      }
  }
//   for(int i = 0 ; i < p.size(); i++){
//       cout << p[i] << endl;
//   }
}

void gold(int n){
   for(int i = 2 ; i <= n ; i++){
     if(prime[i] == true && prime[n-i]==true){
      cout << i << " " << n-i ; return;
      }
   }
}

void go()
{
  int n;
  filler();
//   cout << "here" << endl;
  while(cin >> n){
      if(n < 8){
          cout << "Impossible." << endl;
      }else{
          if(n%2 == 0){
              cout << 2 << " " << 2 << " " ; gold(n-4) ; cout << endl;
          }else{
              cout << 2 << " " << 3 << " ";  gold(n-5) ; cout << endl;
          }
      }
  }
}

int main()
{
    NeedForSpeed int t = 1;
    // cin >> t;
    while (t--)
        go();
}
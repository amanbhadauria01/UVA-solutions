#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 400100;
vector<ll> graph[N];
bool visited[N];
ll  color[N];
ll n,m;
#define BLACK 0
#define WHITE 1
ll ans = 0;
vector<ll> a;
void bt(int i){
    // base case
    if(i==n){
        //  cout << "here" << endl;
         ll blk = 0;
         for(int i = 0 ; i < n ; i++){
             if(color[i]==BLACK){
                 blk++;
             }
         }
         // update if found better ans
         if(blk > ans){
            ans = blk;
            a.clear();
            for(int i = 0 ; i < n  ; i++){
                if(color[i]==BLACK)
                 a.push_back(i);
            }
         }
         return;
    }
    // body
    bool canBlack = true;
    for(int j = 0 ; j  <  (int)graph[i].size(); j++){
        int next = graph[i][j];
        if(visited[next] && color[next]==BLACK){
            canBlack = false;
            break;
        }
    }
    visited[i] = true;
    if(canBlack){
       color[i] = BLACK;
       bt(i+1);
    }
    color[i] = WHITE;
    bt(i+1);
    visited[i] = false;
}


void go()
{  
   cin >> n >> m;
   for(int i = 0 ; i <= n ; i++){ graph[i].clear(); visited[i] = false;  }
   
   for(int i = 0 ; i < m ; i++){
       ll x, y;
       cin >> x >> y;
       x--; y--;
       graph[x].push_back(y);
       graph[y].push_back(x);
   } 
    a.clear();
    ans = 0;
    bt(0);
    cout << ans << endl;
    for(int i = 0 ;i < a.size();  i++ ) cout << a[i]+1 << " ";
    cout << endl;
}


int main()
{
    NeedForSpeed 

    ll t = 1;
    cin >> t;
    while (t--)
        go();
}
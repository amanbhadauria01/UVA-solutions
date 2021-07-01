#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 400100;
ll a[5];
bool ans = false;
bool visited[5] ;
vector<int> f;


void bt(int i,int curr){
    // base case
    if(ans == true) return;
    if(i==4){
       if(curr == 23){
           ans = true;
       }
       return ;
    }
    // body
    for(int j = 0 ; j < 5 ; j++){
    if(visited[j]) continue;    
    visited[j] = true;

    // +
    curr = curr + a[j];
    bt(i+1,curr);
    curr = curr - a[j];

    // - 
    curr = curr - a[j];
    bt(i+1,curr);
    curr = curr + a[j];

    // *
    int temp = curr;
    curr = curr*a[j];
    bt(i+1,curr);
    curr = temp;

    visited[j] = false;
    }
}

void go()
{  
    memset(visited,false,sizeof(visited));
    ans = false;
    vector<int> c;
    c.clear();
    for(int i = 0 ; i < 5 ; i++)
    {   visited[i] = true;
        bt(0,a[i]);
        visited[i] = false; }
    if(ans)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}


int main()
{
    NeedForSpeed 

    ll t = 1;
    // cin >> t;
    while (1){
        bool doit = false;
        for(int i = 0 ; i < 5 ; i++){
          cin >> a[i];
          if(a[i]!=0){
              doit = true;
          }
        }
        if(!doit) break;
        go();
    }    
}
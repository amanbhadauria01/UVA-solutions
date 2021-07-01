#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 400100;
unordered_map<string,vector<pair<ll,ll>>> M; 
ll b;
bool possible(ll x){
    ll onecost = INF;
    ll cost = 0;
    for(auto i : M){
          onecost = INF;
          for(auto j : i.second){
              if(j.second >= x){
                  onecost = min(onecost,j.first);
              }
          }
          cost += onecost;
          if(cost > b){
              return false;
          }
    }
    return true;
}

void go()
{  
    ll n ;
    cin >> n >> b;
    string s,t;
    ll p,q;
    M.clear();
    for(int i = 0 ; i< n ; i++){
        cin >> s >> t >> p >> q;
        M[s].push_back({p,q});
    }
    ll low = 0 , high = INF;
    ll mid;
    ll ans = 0;
    while(low <= high){
        mid = (low+high)/2;
        if(possible(mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout << ans << endl;  
}


int main()
{
    NeedForSpeed 

    ll t = 1;
    cin >> t;
    while (t--){
        go();
    }    
}   
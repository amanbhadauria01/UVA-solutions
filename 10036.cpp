#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 1e6 + 10;
ll a[N];
bool dp[10010][101][101];
bool visited[10010][101][101];

bool rec(int i , int n , int k, int sum){
    // base case
    if(i==n){
       if(sum%k == 0){
           return true;
       }
       return false;
    }
    if(visited[i][k][sum]) return dp[i][k][sum];
    // plus
    bool ans = rec(i+1,n,k,(sum+a[i])%k);
    // minus
    ans = (ans || rec(i+1,n,k,(sum-a[i]+k)%k ) );
    dp[i][k][sum] = ans;
    visited[i][k][sum] = true;
    return ans;
}

void go(){  
    ll n , k;
    cin >> n >> k;
    for(int i = 0 ;i < n ; i++){
        cin >> a[i];
        for(int j = 0 ; j <= k ; j++){
            for(int x = 0 ; x <= k ; x++){
                visited[i][j][x] = false;
                dp[i][j][x] = false;
            }
        }
    }
    bool ans =  rec(0,n,k,0);
    if(ans) cout << "Divisible";
    else cout << "Not divisible";
}

int main() {
        NeedForSpeed
       int t;
       cin >> t;
       while(t--) {go(); cout << endl; }        
}

  	 			 		   	 		 						 	  		
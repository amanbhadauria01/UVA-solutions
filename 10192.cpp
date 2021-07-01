#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 1000100;
string a,b;
ll t[1000][1000];
ll cases = 1;

ll lcs(string &a , string &b , ll i , ll j){
    // base case
    if(i == a.size() || j == b.size()){
         return 0;
    }
    // body
    if(t[i][j] != -1) return t[i][j];
    ll ans = 0;
    if(a[i]==b[j]){
        t[i+1][j+1] = lcs(a,b,i+1,j+1);
        ans = t[i+1][j+1] + 1;
    }
    t[i+1][j] = lcs(a,b,i+1,j);
    t[i][j+1] = lcs(a,b,i,j+1);
    ans = max(ans,max(t[i+1][j],t[i][j+1]));
    t[i][j] = ans;
    return ans;
}

void go()
{   
    memset(t,-1,sizeof(t));
    ll ans = lcs(a,b,0,0);
    cout << "Case #"<< cases << ": you can visit at most "<< ans << " cities.";
    cases++;
}


int main()
{
    NeedForSpeed 

    ll t = 1;
    // cin >> t;
    while (1){
        getline(cin,a);
        if(a.size() > 0 && a[0]=='#') break;
        getline(cin,b); 
        go();
        cout << endl;
    }    
}   
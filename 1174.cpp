#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 2e5 + 10;
vector<pair<int,pair<string,string> > > edges;
unordered_map<string,string> p;
unordered_map<string,int> r;


string findP(string a){
    if(a==p[a]){
        return a ;
    }
    return p[a] = findP(p[a]);
}

int joint(string a, string b){
   a = findP(a); b = findP(b);
   if(a != b){
      if(r[a] > r[b]){
          r[b] += r[a];
          p[a] = b;
      }else{
          r[a] += r[b];
          p[b] = a;
      }
      return 1;
   }
   return 0;
}
void go()
{
  int n , m;
  cin >> m >> n;
  edges.clear(); p.clear(); r.clear();

  for(int i = 0 ; i < n ; i++){
      string a,b;
      int c;
      cin >> a >> b >> c;
      edges.push_back({c,{a,b}});
      p[a] = a; p[b] = b; r[a] = 1; r[b] = 1;
  }
  sort(edges.begin(),edges.end());
  ll sum = 0 ;
  for(int i = 0 ; i< n ; i++ ){
      if(joint(edges[i].second.first , edges[i].second.second)){
         sum += edges[i].first;
      }
  }
  cout << sum;
}

int main()
{
    NeedForSpeed 
    ll t = 1;
    cin >> t;
    while (t--)
       {  go(); if(t!=0) cout << endl << endl;}
}

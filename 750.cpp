#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 400100;
bool col[8],row[8];

ll tiiime;
vector<string> answers;

bool cT(int c){
    if(col[c]) return false;
    return true;
}

bool rT(int r){
    if(row[r]) return false;
    return true;
}

bool dT(int x, int y,vector<pair<ll,ll>> points){
    for(auto i : points){
        if(abs(x-i.first)==abs(y-i.second)) return false;
    }
    return true;
}

void bt(ll r,vector<pair<ll,ll>> points){
    // base case , also prints answer here
    if(r == 8){
      vector<int> sol(8);
      string s;
      for(auto i : points){
          sol[i.second] = i.first;
      }
      for(int i = 0 ;i < 8 ; i++){
           s  += to_string(sol[i]+1) ;
      }
      answers.push_back(s);
      return;
    }
    // body
    if(rT(r) == false) bt(r+1,points);
    else
    for(int i = 0 ; i < 8 ; i++){
        if(cT(i) && rT(r) && dT(r,i,points)){
             points.push_back(make_pair(r,i));
             row[r] = true;
             col[i] = true;
             bt(r+1,points);
             row[r] = false;
             col[i] = false;
             points.pop_back();
        }
    }
}


void go()
{  
   ll x, y;
   cin >> x >> y;
   x--; y--;
   answers.clear();
   memset(col,false,sizeof(col));
   memset(row,false,sizeof(row));
   row[x] = true;
   col[y] = true;
   vector<pair<ll,ll>> points;
   points.push_back(make_pair(x,y));
   cout << "SOLN       COLUMN" << endl;
   cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
   tiiime = 1;
   bt(0,points);
   sort(answers.begin(),answers.end());
   for(int i = 0 ; i < answers.size(); i++){   
     cout << " " <<tiiime <<"      " ;
     tiiime++;
     for(int j = 0 ; j < 8 ; j++){
         cout << answers[i][j] << " ";
     }
     cout << endl;
   }
   cout << endl;
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
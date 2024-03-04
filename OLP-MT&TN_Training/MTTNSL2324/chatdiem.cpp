#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
 
void solve(){
    double x1,x2,v1,v2;
    cin >> x1 >> x2 >> v1 >> v2;
    if (v1 == v2 && x1 !=x2){
        cout << -1;
        return;
    }
    if (x1 == x2){
        cout << 0;
        return;
    }
    if (x1 < x2 && v1 < 0 && v2 > 0){
        cout << -1;
        return;
    }
    double up = x1 -x2;
    double down = v2 - v1;
    double t = up/down;
    cout << fixed << setprecision(4) << t;
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}
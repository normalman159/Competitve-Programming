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
    ll t; cin >> t;
    while (t--){
        vector<ll>v;
        for (ll i=1;i<=7;i++){
            ll x;
            cin >> x;
            v.pb(x);
        }
        sort(ALL(v));
        cout << v[0] << " " << v[1] << " " << v[6] - v[0] - v[1] << ln;
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}
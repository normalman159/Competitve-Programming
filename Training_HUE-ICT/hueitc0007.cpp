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
    auto cnt = [&](ll x){
        return x / 4 - x / 100 + x / 400;
    };
    ll t; cin >> t;
    while (t--){
        ll a,b; cin >> a >> b;
        ll leaf_a = cnt(a-1);
        ll leaf_b = cnt(b);
        cout << leaf_b - leaf_a << ln;
    }

}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}
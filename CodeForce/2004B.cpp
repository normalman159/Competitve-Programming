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
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

//Modulo Calculation
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (long long)x * y % MOD;
}

void solve_sub(){
    ll l,r, L,R; cin >>l >> r >> L >> R;
    ll L_M = max(L,l) , R_M = min(r,R);
    if (!(L_M <= R_M)) {cout << 1 << ln; return;}
    ll ans = R_M - L_M;
    ans += (l != L); ans+= (r!=R);
    cout << ans<< ln;
}

void solve(){
    ll t; cin >> t;
    while (t--){
        solve_sub();
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}



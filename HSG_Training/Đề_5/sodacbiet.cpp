#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 3e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll l, r,s[MXN];

void tinhuoc(ll r){
    fill(s+1,s+1+r,1);
    for (ll i = 2;i*i<=r;i++){
        for (ll j = i*i;j<=r;j+=i){
            s[j] +=i;
            if (i*i!=j){
                s[j] += j/i;
            }
        }
    }
}

void solve(){
    cin >> l >> r;
    ll ans = 0;
    tinhuoc(r);
    for (ll i = l;i<=r;i++){
        if (s[i] > i){
            ans++;
        } 
    }
    cout << ans;
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
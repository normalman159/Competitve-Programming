#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
string s;
const ll Lim = 1e6+5;
ll a[30];
ll gt[Lim];
ll giaithua(ll n){
    if (n==0) return 1;
    ll res = 1;
    for (ll i=1;i<=n;i++){
        res = (res*i)%MOD;
    }
    return res;
}

ll powMod(ll a, ll b){
    ll res  =1;
    while (b > 0){
        if (b&1){
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b/=2;
    }
    return res;
}

void solve(){
    cin >> s;
    for (ll i=0;i<s.size();i++){
        a[s[i] - 'A']++;
    }
    ll cntodd = 0;
    ll n=0;
    for (ll i=0;i<27;i++){
        n+= a[i]/2;
        if (a[i] & 1) cntodd++;
    }
    if (cntodd>=2){
        cout << 0;
        return;
    }
    ll up = giaithua(n);
    ll down  =1;
    for (ll i=0; i < 27;i++){
        down = (down * giaithua(a[i]/2))%MOD;
    }
    ll res = (up * powMod(down,MOD-2))%MOD;
    cout << res;
}
int main()
{
    // freopen("CNTPALIN.INP","r",stdin);
    // freopen("CNTPALIN.OUT","w",stdout);
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
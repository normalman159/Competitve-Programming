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
const ll LimN = 1e5+5;
string s;
unordered_map<ll,ll> mp;
void solve(){
    cin >> s;
    ll n = s.size();
    s = ' ' + s;
    ll p[LimN];
    p[0] = 0;
    for (ll i=1; i<=n;i++){
        p[i] = p[i-1] + s[i] - '0';
    }
    for (ll i=1;i<=n;i++){
        p[i]%=3;
    }
    ll res= 0;
    ll k = p[n];
    p[n+1] = 0x3f;
    ll d = 1;
    for (ll i=1;i<=n+1;i++){
        // for (ll j=i; j<=n;j++){
        //     if ((k - (p[j] - p[i-1])) % 3 == 0 && j - i+1 < n){
        //         res++;
        //     }
        // }
        if (p[i] == p[i-1]){
            if (s[i] == '0' && s[i-1] == '0') continue;
            d++;
            cout << p[i] << " " << p[i-1] << ln;
        } 
        else {
            res+=d*(d-1)/2;
            d=1;
        }
    }
    cout << res;
}
int main()
{
    // freopen("CAU3.INP", "r",stdin);
    // freopen("CAU3.OUT","w",stdout);
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
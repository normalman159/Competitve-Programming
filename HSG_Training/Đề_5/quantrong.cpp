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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

//O(n)

ll n, a[MXN], p[MXN],s[MXN];
void solve(){
    p[0] =0;
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        p[i] = p[i-1] + a[i];
    }
    fill(s+1,s+1003,-1);
    for (ll i=n;i>=1;i--){
        if (s[a[i]] == -1){
            s[a[i]] = i;
        }
    }
    ll res = -1;
    for (ll i=1;i<=n;i++){
        res = max(res,p[s[a[i]]] - p[i-1]);
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
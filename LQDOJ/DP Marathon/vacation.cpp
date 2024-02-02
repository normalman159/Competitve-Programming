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

const ll LimN = 1e5 + 5;

ll n,a[LimN],b[LimN], c[LimN];
    ll f[LimN][3];

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
    memset(f,0,sizeof(f));
    f[0][0] = f[0][1] = f[0][2] = 0;
    for (ll i=1;i<=n;i++){
        f[i][0] += a[i];
        f[i][0]+=max(f[i-1][1], f[i-1][2]);
        f[i][1] +=b[i];
        f[i][1]+=max(f[i-1][0],f[i-1][2]);
        f[i][2] +=c[i];
        f[i][2] +=max(f[i-1][0],f[i-1][1]);
    }
    cout << max({f[n][0], f[n][1],f[n][2]});
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
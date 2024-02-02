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

const ll LimN = 1e2 + 5, LimW = 1e5+5;
ll n,w, a[LimN], b[LimN];
ll f[LimN][LimW];
void solve(){
    cin >> n >> w;
    for (ll i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    f[1][0] = 0;
    for (ll i=1;i<=n;i++){
        for (ll j=0 ;j <=w;j++){
            if (j - a[i] >=0){
                //chon
                f[i][j] = max(f[i][j], f[i-1][j-a[i]] + b[i]);
                //ko chon
                f[i][j] = max(f[i-1][j], f[i][j]);
            }
            else f[i][j] = f[i-1][j];
        }
    }
    cout << f[n][w];
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
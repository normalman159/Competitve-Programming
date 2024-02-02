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

const ll LimN = 1e2+5, LimV = 1e5+5;
ll n,W,w[LimN], v[LimN],sum=0;

void solve(){
    cin >> n >> W;
    for (ll i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    } 
    ll f[LimV];
    fill(f,f+LimV,INF);
    f[0] = 0;
    f[v[1]] =w[1];
    for (ll k=2;k<=n;k++){
        for (ll i =LimV-1;i>=0;i--){
            if (f[i-v[k]] + w[k] <=W && i-v[k]>=0 && f[i-v[k]]!=INF){
                f[i] = min(f[i], f[i-v[k]] + w[k]);
            }
        }
    } 
    for(ll i=LimV-1;i>=0;i--){
        if (f[i]!=INF){
            cout << i;
            break;
        }
    }
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
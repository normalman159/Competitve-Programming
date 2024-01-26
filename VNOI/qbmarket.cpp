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
const ll MAX_S = 1e5+3;
ll s,n, c[MXN], m[MXN];
__int128_t dp[2][MAX_S];
void print(__int128_t x){
    if (x < 0){
        putchar('-');
        x=-x;
    }
    if (x > 9){
        print(x/10);
    }
    putchar(x%10 + '0');
}
void solve(){
    cin >> s >> n;
    for (ll i=1;i<=n;i++){
        cin >> c[i] >> m[i];
    } 
    dp[0][s] = 1;
    for (ll i=1;i<=n;i++){
        for (ll j = 0;j<=s;j++){
            dp[i&1][j] = 0;
            for (ll t = 0;t<=m[i];t++){
                dp[i&1][j - t*c[i]] += dp[(i-1)&1][j];
            }
        }
    }
    print(dp[n&1][0]);
}
ll f[MXN],d[MXN];
void solve1(){
    cin >> s >> n;
    for (ll i=1;i<=n;i++){
        cin >> c[i] >> m[i];
    } 
    f[0] = 1;
    for (ll i=1;i<=n;i++){
        for (ll v = c[i];v<=s;v++){
            d[v] = f[v-c[i]];
            d[v] += d[v-c[i]];
            if (v >= c[i]*(m[i]+1)){
                d[v]-=f[v-c[i]*(m[i]+1)];
            }
        }
        for (ll j=0;j<=s;j++){
            f[j]+=d[j];
            d[j] = 0;
        }
    }
    print(f[s]);
}

int main()
{
    fast_cin();
    solve1();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
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
const ll LimN = 1e2 + 5;
ll n,k,a[LimN], cnt2[LimN], cnt5[LimN];
    ll f[LimN][LimN][LimN*60];
ll tach(ll x, ll k){
    ll res = 0;
    while (x%k==0){
        res++;
        x/=k;
    }
    return res;
}

void solve(){
    cin >> n >> k;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for (ll i=1;i<=n;i++){
        cnt2[i] = tach(a[i],2);
        cnt5[i] = tach(a[i],5);
    }

    memset(f,-1,sizeof(f));
    f[0][0][0] = 0;
    for (ll i=0;i<n;i++){
        for (ll j = 0; j<=min(k,i);j++){
            for (ll f2 = 0;f2<=j*60;f2++){
                if (f[i][j][f2]!=-1){
                    //chon
                    f[i+1][j+1][f2+cnt2[i+1]] = max(f[i+1][j+1][f2+cnt2[i+1]],f[i][j][f2] + cnt5[i+1]);
                    f[i+1][j][f2] = max(f[i+1][j][f2], f[i][j][f2]);
                }
            }
        }
    }
    ll res = 0;
    for (ll f2 = 0;f2<=k*60;f2++){
        if (f[n][k][f2] != -1){
            res = max(res, min(f2, f[n][k][f2]));
        }
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
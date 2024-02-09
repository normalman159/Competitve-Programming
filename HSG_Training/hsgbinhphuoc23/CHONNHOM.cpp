#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e3 + 5;
ll n,k, cnt[LimN], f[LimN][LimN],factor[LimN];
string a[LimN];


ll tohop(ll x){
    return x*(x-1)/2;
}

void fac(ll n){
    factor[0] = 1;
    for (ll i=1;i<=n;i++){
        factor[i] = (factor[i-1]*i)%MOD;
    }
}

ll powMod(ll a, ll b){
    ll res = 1;
    while (b){
        if (b&1) {
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b/=2;
    }
    return res;
}

ll inversion(ll k){
    return powMod(k, MOD-2) %MOD;
}

ll count_C(ll n, ll k){
    return factor[n] * inversion(factor[k] * factor[n-k] %MOD) %MOD;
}

void solve(){
    cin >> n >> k;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        sort(a[i].begin(),a[i].end());
    }
    sort(a+1,a+1+n);
    // for (ll i=1;i<=n;i++){
    //     cout << a[i] << ln;
    // }
    ll u = 1, count=1;
    a[n+1] = ' ';
    for (ll i=2;i<=n+1;i++){
        if (a[i]!=a[i-1]){
            cnt[u] = count;
            u++;
            count = 1;
        }
        else count++;
    }
    // for (ll i=1;i<=u;i++){
    //     cout << cnt[i] << " ";
    // }
    // cout << u << ln;
    fac(LimN);
    f[0][0] = 1;
    for (ll i=0;i<u;i++){
        for (ll j=0;j<=k;j++){
            for (ll t = 0; t<= cnt[i+1];t++){
                ll coef = count_C(cnt[i+1], t);
                ll z = tohop(t);
                f[i+1][j + z]+=f[i][j] * coef;
                f[i+1][j+z]%=MOD;
            }
        }
    }
    cout << f[u][k];
}
int main()
{
    // freopen("CHONNHOM.INP","r",stdin);
    // freopen("CHONNHOM.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}
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
const ll LimN = 4*1e4+5;
ll n;
bool nt[LimN];

void sang(ll n){
    memset(nt,true,sizeof(nt));
    nt[0] = nt[1] = false;
    for (ll i=2;i*i<=n;i++){
        if (nt[i]){
            for (ll j=i*i;j<=n;j+=i) nt[j] = false;
        }
    }
}

ll powMod(ll a, ll b){
    ll res = 1;
    while (b){
        if (b&1){
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b/=2;
    }
    return res;
}

ll tach(ll n, ll x){
    ll res = 0;
    for (ll i=x;i<=n;i*=x){
        res+=n/i;
    }
    return res;
}

void solve(){
    cin >> n;
    sang(n);
    ll res = 1;
    for (ll i=1;i<=n;i++){
        if (nt[i]== true){
            ll k = tach(n,i);
            if (k&1) k--;
            res = (res* powMod(i,k))%MOD;
        }
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}
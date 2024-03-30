#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

//Modulo Calculation
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (long long)x * y % MOD;
}

const ll LimN = 1e4+5, LimK = 1e2 +5;
ll f[LimK][LimN], a[LimN];
ll best[LimK][LimN];
void sub1(ll n, ll k){
    vector<ll> prefix_1(n+1,-INF) , prefix_2(n+1,-INF);
    prefix_1[1] = a[1];
//    for(ll i = 1;i<= n; i++){
//        ll max_so_far  = -INF, max_here=0;
//        for (ll j = 1; j<=i;j++){
//            max_here += a[j];
//            max_so_far = max(max_so_far, max_here);
//            if (max_here < 0) max_here = 0;
//        }
//        cout << "i = " << i << " " << max_so_far << ln;
//    }
//    cout << ln;
    ll max_here = 0;
    for (ll i=1;i<=n;i++){
        max_here+=a[i];
        if (i==1){
            prefix_1[i] = a[i];
            continue;
        }
        prefix_1[i] = max(prefix_1[i-1], max_here);
//        cout << "i = " << i << " " << prefix_1[i]  << " " << max_here<< ln;
        max_here = max(max_here,0LL);
    }
    max_here = 0;
    for (ll i = n; i>=1;i--){
        max_here += a[i];
        if (i==n){
            prefix_2[i] = a[i]; continue;
        }
        prefix_2[i] = max(prefix_2[i+1], max_here);
        max_here = max(max_here, 0LL);
    }
    ll res = -INF;
    for (ll i=1;i<n;i++){
        ll z = prefix_1[i] + prefix_2[i+1];
        res = max(res,z);
    }
    cout << res;
}

void sub23(ll n, ll k){
    for(ll i=0;i<= LimN - 5;i++){
        for (ll j = 0;j <= LimK - 5; j++) f[j][i] = -INF, best[j][i];
    }
    f[0][0] = 0;

    for (ll j = 1; j<=k;j++){

    }
}

void solve(){
    ll k,n; cin >> n >> k;
    forsn(i,1,n) cin >> a[i];
    if (k==2){
        sub1(n,k);
    }
    else{
        sub23(n,k);
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}

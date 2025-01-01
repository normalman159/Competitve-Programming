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
const ll LimN = 1e6 +5;
ll t,n, arr[LimN];
void solve(){
    cin >> t;
    while (t--){
        cin >> n;
        ll sum =0;
        double cnt = 0;
        for (ll i=1;i<=n;i++) {cin >> arr[i]; sum+=arr[i];}
        sort(arr+1, arr+1+n);
        double avarage = (double)sum/(2*n);
        cnt = lower_bound(arr+1,arr+1+n,avarage) - arr - 1;
        if (cnt > n/2) {cout << 0 << ln;continue;}
        if (n < 3) {cout << -1 << ln; continue;}
        cout << max(0LL,arr[n/2 + 1]*n*2 - sum + 1) << ln;
    }
}
/*
3
6 2 2
*/

int main()
{
    fast_cin();
    solve();
    return 0;
}



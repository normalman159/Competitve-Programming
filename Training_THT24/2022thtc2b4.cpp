/*
Link: https://lqdoj.edu.vn/problem/2022thtc2b4
*/

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

const ll LimN = 1e5+5;
ll v[LimN];
void sub12(ll n, ll k){
    ll ans = 0;
    priority_queue<ll> pq;
    for (ll i=1;i<=n;i++){
        pq.push(v[i]);
    }
    while (k--){
        if (pq.top()==0) break;
        ans+=pq.top();
        ll z = pq.top();
        pq.pop();
        pq.push(z-1);
    }
    cout << ans;
}

void solve(){
    ll n,k; cin >> n >> k;
    for (ll i=1;i<=n;i++) cin >> v[i];
    if (n<=1e5){
        sub12(n,k);
    }
}


int main()
{
//    freopen("DOVUIVE.INP","r",stdin);
//    freopen("DOVUIVE.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}


//https://codeforces.com/problemset/problem/2010/C2

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9 + 2277;
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

const ll LimN = 1e6 + 5;
ll pre[LimN], arr[LimN], POW[LimN], hashT[LimN];

const ll Base = 71;

ll getHash(ll i, ll j){
    return (hashT[j] - hashT[i-1] * POW[j-i+1] + MOD * MOD ) %MOD;
}

void solve(){
    string t; cin >> t;
    ll n = t.size();
    t = ' ' + t;
    POW[0] = 1;
    for (ll i=1;i<=n; i++){
        POW[i] = (POW[i-1] * Base) % MOD;
    }
    for (ll i=1;i<=n;i++){
        hashT[i] = (hashT[i-1] * Base + t[i] - 'a' + 1) % MOD;
    }
    for (ll i=2;i<=n;i++){
        if (!(i<=n-i+1)) break;
        if (getHash(1,n-i+1) == getHash(i,n)){
            cout << "YES" << ln;
            for (ll j = i; j<=n;j++){cout << t[j];}
            return;
        }
    }
    cout << "NO";
}


int main()
{
    fast_cin();
    solve();
    return 0;
}




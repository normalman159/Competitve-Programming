//https://oj.vnoi.info/problem/substr

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+3;
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

ll Base = 31;
const ll LimN = 1e6 + 5;
ll POW[LimN], hashA[LimN];
ll getHash (ll i, ll j){
    return (hashA[j] - hashA[i-1] * POW[j-i+1] + MOD * MOD) % MOD;
}
void solve(){
    string a,b; cin >> a >> b;
    ll SIZE_A = SZ(a), SIZE_B = SZ(b);
    a =  ' ' + a, b = ' ' + b;
    POW[0] = 1;
    for (ll i=1;i<=SIZE_A;i++){
        POW[i] = (POW[i-1] * Base) % MOD;
    }
    for (ll i=1;i<=SIZE_A;i++){
        hashA[i] = (hashA[i-1] * Base + a[i] - 'a' + 1) % MOD;
    }
    ll hashB = 0;
    for (ll i=1; i<= SIZE_B;i++){
        hashB = (hashB * Base + b[i] - 'a' + 1) % MOD;
    }
    for (ll i=1;i<=SIZE_A - SIZE_B + 1;i++){
        if (hashB == getHash(i,i+SIZE_B -1)){
            cout << i << " ";
        }
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}



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

const ll Base = 311, LimN = 5e4 + 5;
ll POW[LimN], HashS[LimN], HashT[LimN], SIZE_S;

ll getHashS(ll i, ll j){
    return (HashS[j] - HashS[i-1] * POW[j-i+1] + MOD * MOD) % MOD;
}

ll getHashT(ll i, ll j){
    return (HashT[SIZE_S - i + 1] - HashT[SIZE_S - j] * POW[j-i+1] + MOD * MOD) % MOD;
}

bool ch_dis(ll length){
    for (ll i=1;i<= SIZE_S - length + 1; i++){
        if (getHashS(i,i+length-1) == getHashT(i,i+length-1)) return true;
    }
    return false;
}

void solve(){
    cin >> SIZE_S;
    string s,t; cin >> s;
    t = s; reverse(ALL(t));
    s = ' ' + s;
    t = ' ' + t;
    POW[0] = 1;
    for (ll i=1;i<=SIZE_S;i++) POW[i] = (POW[i-1] * Base) % MOD;
    for (ll i=1;i<=SIZE_S;i++){
        HashS[i] = (HashS[i-1] * Base + s[i] - 'a' + 1) % MOD;
        HashT[i] = (HashT[i-1] * Base + t[i] - 'a' + 1) % MOD;
    }
    ll ans = 1;
    bool ktra = false;
    ll i = 1, j = SIZE_S/2  ;
    while (i <= j){
        ktra = false;
        ll m = (i+j)>>1;
        if (ch_dis(2*m)){
            ans = max(ans,2*m);
            i = m+1;
            ktra = true;
        }
        if (ch_dis(2*m+1)){
            ans = max(ans,2*m+1);
            i = m+1;
            ktra = true;
        }
        if (!ktra){
            j = m-1;
        }
    }
    cout << ans;
}


int main()
{
    fast_cin();
    solve();
    return 0;
}



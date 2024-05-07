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

void solve(){
    string s; getline(cin,s);
    map<char,ll> mp;
    for (auto x : s){
        mp[x]++;
    }
    ll cnt = 0;
    if (mp['C'] == 0) cnt++;
    if (mp['h'] < 3) cnt+= 3 - mp['h'];
    if (mp['u'] < 2) cnt+= 2- mp['u'];
    if (mp['c'] == 0) cnt++;
    if (mp[' '] < 4) cnt+=4 - mp[' '];
    if (mp['m'] ==0) cnt++;
    if (mp['n'] < 3) cnt += 3 - mp['n'];
    if (mp['g'] == 0) cnt++;
    if (mp['s'] == 0) cnt++;
    if (mp['i'] == 0) cnt++;
    if (mp['a'] == 0) cnt++;
    if (mp['t'] == 0) cnt++;
    if (mp['L'] == 0) cnt++;
    if (mp['Q'] == 0) cnt++;
    if (mp['D'] == 0) cnt++;
    if (mp['O'] == 0) cnt++;
    if (mp['J'] == 0) cnt++;
    cout << cnt;
}


int main()
{
    fast_cin();
    solve();
    return 0;
}


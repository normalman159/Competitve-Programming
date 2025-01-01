//https://codeforces.com/problemset/problem/2010/C1

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
    string t; cin >> t;
    ll n = t.size();
    t = ' ' + t;
    for (ll i=2;i<=n;i++){
        if (!(i<= n-i+1)) break;
        string s1 = t.substr(1,n-i+1), s2 = t.substr(i,n);
        if (s1 == s2){
            cout << "YES" << ln << s1;
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



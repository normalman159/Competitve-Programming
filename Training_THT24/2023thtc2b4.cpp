/*
Link: https://lqdoj.edu.vn/problem/2023thtc2b4
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

string cal(string s){
    string res;
    for (auto x : s){
        ll tmp = x - '0';
        tmp++;
        string tmp1 = to_string(tmp);
        res+=tmp1;
    }
    return res;
}

void sub12(ll t){
    vector<pair<ll,ll>> v(100);
    for (ll i=1;i<=t;i++) cin >> v[i].first >> v[i].second;
    for (ll z = 1 ; z<=t;z++){
        ll n = v[z].first, k = v[z].second;
        string res = to_string(n);
        while (k--){
            res = cal(res);
        }
        ll p = res.size() %MOD;
        cout << p << ln;
    }
}

void solve(){
    ll t; cin >> t;
    if (t<=100){
        sub12(t);
    }
}


int main()
{
//    freopen("CONG.INP","r",stdin);
//    freopen("CONG.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}


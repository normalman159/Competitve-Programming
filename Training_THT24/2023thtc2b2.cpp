/*
Link: https://lqdoj.edu.vn/problem/2023thtc2b2
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

ll docao(ll x){
    ll res = 0;
    while (x!=0){
        res+=x%10;
        x/=10;
    }
    return res;
}

void solve(){
    ll n,h; cin >> n >> h;
    vector<bool> nt(n+2,true);
    nt[0] = nt[1] = false;
    for (ll i=2;i*i<=n;i++){
        if (nt[i]==true){
            for(ll j = i*i;j<=n;j+=i) nt[j] = false;
        }
    }
    ll res = 0;
    for (ll i=1;i<=n;i++){
        if (nt[i]== true && docao(i)==h){
            res++;
            cout << i << ln;
        }
    }
    cout << res;
}


int main()
{
//    freopen("DOCAONT.INP","r",stdin);
//    freopen("DOCAONT.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}


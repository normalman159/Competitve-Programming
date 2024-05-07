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
    string s, a;cin >> s >> a;
    ll cnt_R = 0, cnt_L = 0;
    for (auto x : a){
        if (x=='R') cnt_R++;
        else cnt_L++;
    }
    if (cnt_L==cnt_R){
        cout << s; return;
    }
    if (cnt_L > cnt_R){
        ll del = cnt_L - cnt_R;
        ll n = s.size();
        vector<char> v(n+10);
        s = ' ' + s;
        for (ll i=1;i<=n;i++){
            ll z = (i+del)%n;
            if (z==0){
                v[n] = s[i];
            }
            else v[(i + del) % n] = s[i];
        }
        for (ll i=1;i<=n;i++) cout << v[i];
        return;
    }
    else{
        ll del = cnt_R - cnt_L;
        ll n = s.size();
        vector<char> v(n+10);
        s = ' ' + s;
        for (ll i=n;i>=1;i--){
            ll z = (i+del)%n;
            if (z==0){
                v[n] = s[i];
            }
            else v[(i + del) % n] = s[i];
        }
        for (ll i=1;i<=n;i++) cout << v[i];
        return;
    }
}


int main()
{
//    freopen("ROBOT.INP","r",stdin);
//    freopen("ROBOT.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}


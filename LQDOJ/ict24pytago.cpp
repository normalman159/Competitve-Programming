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

void sub12(ll n){
    vector<pair<ll,ll>> a(n+1);
    forsn(i,1,n){
        ll x; cin >> x;
        a[i] = {x,i};
    }
    map<ll,ll> mp;
    sort(a.begin(),a.end());
    forsn(i,1,n){
        a[i] = {a[i].first*a[i].first , a[i].second};
        mp[a[i].first]++;
    }
    ll res = 0;
    for (ll i = 1; i <= n-2;i++){
        for (ll j = i+1;j<=n-1;j++){
            ll z = a[i].first + a[j].first;
            res+=mp[z];
        }
    }
    cout << res;
}

const ll LimN = 5e6+5;

void sub3(ll n){
    vector<ll> a(n+1), dic(LimN,0), cnt(LimN,0);
    forsn(i,1,n){
        cin >> a[i];
    }
    forsn(i,1,n){
        cnt[a[i] * a[i]]++;
        dic[a[i]]++;
    }
    ll res  =0;
    for (ll a=1;a<=1000;a++){
        for (ll b = a+1;b<=1000;b++){
//            DEBUG(a*a + b*b);
            res += dic[a] * dic[b] * cnt[a*a + b*b];
        }
    }
    cout << res;
}

void solve(){
    ll n; cin >> n;
    if (n <= 5e3) sub12(n);
    else{
            sub3(n);
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}

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

void sub1(ll n, vector<ll> &v){
    vector<ll> prefix_1(n+2,0), prefix_2(n+2,0);
    for (ll i=1;i<=n;i++){
        prefix_1[i] = prefix_1[i-1];
        prefix_2[i]= prefix_2[i-1];
        if (v[i]%2==0){
            prefix_1[i] = prefix_1[i-1]+ 1;
        }
        else prefix_2[i] = prefix_2[i-1] + 1;
    }
    ll res = 0;
    for (ll i=1;i<=n;i++){
        for (ll j=i; j<=n;j++){
//            DEBUG(j), DEBUG(i), DEBUG(prefix_2[j] - prefix_2[i-1]), DEBUG(prefix_1[j] - prefix_1[i-1]);
            if (prefix_2[j] - prefix_2[i-1] >= (prefix_1[j] - prefix_1[i-1])* (prefix_1[j] - prefix_1[i-1]) + 7){
//                DEBUG(j), DEBUG(i);
                res++;
            }
        }
    }
    cout << res;

}

void sub2(ll n, vector<ll> &v){
    vector<ll> prefix_1(n+2,0), prefix_2(n+1,0), chan;
    for (ll i=1;i<=n;i++){
        prefix_1[i] = prefix_1[i-1];
        prefix_2[i]= prefix_2[i-1];
        if (v[i]%2==0){
            prefix_1[i] = prefix_1[i-1]+ 1;
            chan.pb(i);
        }
        else prefix_2[i] = prefix_2[i-1] + 1;
    }
    chan.pb(n+1);
    ll res = 0;
    ll sz = chan.size();
    ll st = 0;
    for (ll i=1;i<=n;i++){
        while (st < sz-1 && chan[st] < i) st++;
        if (chan[st]>i) res+=max(0LL, chan[st] - i - 7+1);
        ll j =0, f = st;
        while (j*j<n && f < sz-1){
            ll nd = max(0LL, ((j+1)*(j+1)+7) - (prefix_2[chan[f]] - prefix_2[i-1] ));
            ll nx = chan[f] + nd;
            if (nx < chan[f+1]) res+=(chan[f+1] - nx);
            j++, f++;
        }
    }
    cout << res;
}

void solve(){
    ll n; cin >> n;
    vector<ll> v(n+1);
    forsn(i,1,n) cin >> v[i];
    if (n <= 5e3){
        sub1(n,v);
    }
    else{
        sub2(n,v);
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}

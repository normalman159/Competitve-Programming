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

const ll LimN = 1e6 + 6;
ll arr[LimN], n, pref_even[LimN], pref_odd[LimN], cnt_odd[LimN], cnt_even[LimN];

void sub1(){
    ll ans = 0;
    for (ll i=1;i<=n;i++){
        for (ll j = i;j<=n;j++){
            if ((arr[i] + arr[j]) & 1) ans= (ans + (arr[i] % MOD+ arr[j] % MOD)) %MOD;
        }
    }
    cout << ans;
}

void sub2(){
    for (ll i=1;i<=n;i++){
        pref_even[i] = pref_even[i-1];
        pref_odd[i] = pref_odd[i-1];
        cnt_odd[i] = cnt_odd[i-1];
        cnt_even[i] = cnt_even[i-1];
        if (arr[i] & 1) pref_odd[i] += arr[i], cnt_odd[i]++;
        else pref_even[i]+=arr[i], cnt_even[i]++;
    }
    ll ans = 0;
    for (ll i=1;i<=n-1;i++){
        if (arr[i] & 1){
//            DEBUG(i),DEBUG(arr[i]), DEBUG(pref_even[n] - pref_even[i]);
            if (pref_even[n] - pref_even[i]==0) continue;
            ans = (ans + add(arr[i]*(cnt_even[n] - cnt_even[i]), pref_even[n] - pref_even[i])) % MOD;
        }
        else{
//            DEBUG(i),DEBUG(arr[i]), DEBUG(pref_odd[n] - pref_odd[i]);
            if (pref_odd[n] - pref_odd[i]==0) continue;
            ans= (ans +  add(arr[i] * (cnt_odd[n]-cnt_odd[i]), pref_odd[n] - pref_odd[i])) % MOD;
        }
    }
    cout << ans;
}

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> arr[i];
    if (n<=1e3) sub1();
    else sub2();
}


int main()
{
    fast_cin();
    solve();
    return 0;
}



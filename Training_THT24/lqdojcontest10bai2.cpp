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

const ll LimN = 3e6+5;

ll cnt_sum(ll x){
    ll cnt= 0;
    while (x != 0){
        cnt+=x%10;
        x/=10;
    }
    return cnt;
}

void solve(){
    ll l, r; cin >> l >> r;
    vector<bool> check_nt(LimN,true);
    check_nt[0] = check_nt[1] = false;
    for (ll i=2;i*i<=LimN -5;i++){
        if (check_nt[i]==true){
            for (ll j = i*i;j<=LimN-5;j+=i) check_nt[j] = false;
        }
    }
    ll cnt = 0;
    for (ll i = l; i<=r;i++){
        if (check_nt[i] && cnt_sum(i)%5==0) cnt++;
    }
    cout << cnt;
}


int main()
{
    fast_cin();
    solve();
    return 0;
}


#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e6+5;
ll n, a[LimN];

ll cnt(ll x){
    ll res = 0;
    for (ll i=1;i*i<=x;i++){
        if (x%i==0){
            res+=i;
            if (i != x/i){
                res+=x/i;
            }
        }
    }
    return res;
}

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for (ll i=1;i<=n;i++){
        ll k = cnt(a[i]);
        k-=a[i];
        if (a[i] < k) cout << 1 << ln;
        else cout << 0 << ln;
    }
    // cout << cnt(18);

}
int main()
{
    fast_cin();
    solve();
    return 0;
}
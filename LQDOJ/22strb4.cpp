#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ln "\n"
const ll INF = 1e18;
const ll LimN = 1e5+5;

ll n,a[LimN];
map<ll,ll> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    ll res = 0;

    for (ll i=1;i<=n;i++){
        ll x = a[i];
        if (a[i-1] < x && x > a[i+1]){
            mp[x+1]--;
            ll m = max(a[i-1],a[i+1]);
            mp[m+1]++;
        }
    }
    ll cnt = 0;
    for (auto it = mp.begin(); it!=mp.end();++it){
        cnt += it->second;
        res = max(res,cnt);
    }
    cout << res;
    return 0;
}

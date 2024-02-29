#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;
#define ln "\n"
const ll LimN = 20 +5;


ll n,x;
pair<ll,ll> p[LimN];

ll sum(ll T){ //ok
    ll res = 0;
    for (ll i=1;i<=n;i++){
        if (!(p[i].first<=T)) return res;
        ll x = (T - p[i].first)/p[i].second;
        res+= 1 + x;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    for (ll i=1;i<=n;i++){ //ok
        cin >> p[i].first >> p[i].second;
    }
    sort(p+1,p+1+n);
    ll l =1 , r = 1e18;
    ll res = INF;
    while (l<=r){
        ll mid = (l+r)/2;
        ll s = sum(mid);
        if (s >= x){
            res = min(res,mid);
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << res;
    return 0;
}

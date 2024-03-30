#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define ln "\n"
const ll INF = 1e18;

void fast_cin(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
const ll LimN = 1e5+5;
ll n,a[LimN], k;
map<ll,ll> mp;

int main(){
    fast_cin();
    cin >> n >> k;
    for (ll i=1;i<=n;i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (ll i=1;i<n;i++){
        ll ap = a[i];
        ll au = 2*k - ap;
        if (mp[au] != 0 ){
            cout << i << " " << mp[au];
            return 0;
        }
    }
    cout << 0 << " " << 0;
    return 0;
}

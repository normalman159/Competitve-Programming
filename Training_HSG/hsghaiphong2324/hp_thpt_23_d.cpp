#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ln " \n"
const ll INF = 1e18;

const ll LimN = 1e6+5;
ll t,a[LimN];
map<ll,bool> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--){
        ll n,k; cin >> n >> k;
        bool flag = false;
        for (ll i=1;i<=n;i++){
            cin >> a[i];
            mp[a[i]] = true;
        }
        if (k %2==0){
            cout << 0;
            continue;
        }
        for (ll i=1;i<=n;i++){
            ll u = a[i];
            ll v = k-u;
            if (mp[v] == true){
                cout << 1;
                flag = true;
                break;
            }
        }
        if (flag == 0){
            cout << 0;
        }
    }
    return 0;
}

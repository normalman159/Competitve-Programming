#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e6+5;
ll n,a[LimN];
ll p[LimN], p2[LimN];
ll cnt[2*LimN];
ll *cnt1 = cnt + LimN;
void solve(){
    cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    for (ll i=1;i<=n;i++){
        if (s[i]=='a') a[i] = 1;
        else a[i] = 0;
    }
    for (ll i=1;i<=n;i++){
        if (a[i]==1){
            p[i] = p[i-1] + 1;
        }
        else p[i] = p[i-1] - 1;
    }
    ll res = 0;
    for (ll i=0;i<=n;i++){
        res+=cnt1[p[i]];
        cnt1[p[i]]++;
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}

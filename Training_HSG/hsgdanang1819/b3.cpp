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
const ll Lim = 1e6+5;
string s;
ll k, sum= 0, res  = 0, a[Lim],cnt[Lim];
void solve(){
    cin >> k;
    cin >> s;
    ll n = s.size();
    s = ' ' + s;
    ll res = 0;
    for (ll i=1;i<=n;i++){
        if (s[i]=='1'){
            cnt[i] = cnt[i-1]+1;   
        }
        else cnt[i] = cnt[i-1];
    }
    a[k] = 1;
    for (ll i=1;i<=n;i++){
        res+=a[cnt[i]];
        a[cnt[i] + k]++;
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}
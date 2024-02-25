#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
string s;
const ll Lim = 1e6+5;
ll cnt1[Lim],cnt2[Lim];
void solve(){
    cin >> s;
    ll n = s.size();
    s = ' ' + s;
    for (ll i=1;i<=n;i++){
        cnt1[i] = cnt1[i-1];
        cnt2[i] = cnt2[i-1];
        if (s[i]=='a' || s[i]=='e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'  ){
            cnt1[i]++;
        }
        else{
            cnt2[i]++;
        }
    }
    ll res = 0;
    for (ll i=1;i<=n;i++){
        if (s[i]=='a' || s[i]=='e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'  ){
            res+=cnt2[n] - cnt2[i];
        }
        else res+=cnt1[n] - cnt1[i];
    }
    cout << res;
}
int main()
{
    // freopen("CAU4.INP","r",stdin);
    // freopen("CAU4.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}
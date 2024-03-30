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
ll n, p[LimN],cnt[100];
void solve(){
    cin >> n;
    string s = to_string(n);
    ll n1 = s.size();
    s = ' ' +s;
    ll res = 0,res1=0;
    ll d=0;
    for (ll i=1;i<=n1;i++){
        d+= s[i] - '0';
    }
    d = d%3;
    for (ll i=1;i<=n1;i++){
        p[i] = p[i-1] + s[i] - '0';
    }
    for (ll i = 0;i<=n1;i++){
        ll j = p[i]%3 - d;
        if (j < 0){
            j+=3;
        }
        res+=cnt[j];
        cnt[p[i]%3]++;
    }
    // for (ll i=1;i<=n1;i++){
    //     for (ll j=i; j<=n1;j++){
    //         if ((p[n1] - (p[j] - p[i-1])) % 3 == 0 && j - i+1 < n1){
    //             res1++;
    //         }
    //     }
    // }
    // if (d==0) res1++;
    if (d > 0) res--;
    cout << res;
}
int main()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    // freopen("CAU3.INP","r",stdin);
    // freopen("CAU3.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}
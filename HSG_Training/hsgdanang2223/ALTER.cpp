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
ll f[Lim][2], t[30][2];
string a;
void solve(){
    cin >> a;
    ll n = a.size();
    a = ' ' + a;
    //Loai 0 -> tang a[j] > a[i]
    //Loai 1 -> giam a[j] < a[i]
    // 0 1 0 1 0 1 0 1 0 1
    ll ans= 0;
    for (ll i=1;i<=n;i++){
        f[i][0] += 1;
        ll k = a[i] - 'A';
        for (ll j = k+1;j<26;j++){
            f[i][0]+=t[j][1];
            f[i][0]%=MOD;
        }
        for (ll j = 0; j<k;j++){
            f[i][1]+=t[j][0];
            f[i][1]%=MOD;
        }

        t[k][1]+=f[i][1];
        t[k][0]+=f[i][0];
        t[k][1]%=MOD;
        t[k][0]%=MOD;
        ans+= f[i][0] + f[i][1];
        ans%=MOD;
    }
    cout << ans;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}
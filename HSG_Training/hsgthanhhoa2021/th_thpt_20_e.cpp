#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 5e3+5;
const ll MAX = 2e8+5;
ll n, a[LimN], demtg = 0;
unordered_map<ll,ll>mp;
ll tu =0, nhon = 0, vuong =0;
// ll cnt[MAX];
ll demvuong(){
    ll res = 0;
    for (ll i=1;i<=n-1;i++){
        for (ll j=i+1;j<=n;j++){
            ll z = a[i]*a[i] + a[j]*a[j];
            mp[z]++;
        }
    }
    for (ll i =1;i<=n;i++){
        res+=mp[a[i]*a[i]];
    }
    return res;
}
//x^2 + y^2 > z^2
ll demnhon(){
    ll res=0;
    for (ll i=1;i<=n-2;i++){
        for (ll j = i+1, k = i+2, f= i+2;j<=n-1;j++){
            while (k <= n && a[i]+ a[j] >a[k]) k++;
            demtg+=k-j-1;
            while (f<=n && a[i]*a[i] + a[j]*a[j] > a[f]*a[f]) f++;
            if (f <= k+1){
                res+=f-j-1;
            }
        }
    }
    return res;
}

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a+1,a+1+n);
    nhon = demnhon();
    vuong = demvuong();
    cout << nhon << " " << vuong << " " << demtg - nhon - vuong;
}
int main()
{
    // freopen("CAU5.INP","r",stdin);
    // freopen("CAU5.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}
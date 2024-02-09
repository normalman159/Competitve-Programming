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
const ll LimN = 1e6+5;
ll n,a[LimN];
bool nt[LimN];
vector<ll> v,v1;
void sangnt(ll n){
    memset(nt,true,sizeof(nt));
    nt[0] = nt[1] = 0;
    for (ll i=2;i*i<=n;i++){
        if (nt[i]){
            for (ll j=i*i;j<=n;j+=i){
                nt[j] = 0;
            }
        }
    }
    for (ll i=1;i<=n;i++){
        if (nt[i]){
            v.push_back(i);
        }
    }
}

ll powMod(ll a,ll b){
    ll res =1;
    while (b){
        if (b&1) res = (res*a);
        a = a*a;
        b/=2;
    }
    return res;
}

void solve(){
    cin >> n;
    ll hi = -1;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        hi = max(hi,a[i]);
    }
    sangnt(1e6);
    for (auto u : v){
        v1.push_back(powMod(u,2));
    }
    //O(n * log(a[i]))
    for (ll i=1;i<=n;i++){
        // ll k = sqrt(a[i]);
        // if (k*k != a[i]){
        //     cout <<"NO" << ln;
        //     continue;
        // }
        // if (nt[k] == true && k*k == a[i]){
        //     cout << "YES" << ln;
        // }
        if (find(v1.begin(), v1.end(), a[i]) != v1.end()){
            cout << "YES" << ln;
        }
        else cout << "NO" << ln;
    }

}
int main()
{
    fast_cin();
    solve();
    return 0;
}
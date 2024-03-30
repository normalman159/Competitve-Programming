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
}



void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sangnt(1e6);

    for (ll i=1;i<=n;i++){
        ll k = sqrt(a[i]);
        if (nt[k] == true && k*k == a[i]){
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
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

const ll LimN = 2*1e5+5;

pair<ll,ll> a[LimN]; 
ll n,m;
void solve(){
    cin >> n >> m;
    for (ll i=1;i<=n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a+1,a+1+n);

    while (m--){
        ll i,j,k; cin >> i >> j >> k;
        for (ll f=1;f<=n;f++){
            if (a[f].second <= j && a[f].second>=i){
                k--;
            }
            if (k==0){
                cout << a[f].first << ln;
                break;
            }
        }
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}
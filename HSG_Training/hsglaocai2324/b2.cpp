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

ll powMod(ll a, ll b, ll Mod){
    ll res =1;
    while (b){
        if (b&1) res = (res*a)%Mod;
        a = (a*a)%Mod;
        b/=2;
    }
    return res;
}

bool fermat_checK(ll x, ll k = 50){
    if (x < 4){
        return x == 2 || x==3;
    }
    if (x!=2 && x %2==0){
        return false;
    }
    for (ll i=1;i<=k;i++){
        ll a = 2 + rand() % (x-3);
        if (powMod(a,x-1,x) != 1){
            return false;
        }
    }
    return true;
}
string s;
vector<ll> v;
void solve(){
    cin >> s;
    ll n = s.size();
    s = ' ' + s;
    ll tmp = 0;
    for (ll i=1;i<=n;i++){
        if (s[i]>='0' && s[i] <='9'){
            if (s[i] == '0' && (s[i-1] == '0' || !(s[i-1]>='0' && s[i-1] <='9'))){
                continue;
            }
            tmp = tmp*10 + s[i] - '0';
        }
        else{
            if (tmp == 0) continue;
            v.push_back(tmp);
            tmp = 0;
        }
    }
    if (tmp !=0){
        v.push_back(tmp);
    }
    // for (auto x : v){
    //     cout << x << " ";
    // }
    ll res = -INF;
    for (auto x :v){
        if (fermat_checK(x) == true){
            res = max(res,x);
        }
    }
    if (res == -INF){
        cout << 0;
    }
    else cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}
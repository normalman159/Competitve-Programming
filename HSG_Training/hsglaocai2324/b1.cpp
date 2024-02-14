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
ll t;

ll powMod(ll a,ll b, ll Mod){
    ll res = 1;
    while (b){
        if (b&1){
            res = (res*a)%Mod;
        }
        a  = (a*a)%Mod;
        b/=2;
    }
    return res;
}

bool fermat_checK(ll x, ll k = 50){
    if (x < 4){
        return x == 2 || x==3;
    }
    if (x!=2 && x&2==0){
        return false;
    }
    for (ll i=1;i<=k;i++){
        ll a = 2 + rand() %(x-3);
        if (powMod(a,x-1,x)!=1){
            return false;
        }
    }
    return true;
}

const ll LimN = 1e6+5;
bool nt[LimN];
vector<ll> prime;
void sangnt(){
    memset(nt,true,sizeof(nt));
    nt[0] = nt[1] = 0;
    for (ll i=2;i*i<=1e6;i++){
        if (nt[i]){
            for (ll j=i*i;j<=1e6;j+=i){
                nt[j] = 0;
            }
        }
        
    }
    for (ll i=2;i<=1e6;i++){
        if (nt[i]) prime.push_back(i);
    }
}

void count(ll x){
    sangnt();
    ll res =1;
    for (auto p : prime){
        if (p*p*p>x){
            break;
        }
        ll cnt= 0;
        while (x %p==0){
            cnt++;
            x/=p;
        }
        res*=(cnt+1);
    }
    if (fermat_checK(x)){
        res*=2;
    }
    else{
        ll square = sqrt(x);
        if (square*square == x && fermat_checK(square)== true){
            res*=3;
        }
        else if (x!=1){
            res*=4;
        }
    }
    if (res &1){
        cout << "LE"<<ln;
    }
    else cout << "CHAN" << ln;
}

void solve(){
    cin >> t;
    while (t--){
        ll n; cin >> n;
        count(n);
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
const ll LimN = 4e6+5;
ll n,a,b;


void sub1(){
    ll res = 0;
    auto checknt = [&](ll x){
        if(x==1) return false;
        for (ll i=2;i*i<=x;i++){
            if (x%i==0) return false;
        }
        return true;
    };
    for (ll i=1;i*i<=n;i++){
        if (checknt(i)) res++;
    }
    cout << res;
}

void sub2(){
    vector<ll> cnt_uoc(LimN, 0);
    vector<ll> f(LimN, 0);
    vector<bool> sangnt(LimN,true);

    sangnt[1] = sangnt[0] = false;
    for(ll i=2;i*i<=n;i++){ //ok
        if (sangnt[i]){
            for (ll j=i*i;j<=n;j+=i) sangnt[j] = false;
        }
    }

    for (ll i=1;i<=n;i++){
        for (ll j = i;j<=n;j+=i){
            cnt_uoc[j]++;
            if (sangnt[i]){
                if (f[j]==0) f[j]=1;
                f[j]*=i;
            }
        }
    }
    ll res = 0;
    forsn(i,1,n){ //ok
        if (i*f[i]<=n && cnt_uoc[i]>=a && cnt_uoc[i]<=b) res++;
    }
    cout << res;
}

void sub3(){
    vector<bool> sangnt(LimN, true);
    sangnt[1] = sangnt[0] = false;
    ll n1= sqrt(n);
    for (ll i=2;i*i<=n1;i++){
        if (sangnt[i]){
            for (ll j = i*i;j<=n1;j+=i) sangnt[j] = false;
        }
    }
    vector<ll> nt;
    forsn(i,2,n1){
        if (sangnt[i]) nt.pb(i);
    }
    auto powMod = [&](ll a, ll b){
        ll res = 1;
        for (ll i=1;i<=b;i++){
            res*=a;
            if (res > n) return res;
        }
        return res;
    };
    auto solve_k1 = [&](ll k){
        //p1^(k1+1) <=n
        ll res = -1;
        ll l = 0, r = nt.size() - 1;
        while (l<=r){
            ll mid = (l+r)/2;
            if (powMod(nt[mid], k+1) <=n){
                res = mid;
                l=mid+1;
            }
            else r = mid-1;
        }
        return res+1;
    };
    auto solve_k2 = [&](ll k1,ll k2){
        //p1^(k1+1) * p2^(k2+1) <=n
        // p1 < p2
        ll ans = 0;
        for (auto p2 : nt){
            ll z = powMod(p2,k2+1);
            ll z1 = n/z;
            ll l = 0, r=nt.size()-1;
            ll res  =-1;
            while (l <=r){
                ll mid = (l+r)/2;
                if (powMod(nt[mid],k1+1) <=z1 && nt[mid] < p2){
                    res = mid;
                    l = mid+1;
                }
                else r = mid-1;
            }
            ans+=(res+1);
        }  
        return ans;
    };
    ll ans = 0;
    forsn(i,a,b){
        if (i==2){
            ans+=solve_k1(1);
        }
        if (i==3){
            ans+=solve_k1(2);
        }
        if (i==4){
            ans+=solve_k1(3);
            ans+=solve_k2(1,1);
        }
        if (i==5){
            ans+=solve_k1(4);
        }
        if (i==6){
            ans+=solve_k1(5);
            ans+=solve_k2(1,2);
            ans+=solve_k2(2,1);
        }
    }
    cout << ans;
}

void solve(){
    cin >> n >> a >> b;
    if (a == 2 && b== 2 && n <= 1e6){
        sub1();
    }
    else if (n<=4*1e6){
        sub2();
    }
    else if (a>=2 && b<=6){
        sub3();
    }
}

int main()
{
    fast_cin();
    solve();
    return 0;
}

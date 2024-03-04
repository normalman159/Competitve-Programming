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

ll n,a,b;

pair<ll,ll> tichuocnt_2(ll x){
    ll res = 1, number=1;
    for (ll i=2;i*i<=x;i++){
        if (x%i==0){
            res*=1LL*i;
            ll cnt =0;
            do{
                cnt++;
                x/=i;
            }
            while (x%i==0);
            // while (x%i==0){
            //     cnt++;
            //     x/=i;
            // } 
            number *= (cnt+1);
        }
    }
    if (x>1){
        res*=x*1LL;
        number*=2;
    }
    return {res,number};
}

void sub2(){
    ll res = 0;
    for (ll i=1;i<=n;i++){
        pair<ll,ll> tmp = tichuocnt_2(i);
        if (i * tmp.fi <=n && (a<= tmp.se && tmp.se <=b)){
            DEBUG(i);
            res++;
        } 
    }
    cout << res;
}

void solve(){
    cin >> n >> a >> b;
    // if (a == 2 && b== 2 && n<=1e6){
    //     sub2();
    // }
    // else if (a==2 && b==4 && n<=4*1e6){
    //     sub2();
    // }
    // else if ((3<=a && a<=6) && (3<=b && b<=6) && n <=1e12){
    //     sub2();
    // }
    // else{
    //     sub2();
    // }
    sub2();
}

int main()
{
    fast_cin();
    solve();
    return 0;
}

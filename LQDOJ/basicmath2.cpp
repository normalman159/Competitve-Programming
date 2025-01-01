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
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

//Modulo Calculation
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (long long)x * y % MOD;
}

const ll LimN = 1e5;
ll n;
ll arr[25];
bool ch = 1;

void sub1(){
    auto init = [](ll n){
        for (ll i=1;i<=n;i++) arr[i] = i;
    };
    auto next = [](ll k){
        ll i = k;
        while (i > 0 && arr[i]==n-k+i) i--;
        if (i==0) ch=0;
        else{
            arr[i]++;
            for (ll j = i+1; j<=k;j++) arr[j] = arr[j-1] + 1;
        }
    };
    for (ll k = 1;k<=n;k++){
        ll count_num = 0;
        for (ll cnt = 1; cnt <= n; cnt++){
            ch = 1;
            init(n);
            while (ch){
                bool ktra = true;
                ll brr[25]; copy(arr, arr+25, brr);
                sort(brr+1, brr+cnt+1);
                for (ll i=1;i<cnt;i++){
                    if (!(abs(brr[i]-brr[i+1]) >= k)) {ktra = 0; break;}
                }
                if (ktra) {
                    count_num++;
                    count_num%=MOD;
                }

                next(cnt);
            }

        }
        cout << count_num % MOD << ln;
    }
}
vector<ll> factor(305,1);
void sub2(){

    for (ll i=1;i<=302;i++){
        factor[i] = factor[i-1] %MOD * i;
        factor[i] %= MOD;
        cout << factor[i] << ln;
    }
    auto cof = [](ll k, ll n){
        return factor[n]/(factor[k]*factor[n-k]);
    };
    ll count_num = 0;
    for (ll k=1;k<=n;k++){
        count_num = 0;
        for (ll cnt = 1; cnt<=n;cnt++){
//            if (cnt == 1) {count_num+=n; count_num%=MOD; continue;}
            for (ll i = 1; i<=n;i++){
                if (!((n-k-i+1) >0 )|| cnt > n-k-i+1) continue;
                count_num+=cof(cnt,n-k-i+1);
                count_num%=MOD;
            }
        }

        cout << count_num % MOD << ln;
    }
}

/*
3
k =1 => {1} {2} {3} {1 2} {2 3} {1 3} {1 2 3}
k =2 => {1} {2} {3} {1 3}
k = 3 => {1} {2} {3}
*/

void solve(){
    cin >> n;
    if (n <= 20){
        sub2(); //O(
    }
    else if (n <=300){

    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}



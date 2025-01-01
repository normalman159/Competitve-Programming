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
ll n; string s;
void sub1(){
    auto ch = [](string x){
        for (ll i=0; i<x.size()-1;i++) {
            if (x[i] == x[i+1]) return false;
        } return true;
    };
    sort(ALL(s));
    vector<string> ans;
    do{
        if (ch(s)) ans.pb(s);
    }
    while (next_permutation(ALL(s)));
    if (!ans.empty()) cout << ans[0];
    else cout << -1;
}

void sub2(){
    cout << ln;
    sort(ALL(s));
    ll cnt_a = 0, cnt_b = 0, cnt_c = 0;
    for (auto x : s){
        if (x == 'a') cnt_a++;
        else if (x == 'b') cnt_b++;
        else cnt_c++;
    }
    DEBUG(cnt_a), DEBUG(cnt_b), DEBUG(cnt_c);
    DEBUG(s);
}

/*
11
acbaaabcccc => abcacacacbc
*/

void solve(){
    cin >> n;
    cin >> s;
    sub1();
    sub2();
//    bool flag_sub2 = true;
//    for (auto x : s) {
//        if (x!= 'a' && x!= 'b' && x != 'c') {
//            flag_sub2 ^=1; break;
//        }
//    }
//    if (n<=10){
//        sub1();
//    }
//    else if (flag_sub2){
//        sub2();
//    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}


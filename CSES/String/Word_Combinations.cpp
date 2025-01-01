#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;
#define forn(i, e) for (ll i = 1; i <= e; i++)
#define forsn(i, s, e) for (ll i = s; i <= e; i++)
#define rforn(i, s) for (ll i = s; i >= 1; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout << #x << " = " << x << ln
#define pb push_back
#define fi first
#define se second
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

// Modulo Calculation
ll add(ll x, ll y)
{
    return (x + y) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)x * y % MOD;
}

struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(ll i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

TrieNode *root = new TrieNode();

void insertString(string s){
    TrieNode *curr = root;
    ll n = SZ(s);
    for(ll i=0;i<n;i++){
        ll idx = s[i] - 'a';
        if(curr->child[idx] == NULL){
            curr->child[idx] = new TrieNode();
        }
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

void solve(){
    string s; cin >> s;
    ll n; cin >> n;
    for (ll i=0; i< n;i++){
        string p; cin >> p;
        insertString(p);
    }
    ll len = SZ(s);
    vector<ll> dp(len+1,0);
    dp[len] = 1;
    for (ll i = len - 1; i>=0;i--){
        TrieNode *t = root;
        for (ll j = i; j<len; j++){
            if (t->child[s[j] - 'a'] == NULL){
                break;
            }
            t = t->child[s[j] - 'a'];
            if (t->isEnd){
                dp[i] = dp[i] % MOD + dp[j+1] % MOD;
                dp[i]%=MOD; 
            }
        }
    }
    cout << dp[0];
}   
    
int main()
{
    fast_cin();
    solve();
    return 0;
}

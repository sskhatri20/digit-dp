#include <bits/stdc++.h>
#define pb push_back
#define PQ priority_queue<int>
#define ff first
#define all(v) v.begin(), v.end()
#define ss second
#define pii pair<int,int>
#define v1d vector<int>
#define vpi vector<pair<int,int>>
#define int long long
#define nl '\n'
#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++) 
using namespace std;

template<typename T> void read(vector<T> &a){ for(T &e: a) cin>>e; } 
template<typename T> void print(vector<T> &a){ for(T &e: a) cout<<e<<" "; } 

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

void IOS(){ios::sync_with_stdio(false); cout.precision(10); cout << fixed;}

#define INF (1LL<<60)
int i, j, k;

int dp[20][4][2];

// pos in the number, num of non zero digits, bool func to not go out of bounds

int sol(const string & s, int pos, int cnt, int tight, int len){
	
	if(cnt>3)return 0;
	if(pos==len){
		return cnt<=3;
	}
	if(dp[pos][cnt][tight]!=-1)return dp[pos][cnt][tight];

	int limit = tight?(s[pos]-'0'):9;
	int ans = 0;
	for(int i=0; i<=limit; i++){
		ans += sol(s, pos+1, cnt+(i!=0), tight&(i==limit), len);
	}
	return dp[pos][cnt][tight] = ans;

}

void test_cases(){
	int n, m;
	cin>>n>>m;
	string s = to_string(m);
	memset(dp, -1, sizeof dp);
	int x = s.length();
	int z = n-1;
	string t = to_string(z);
	int y = t.length();
	
	int pe = sol(s, 0 ,0, 1, x);
	memset(dp, -1, sizeof dp);
	int me = sol(t, 0, 0, 1, y);
	cout<<pe-me<<nl;
}

int32_t main(){
	IOS();
	int nr=1;
      cin>>nr;
	
      for(int i=1; i<=nr; i++){
            test_cases();
      }
	
	return 0;
}






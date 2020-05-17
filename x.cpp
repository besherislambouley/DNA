/*
 * we iterate through the string from the left to the right , and try building the prefix of our answer
 * when we face a 'N' we try replace it with { 'A' , 'C' , 'G' , 'T' } 
 * we check if a letter should be here by finding how many strings with form k starting with prefix Pre + crntletter let this value num 
 * if num < R then this is not the right letter other wise we add it to the prefix and complete
 * we find num by an dp [M][last][K] , we are at the pos'th letter , the (pos-1)'th letter is last , the prefix is form-K 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
ll n , k , goal ;
string s ;
map < char , ll > val12 ; map < ll , char > val21 ;
char c[] = { 'A' , 'C' , 'G' , 'T' } ; 
ll dp [50009][4][19] ;
ll bt ( ll pos , ll last , ll crnt ) {
	if ( crnt > k ) return 0ll ;
	if ( pos == n ) return 1ll ;
	ll &ret = dp [pos][last][crnt] ;
	if ( ret != -1 ) return ret ;
	ret = 0 ; 
	for ( ll i = 0 ; i < 4 ; i ++ ) {
		if ( s [pos] != 'N' && i != val12 [ s[pos] ] ) C ;
		ll ncrnt = crnt + ( i < last ) ;
		ret += bt ( pos + 1 , i , ncrnt ) ;
	}
	return ret ;
}
int main () {
	mem ( dp , -1 ) ;
	for ( ll i = 0 ; i < 4 ; i ++ ) {
		val12 [ c [i] ] = i ;
		val21 [ i ] = c [i] ;
	}
	cin >> n >> k >> goal >> s ;
	ll Crnt = 1 , last = 0 ;
	for ( ll i = 0 ; i < n ; i ++ ) {
		if ( s[i] == 'N' ) {
			for ( int j = 0 ; j < 4 ; j ++ ) {
				ll ncrnt =  Crnt + ( j < last ) ;
				ll num = bt ( i + 1 , j , ncrnt ) ;
				if ( num >= goal ) {
					s [i] = val21 [ j ] ; 
					break ; 
				}
				goal -= num ;
			}
		}
		if ( val12 [ s[i] ] < last ) Crnt ++ ;
		last = val12 [ s[i] ] ;
	}
	cout << s << endl ; 
}

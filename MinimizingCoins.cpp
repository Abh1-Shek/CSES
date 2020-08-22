#include<bits/stdc++.h>
using namespace std ;
 
 
/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
/************************************************************/
 
vector<int> dp( (int)(1e6) + 1, INT_MAX ) ;
// dp[i] is minimum number of moves to make i
 
int solve( vector<int> &c, int &n, int &x ){
	// sort( all(c), []( int a, int b ) { return a > b ; } ) ;
	dp[0] = 0 ;
	for( int i = 1 ; i <= x ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			if( i - c[j] >= 0 )
			dp[i] = min( dp[i], dp[ i - c[j] ] + 1 ) ;
		}
	}
	return ( dp[x] == INT_MAX ? - 1 : dp[x] ) ;
}
 
 
signed main() {
	int n, x ; cin >> n >> x ;
	vector<int> c(n) ;
	for( let &ci of c ) cin >> ci ;
	cout << solve( c, n, x ) ;
} 

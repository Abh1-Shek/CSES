#include<bits/stdc++.h>
using namespace std ;


// START
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
// END

signed main() {
	int n ; cin >> n ;
	vector<int> dp( n + 1, INT_MAX ) ;
	dp[0] = 0 ;
	int x ;
	for( int i = 1 ; i <= n ; i++ ){
		x = i ;
		while( x > 0 ){
			dp[ i ] = min( dp[ i ], dp[ i - (x % 10 ) ] + 1 ) ;
			x /= 10 ;
		}
	}
	cout << dp[n] << endl ;
}
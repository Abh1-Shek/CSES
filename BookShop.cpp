#include<bits/stdc++.h>
using namespace std ;
 
// START
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
const int mod = (int)1e9 + 7 ;
// END
 
 
signed main() {
	int n, x ; cin >> n >> x ;
	vector<int> price(n), pages(n) ;
	for(int &p of price) cin >> p ;
	for(int &p of pages) cin >> p ;
	vector<int> dp( x + 1, 0 ) ;
	// dp[i] is most number of pages for max cost of i
	for( int j = 0 ; j < n ; j++ ){
  // we can use one item only once that's why running second
  // loop backwards
		for( int i = x ; i >= 0 ; i-- ){
			if( i - price[j] >= 0 )
			dp[i] = max( dp[i], dp[i-price[j]] + pages[j] ) ;
		}
	}
	cout << dp[ x ] << endl ;	
}

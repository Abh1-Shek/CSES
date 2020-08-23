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
    int n ; cin >> n ;
	vector<int> a(n) ;
	for(int &i of a) cin >> i ;
	vector<bool> isPos( (int)(1e5) + 1, false ) ;
	isPos[0] = true ;
	for( int i = 0 ; i < n ; i++ ){
		for( int j = (int)1e5 ; j >= 0 ; j-- ){
			if( isPos[j] ){
				isPos[j + a[i]] = true ;
			}
		}
	}
	int cnt = count( all(isPos), true ) - 1 ;
	cout << cnt << "\n" ;
	for( int i = 1 ; i <= (int)1e5 ; i++ ){
		if( isPos[i] ){
			cout << i << " " ;
		}
	}
	return 0 ;
}

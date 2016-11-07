#include <iostream>
#include <vector>

using namespace std;

template <int N, typename T, typename Functor>
void operator | (T (&array)[N], Functor functor) {
	int i = 0;
	while (i < N) {
		functor( array[i] );
		++i;
	}
}

template <typename T, typename Functor>
void operator | (vector<T> v, Functor functor) {
	for( auto it = v.begin(); it != v.end(); ++it ) {	// Or use: for( T item : v ) { ... } 
		functor( *it );
	}
}

int main() {

	int tab[10] =  { 1, 2, 3, 2, 3, 4, 6, 0, 1, 8 };
	vector<int> v;

	tab | []( auto x ) { cout << x*x << endl; };
	tab | [&v]( auto x ) { v.push_back( x ); };
	v | []( auto x ) { cout << x*x << endl; };

	return 0;
}
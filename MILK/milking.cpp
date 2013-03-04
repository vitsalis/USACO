/*
ID: vitsali1
LANG: C++
TASK: milk
*/
#include <cstdio>
#include <algorithm>

using namespace std;

struct farm {
    int val;
    int gal;
};

bool operator <( farm a, farm b ) {
    return a.val < b.val;
}

int main() {
    freopen( "milk.in", "r", stdin );
    freopen( "milk.out", "w", stdout );
    int N, ned;
    scanf( "%d%d", &ned, &N );
    int i;
    farm array[ N ];
    for ( i = 0; i < N; ++i ) {
        scanf( "%d%d", &array[ i ].val, &array[ i ].gal );
    }
    sort( array, array + N );
    int sum = 0;
    for ( i = 0; i < N; ++i ) {
        if ( array[ i ].gal >= ned ) {
           sum = sum + ned * array[ i ].val;
           break;
        }
        else {
            sum += array[ i ].val * array[ i ].gal; 
            ned -= array[ i ].gal;
        }
    }
    printf( "%d\n", sum );
    return 0;
}

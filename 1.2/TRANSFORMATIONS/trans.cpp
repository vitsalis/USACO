/*
ID: vitsali1
LANG: C++
TASK: transform
*/
#include <cstdio>

using namespace std;

int main() {
	freopen( "transform.in", "r", stdin );
	freopen( "transform.out", "w", stdout );
    int N;
    scanf( "%d", &N );
    char origin[ N ][ N ], save[ N ][ N ];
    char trans[ N ][ N ];
    int i, j;
    scanf( "%*c" );
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            scanf( "%c", origin[ i ] + j );
            save[ i ][ j ] = origin[ i ][ j ];
        }
        scanf( "%*c" );
    }
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            scanf( "%c", trans[ i ] + j );
        }
        scanf( "%*c" );
    }
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( origin[ i ][ j ] != trans[ j ][ N - ( 1 + i ) ] ) {
                break;
            }
        }
        if ( j != N ) {
            break;
        }
        if ( i + 1 == N ) {
            printf( "1\n" );
            return 0;
        }
    }
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( origin[ i ][ j ] != trans[ N - ( 1 + i ) ][ N - ( 1 + j ) ] ) {
                break;
            }
        }
        if ( j != N ) {
            break;
        }
        if ( i + 1 == N ) {
            printf( "2\n" );
            return 0;
        }
    }

    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( origin[ i ][ j ] != trans[ N - ( 1 + j ) ][ i ] ) {
                break;
            }
        }
        if ( j != N ) {
            break;
        }
        if ( i + 1 == N ) {
            printf( "3\n" );
            return 0;
        }
    }
    bool visited[ N ][ N ];
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            visited[ i ][ j ] = false;
        }
    }
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( !visited[ i ][ j ] ) {
                char temp = origin[ i ][ j ];
                origin[ i ][ j ] = origin[ i ][ N - ( j + 1 ) ];
                origin[ i ][ N - ( j + 1 ) ] = temp;
                visited[ i ][ N - ( j +1 ) ] = true;
            }
        }
    }

    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( origin[ i ][ j ] != trans[ i ][ j ] ) {
                break;
            }
        }
        if ( j != N ) {
            break;
        }
        if ( i + 1 == N ) {
            printf( "4\n" );
            return 0;
        }
    }
    
	for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( origin[ i ][ j ] != trans[ j ][ N - ( 1 + i ) ] ) {
                break;
            }
        }
        if ( j != N ) {
            break;
        }
        if ( i + 1 == N ) {
            printf( "5\n" );
            return 0;
        }
    }
    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( origin[ i ][ j ] != trans[ N - ( 1 + i ) ][ N - ( 1 + j ) ] ) {
                break;
            }
        }
        if ( j != N ) {
            break;
        }
        if ( i + 1 == N ) {
            printf( "5\n" );
            return 0;
        }
    }

    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( origin[ i ][ j ] != trans[ N - ( 1 + j ) ][ i ] ) {
                break;
            }
        }
        if ( j != N ) {
            break;
        }
        if ( i + 1 == N ) {
            printf( "5\n" );
            return 0;
        }
    }
	for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            if ( save[ i ][ j ] != trans[ i ][ j ] ) {
                break;
            }
        }
        if ( j != N ) {
            break;
        }
        if ( i + 1 == N ) {
            printf( "6\n" );
            return 0;
        }
    }
	printf( "7\n" );

    return 0;
}

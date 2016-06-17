#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

unsigned int find_missing( unsigned int *el, unsigned int numberOfElements ) {
    unsigned int highestElement = 0;
    unsigned int arraySize = numberOfElements - 1;
    unsigned int *tmp_p = el;
    unsigned int done = 0;
    unsigned int stillOrdering = 0;
    unsigned int missingValue = numberOfElements;
    unsigned int correctLocation = 0;
    unsigned int keep = 0;

    while ( !done ) {
        stillOrdering = 0;
        for ( unsigned int i = 0; i < arraySize; i++ ) {
            if ( el[ i ] != i + 1 && el[ i ] != 0 ) {
                if ( el[ i ] == numberOfElements ) {
                    // store highest elemnent separately to avoid creating
                    // new array of correct length
                    highestElement = el[ i ];
                    el[ i ] = 0;
                } else {
                    // move element value to correct cell
                    correctLocation = el[ i ] - 1;
                    keep = el[ i ];
                    el[ i ] = el[ correctLocation ];
                    el[ correctLocation ] = keep;
                }
                // set bit to indicate that ordering is still happening
                stillOrdering = 1;
            }
            if ( el[ i ] == 0 ) {
                // we can track the 0, which will end up in missing spot
                missingValue = i + 1;
            }
        }
        done = !stillOrdering;
    }
    return( missingValue );
}

int main() {
    unsigned int missing_value;

    // missing 7
    unsigned int elements1[ 9 ] = { 3, 8, 2, 5, 6, 9, 10, 4, 1 };
    missing_value = find_missing( elements1, 10 );
    printf( "Trial 1:  the missing value is %d\n", missing_value );

    // missing 10
    unsigned int elements2[ 9 ] = { 4, 9, 6, 2, 1, 3, 7, 5, 8 };
    missing_value = find_missing( elements2, 10 );
    printf( "Trial 2:  the missing value is %d\n", missing_value );
    
    // missing 9
    unsigned int elements3[ 9 ] = { 7, 10, 8, 6, 5, 4, 3, 2, 1 };
    missing_value = find_missing( elements3, 10 );
    printf( "Trial 3:  the missing value is %d\n", missing_value );
    
    // missing 14
    unsigned int elements4[ 17 ] = { 8, 9, 1, 2, 6, 5, 11, 13, 17, 18, 16, 10, 4, 7, 12, 15, 3 };
    missing_value = find_missing( elements4, 18 );
    printf( "Trial 4:  the missing value is %d\n", missing_value );
    
    // missing 8
    unsigned int elements5[ 19 ] = { 11, 16, 4, 1, 3, 2, 15, 19, 10, 9, 13, 6, 5, 7, 18, 20, 17, 14, 12 };
    missing_value = find_missing( elements5, 20 );
    printf( "Trial 5:  the missing value is %d\n", missing_value );
   
    // missing 4
    unsigned int elements6[ 3 ] = { 3, 2, 1 };
    missing_value = find_missing( elements6, 4 );
    printf( "Trial 6:  the missing value is %d\n", missing_value );

    return( 0 );
}

#include "cpsc3120hw01pt02.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <time.h>

using namespace std;

int main( int argc , char* argv[] ){
  int num;
  vector<int> numbers;

 
  while( cin >> num ){
    numbers.push_back( num );
    
  }

  cout << "Before: ";
  for( int i = 0; i < numbers.size(); i++ ){
    cout << numbers[i] << " ";
  }
  cout << endl;
  
  try{
    clock_t start = clock();
    removeEvens( numbers );
    clock_t end = clock();
    cout << "After : ";
    for( int i = 0; i < numbers.size(); i++ ){
      cout << numbers[i] << " ";
    }
    cout << endl;
    fprintf( stderr , "removeEvens took %.7f seconds.\n" , 1.0 * ( end - start ) / CLOCKS_PER_SEC );
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}

#include <iostream>
#include <vector>
#include <cstdio>
#include "cpsc3120hw04pt01.h"
using namespace std;

int main(int argc , char* argv[]){
  int n;
  cin >> n;
  vector<double> row(n,0);
  vector< vector<double> > matrix(n,row);
  int r , c , v;
  while( cin >> r >> c >> v ){
    int R = (int)(r);
    int C = (int)(c);
    matrix[R-1][C-1] = v * 1.0;
    matrix[C-1][R-1] = v * 1.0;
  }

   // Printing the adjacency matrix (commented out)
  /*
  for (int r = 0; r < matrix.size(); r++) {
    for (int c = 0; c < matrix.size(); c++) {
      fprintf(stderr, "%+ 4.1f ", matrix[r][c]);
    }
    cerr << endl;
  }
  */
  fprintf( stdout , "The value of the maximum spanning tree is % 4.1f\n" , maximumST( matrix ) );
  return 0;
}

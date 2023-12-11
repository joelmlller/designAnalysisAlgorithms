#include "cpsc3120hw03pt02.h"
#include <vector>
#include <climits>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int matrixChainMultiplication( vector< vector<int> > matrices ){
  int n = matrices.size();
  vector<int> row(n,0);
  vector< vector<int> > table(n,row);

  for( int i = 0; i < n - 1; i++ ){
    table[i][i+1] = matrices[i][0] * matrices[i][1] * matrices[i+1][1];
  }

  for( int d = 0; d < n - 1; d++ ){
    for( int p = 0; p < n - 1 - d; p++ ){
      int r = p;
      int c = d + p + 1;
      int best = INT_MAX;
      int bestI = -1;
      //cerr << "FILLING " << r << "," << c << endl;
      for( int o = 1; o <= d + 1; o++ ){
	//cerr << "CHECKING " << r << "," << c-(d+2)+o << " and " << r+o << "," << c << " (" << table[r][c-(d+2)+o] << " and " << table[r+o][c] << ")" << endl;
	if( table[r][c-(d+2)+o] + table[r+o][c] + matrices[r][0] * matrices[c-(d+2)+o][1] * matrices[c][1] < best ){
	  best = table[r][c-(d+2)+o] + table[r+o][c] + matrices[r][0] * matrices[c-(d+2)+o][1] * matrices[c][1];
	  bestI = c-(d+2)+o;
	}
      }
      //cerr << "ADDING " << matrices[r][0]  << " * " << matrices[bestI][1] << " * " << matrices[c][1] << endl;
      table[r][c] = best;
    }
  }

  for( int r = 0; r < table.size(); r++ ){
    for( int c = 0; c < table.size(); c++ ){
      fprintf( stderr , "% 5d " , table[r][c] );
    }
    cerr << endl;
  }
  
  return table[0][matrices.size()-1];
}

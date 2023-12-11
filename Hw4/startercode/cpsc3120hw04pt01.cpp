#include <vector>
#include <iostream>
#include <limits> // for numeric_limits
#include "cpsc3120hw04pt01.h"

using namespace std;

double maximumST(vector<vector<double> > adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    double maxSTWeight = 0.0;
    
    vector<double> mrx(n, numeric_limits<double>::min());
    vector<bool> trd(n, false);

    
    // Start with the first vertex
    mrx[0] = 0.0;

    // Iterate all vertices to build the MST
    for (int ct = 0; ct < n - 1; ++ct) {
        // Find the vertex with the maximum mrx value
        int num = -1;
        for (int i = 0; i < n; ++i) {
            if (!trd[i] && (num == -1 || mrx[i] > mrx[num])) {
                num = i;
            }
        }
        // Include the found vertex in the MST
        trd[num] = true;

        // Update mrx values of adjacent vertices
        for (int v = 0; v < n; ++v) {
            if (adjacencyMatrix[num][v] != -1 && !trd[v] && adjacencyMatrix[num][v] > mrx[v]) {
                mrx[v] = adjacencyMatrix[num][v];
            }
        }
    }

    // Calculate the sum of mrx values
    for (int i = 0; i < n; ++i) {
        maxSTWeight += mrx[i];
    }

    return maxSTWeight;
}

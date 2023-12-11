#include <vector>
#include <iostream>
#include "cpsc3120hw04pt02.h"

using namespace std;

// compute the shortest paths matrix after the kth stage of Floyd's algorithm
vector<vector<double> > allPairsSP(vector<vector<double> > adjacencyMatrix, int k) {
    int num = adjacencyMatrix.size();

    // Iterate through all vertices as med vertices
    for (int med = 0; med < num; ++med) {
        // Iterate through all vertices as src vertices
        for (int src = 0; src < num; ++src) {
            // Iterate through all vertices as dest vertices
            for (int dest = 0; dest < num; ++dest) {
                // Update shortest path if a shorter path is found through the current med vertex
                if (adjacencyMatrix[src][med] != -1 && adjacencyMatrix[med][dest] != -1 && (adjacencyMatrix[src][dest] == -1 || adjacencyMatrix[src][dest] > adjacencyMatrix[src][med] + adjacencyMatrix[med][dest])) {adjacencyMatrix[src][dest] = adjacencyMatrix[src][med] + adjacencyMatrix[med][dest];}
            }
        }
        // Return the matrix after the kth stage
        if (med == k - 1) {
            return adjacencyMatrix;
        }
    }
    // Return the final matrix after n stage
    return adjacencyMatrix; 
}

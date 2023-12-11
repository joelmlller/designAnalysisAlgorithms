#include "cpsc3120hw03pt01.h"
#include <vector>
#include <algorithm> // for std::min

using namespace std;

int assemblyLine(vector<int> line1, vector<int> line2, vector<int> t12, vector<int> t21) {
   
    // Number of stations on each assembly line
    int lineOne = line1.size();

    // DP vectors for minimum time at each station on both assembly lines
    vector<int> vectorDP1(lineOne);  // Line 1
    vector<int> vectoDP2(lineOne);   // Line 2

    // Initialize first station times
    vectorDP1[0] = line1[0];
    vectoDP2[0] = line2[0];

    // Dynamic programming loop to calculate minimum time for each station
    for (int i = 1; i < lineOne; ++i) {
        // Min time to reach current station on assembly line 1
        vectorDP1[i] = min(vectorDP1[i - 1] + line1[i], vectoDP2[i - 1] + t21[i - 1] + line1[i]);
        
        // Min time to reach current station on assembly line 2
        vectoDP2[i] = min(vectoDP2[i - 1] + line2[i], vectorDP1[i - 1] + t12[i - 1] + line2[i]);
    }

    // Return min time to assemble an item, considering the last stations on both lines
    return min(vectorDP1[lineOne - 1], vectoDP2[lineOne - 1]);
}

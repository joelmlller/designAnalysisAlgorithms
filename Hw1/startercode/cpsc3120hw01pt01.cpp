#include "cpsc3120hw01pt01.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int maxSubSlow( const vector<int> &numbers ){
  // computes the maximum of every possible subarray summation, sj,k, of A separately.

    int m = 0; // the maximum found so far
    for (int j = 0; j < numbers.size(); j++) {
        for (int k = j; k < numbers.size(); k++) {
            int s = 0; // the next partial sum we are computing
            for (int i = j; i <= k; i++) {
                s += numbers[i];
            }
            if (s > m) {
                m = s;
            }
        }
    }
    return m;
}


int maxSubFaster( const vector<int> &numbers ){

    vector<int> prefix(numbers.size() + 1, 0); // the initial prefix sum

    // Calculate prefix sums
    for (int i = 1; i <= numbers.size(); i++) {
        prefix[i] = prefix[i - 1] + numbers[i - 1];
    }

    int m = 0; // the maximum found so far

    for (int j = 1; j <= numbers.size(); j++) {
        for (int k = j; k <= numbers.size(); k++) {
            int s = prefix[k] - prefix[j - 1];
            if (s > m) {
                m = s;
            }
        }
    }

    return m;
}


int maxSubFastest( const vector<int> &numbers ){
    int prefix = 0; // the initial prefix maximum
    int m = 0;    // the maximum found so far

    for (int t = 0; t < numbers.size(); t++) {
        prefix = max(0, prefix + numbers[t]);
        m = max(m, prefix);
    }

    return m;
}


#include "cpsc3120hw01pt02.h"
#include <vector>

using namespace std;

void removeEvens(vector<int> &numbers) {
    int curr = 0; 

    // iterate through vector
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 != 0) {
            // if number is odd place it at  current 
            numbers[curr] = numbers[i];
            curr++;
        }
    }

    // resize vector to  new size
    numbers.resize(curr);
}

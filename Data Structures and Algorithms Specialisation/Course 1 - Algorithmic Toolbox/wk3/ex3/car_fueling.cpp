#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int tank, vector<int> & stops) {
    // write your code here
    int numRefills = 0, currentRefill = 0, lastRefill = 0;
    //Find the largest possible fuelstop the car can travel
    while (currentRefill <= stops.size()-1)
    {
        lastRefill = currentRefill;//Stores the lastRefill in variable lastrefill
        while(currentRefill < stops.size() && (stops[currentRefill+1] - stops[lastRefill])<= tank)
        {//Last refill is not incremented. This gets the car to the furthest gas station possible.
            currentRefill = currentRefill + 1;
        }
        //If the furthest possible gas station is the one that the car is at currently, it is impossible to go the full distance.
        if (currentRefill == lastRefill) {return (-1);}
        
        // If the current refill is not the end of the road
        if (currentRefill < stops.size() - 1)
        {
            numRefills = numRefills + 1;
            
        }
    }
    return numRefills;
}

int main() {
    int d = 0;//distance
    cin >> d;
    int m = 0; //max_dist on a full tank
    cin >> m;
    int n = 0; //no.of stops
    cin >> n;
    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i) // input dist of stops with reference to a.
        cin >> stops.at(i);
    //Inserting the start points and end points into stops
    vector<int>::iterator it = stops.begin();
    stops.insert(stops.begin(),0);
    stops.push_back(d);
    cout << compute_min_refills(m, stops) << "\n";

    return 0;
}

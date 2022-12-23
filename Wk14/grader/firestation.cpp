#include <iostream>
#include <vector>

using namespace std;

int minimum_num_fire_stations(int n, int r, vector<int> garages) {
    // initialize the number of fire stations to 1
    int num_fire_stations = 1;

    // initialize the position of the previous garage to the position of the
    // first garage
    int prev_garage = garages[0];

    // iterate through the list of garages starting from the second garage
    for (int i = 1; i < n; i++) {
        int garage = garages[i];
        // if the distance between the current garage and the prev_garage is
        // greater than 2 * R
        if (garage - prev_garage > 2 * r) {
            // increment num_fire_stations by 1 and update prev_garage to the
            // position of the current garage
            num_fire_stations++;
            prev_garage = garage;
        }
    }

    // return the number of fire stations
    return num_fire_stations;
}

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> garages;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        garages.push_back(x);
    }
    cout << minimum_num_fire_stations(n, r, garages) << endl;
    return 0;
}

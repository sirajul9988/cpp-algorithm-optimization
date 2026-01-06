#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

int linearSearch(const vector<int>& v, int target) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) return i;
    }
    return -1;
}

int binarySearch(const vector<int>& v, int target) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == target) return mid;
        if (v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> data;
    for (int i = 0; i < 100000; i++) {
        data.push_back(i);
    }

    int target = 99999;

    auto start = high_resolution_clock::now();
    linearSearch(data, target);
    auto end = high_resolution_clock::now();
    cout << "Linear Search Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    binarySearch(data, target);
    end = high_resolution_clock::now();
    cout << "Binary Search Time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    return 0;
}

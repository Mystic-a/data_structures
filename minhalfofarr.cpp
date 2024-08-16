#include <bits/stdc++.h>
using namespace std;

int minSetSize(vector<int>& arr) {
    unordered_map<int, int> frequency;

    // Count the frequency of each element
    for (int num : arr) {
        frequency[num]++;
    }

    // Store the frequencies in a vector
    vector<int> freqValues;
    for (const auto& entry : frequency) {
        freqValues.push_back(entry.second);
    }

    // Sort frequencies in descending order
    sort(freqValues.begin(), freqValues.end(), greater<int>());

    int removedElements = 0;
    int totalRemoved = 0;
    int target = arr.size() / 2;

    // Remove elements until at least half of the array is removed
    for (int freq : freqValues) {
        totalRemoved += freq;
        removedElements++;
        if (totalRemoved >= target) {
            break;
        }
    }

    return removedElements;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Minimum number of unique elements to remove: " << minSetSize(arr) << endl;

    return 0;
}


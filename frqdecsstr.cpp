#include <bits/stdc++.h>
using namespace std;

// Returns count of character in the string
int countFrequency(string str, char ch)
{
    int count = 0;

    for (int i = 0; i < str.length(); i++)
        if (str[i] == ch)
            ++count;

    return count;
}

// Function to sort the string according to the frequency in decreasing order
void sortArr(string str)
{
    int n = str.length();

    // Vector to store the frequency of characters with respective character
    vector<pair<int, char>> vp;

    // Inserting frequency with respective character in the vector pair
    for (int i = 0; i < n; i++) {
        vp.push_back(make_pair(countFrequency(str, str[i]), str[i]));
    }

    // Sort the vector in decreasing order of frequency
    sort(vp.begin(), vp.end(), greater<pair<int, char>>());

    // Print the sorted vector content
    for (int i = 0; i < vp.size(); i++)
        cout << vp[i].second;
}

// Driver code
int main()
{
    string str;

    // Get the string from the user
    cout << "Enter a string: ";
    getline(cin, str);

    sortArr(str);

    return 0;
}

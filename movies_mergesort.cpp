#include <iostream>
#include <string>
using namespace std;

// Structure to represent a movie
struct Movie {
    string title;
    int releaseYear;
    double rating;
    string genre;
};

// Merge function for merge sort based on given field
void merge(Movie arr[], int l, int m, int r, string sortBy) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    Movie L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (sortBy == "releaseYear") {
            if (L[i].releaseYear <= R[j].releaseYear) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        } else if (sortBy == "rating") {
            if (L[i].rating >= R[j].rating) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        } else if (sortBy == "genre") {
            if (L[i].genre <= R[j].genre) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function for movies based on given field
void mergeSort(Movie arr[], int l, int r, string sortBy) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, sortBy);
    mergeSort(arr, m + 1, r, sortBy);
    merge(arr, l, m, r, sortBy);
}

// Function to print an array of movies
void printMovies(Movie arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Title: " << arr[i].title << ", Release Year: " << arr[i].releaseYear
             << ", Rating: " << arr[i].rating << ", Genre: " << arr[i].genre << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of movies: ";
    cin >> n;

    Movie* movies = new Movie[n];

    // Input movies details
    for (int i = 0; i < n; i++) {
        cout << "Enter title for movie " << i + 1 << ": ";
        cin >> movies[i].title;
        cout << "Enter release year for movie " << i + 1 << ": ";
        cin >> movies[i].releaseYear;
        cout << "Enter rating for movie " << i + 1 << ": ";
        cin >> movies[i].rating;
        cout << "Enter genre for movie " << i + 1 << ": ";
        cin >> movies[i].genre;
    }

    int choice;
    cout << "Sort movies by:\n";
    cout << "1. Release Year\n";
    cout << "2. Rating\n";
    cout << "3. Genre\n";
    cout << "Enter your choice: ";
    cin >> choice;

    string sortBy;
    switch (choice) {
        case 1:
            sortBy = "releaseYear";
            break;
        case 2:
            sortBy = "rating";
            break;
        case 3:
            sortBy = "genre";
            break;
        default:
            cout << "Invalid choice!" << endl;
            delete[] movies;
            return 1;
    }

    mergeSort(movies, 0, n - 1, sortBy);

    cout << "\nSorted movies by " << sortBy << ":\n";
    printMovies(movies, n);

    delete[] movies;
    return 0;
}

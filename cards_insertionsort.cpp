#include <iostream>
#include <string>
using namespace std;

struct Card {
    string suit;
    int value;
};

void insertionSort(Card cards[], int n) {
    for (int i = 1; i < n; ++i) {
        Card key = cards[i];
        int j = i - 1;

        while (j >= 0 && cards[j].value > key.value) {
            cards[j + 1] = cards[j];
            j = j - 1;
        }
        cards[j + 1] = key;
    }
}

void printCards(Card cards[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Suit: " << cards[i].suit << ", Value: " << cards[i].value << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of cards: ";
    cin >> n;

    Card* cards = new Card[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter suit for card " << i+1 << ": ";
        cin >> cards[i].suit;
        cout << "Enter value for card " << i+1 << ": ";
        cin >> cards[i].value;
    }

    insertionSort(cards, n);

    cout << "\nCards sorted by value in ascending order:\n";
    printCards(cards, n);

    return 0;
}

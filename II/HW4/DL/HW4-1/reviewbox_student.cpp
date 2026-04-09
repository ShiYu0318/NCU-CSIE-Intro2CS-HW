#include <iostream>
#include <iomanip>
#include "reviewbox_student.h"
using namespace std;

int ReviewBox::findIndex(const string& song) {
    // TODO:
    // Return the index of song in names
    return -1;
}

ReviewBox::ReviewBox() {
    names = {"ELEVEN", "LOVE_DIVE", "After_LIKE", "I_AM", "Kitsch",
             "Baddie", "HEYA", "Accendio", "REBEL_HEART", "ATTITUDE"};

    // TODO:
    // Allocate dynamic arrays totalScore and reviewCount
    // Their sizes should both be names.size()
    // Initialize all elements to 0
}

void ReviewBox::addReview(const string& song, int score) {
    // TODO:
    // Find the index of song
    // totalScore[idx] += score
    // reviewCount[idx]++
}

ReviewBox::~ReviewBox() {
    int reviewedSongs = 0;
    int totalReviews = 0;
    int best = -1;
    double bestAvg = -1.0;

    // TODO:
    // 1. reviewedSongs = number of songs with reviewCount[i] > 0
    // 2. totalReviews = sum of all reviewCount[i]
    // 3. best = index of the song with the highest average score
    // 4. bestAvg = average score of the best song
    //
    // Average score of one song:
    // avg = 1.0 * totalScore[i] / reviewCount[i]
    //
    // Tie-breaking rules:
    // (1) Higher average score wins
    // (2) If average scores are the same, the song with more reviews wins
    // (3) If still tied, the earlier song in names wins

    cout << "=== IVE Review Report ===\n";
    cout << "Reviewed songs: " << reviewedSongs << "\n";
    cout << "Total reviews: " << totalReviews << "\n";
    cout << "Best song: " << names[best] << "\n";
    cout << fixed << setprecision(2);
    cout << "Average score: " << bestAvg << "\n";

    // TODO:
    // delete[] totalScore;
    // delete[] reviewCount;
}

int main() {
    int N;
    cin >> N;

    {
        ReviewBox box;
        for (int i = 0; i < N; i++) {
            string song;
            int score;
            cin >> song >> score;
            box.addReview(song, score);
        }
    }

    return 0;
}
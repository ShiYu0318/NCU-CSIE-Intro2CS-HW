#include <iostream>
#include "streamlog_student.h"
using namespace std;

const vector<string> officialOrder = {
    "ELEVEN", "LOVE_DIVE", "After_LIKE", "I_AM", "Kitsch",
    "Baddie", "HEYA", "Accendio", "REBEL_HEART", "ATTITUDE"
};

int songOrder(const string& song) {
    // TODO:
    // Return the position of song in officialOrder
    // If song is not found, return a very large number
    return 1000000000;
}

StreamLog::StreamLog(int s, int d) {
    S = s;
    D = d;
    names.resize(S);
    pref.assign(S, vector<long long>(D + 1, 0));
}

void StreamLog::addSong(int idx, const string& song, const vector<long long>& a) {
    // TODO:
    // 1. Set names[idx] = song
    // 2. Set id[song] = idx
    // 3. Build the prefix sum for this song
    //
    // Example:
    // pref[idx][0] = 0
    // pref[idx][j] = pref[idx][j - 1] + a[j]
}

long long StreamLog::rangeSum(const string& song, int l, int r) {
    // TODO:
    // First find the index of song
    // Then use prefix sum to calculate:
    // pref[idx][r] - pref[idx][l - 1]
    return 0;
}

pair<string, long long> StreamLog::overallTop() {
    // TODO:
    // Compare all songs using total plays in [1, D]
    // Find the song with the largest total and return its name and value
    // If there is a tie, the earlier song in officialOrder wins
    return {"", 0};
}

pair<string, long long> StreamLog::bestSong(int l, int r) {
    // TODO:
    // Compare all songs using total plays in [l, r]
    // Find the song with the largest total and return its name and value
    // If there is a tie, the earlier song in officialOrder wins
    return {"", 0};
}

int main() {
    int S, D;
    cin >> S >> D;

    StreamLog log(S, D);

    for (int i = 0; i < S; i++) {
        string song;
        cin >> song;

        vector<long long> a(D + 1);
        for (int j = 1; j <= D; j++) {
            cin >> a[j];
        }

        log.addSong(i, song, a);
    }

    pair<string, long long> top = log.overallTop();
    cout << "OverallTop: " << top.first << ' ' << top.second << "\n";

    int Q;
    cin >> Q;
    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "SUM") {
            string song;
            int l, r;
            cin >> song >> l >> r;

            long long ans = log.rangeSum(song, l, r);
            cout << "SUM " << song << ' ' << l << ' ' << r
                 << " = " << ans << "\n";
        }
        else if (cmd == "BEST") {
            int l, r;
            cin >> l >> r;

            pair<string, long long> res = log.bestSong(l, r);
            cout << "BEST " << l << ' ' << r
                 << " = " << res.first << ' ' << res.second << "\n";
        }
    }

    return 0;
}
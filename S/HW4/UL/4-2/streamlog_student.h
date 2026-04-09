#ifndef STREAMLOG_STUDENT_H
#define STREAMLOG_STUDENT_H

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

extern const std::vector<std::string> officialOrder;

int songOrder(const std::string& song);

class StreamLog {
private:
    int S, D;
    std::vector<std::string> names;
    std::unordered_map<std::string, int> id;
    std::vector<std::vector<long long>> pref;

public:
    StreamLog(int s, int d);
    void addSong(int idx, const std::string& song, const std::vector<long long>& a);
    long long rangeSum(const std::string& song, int l, int r);
    std::pair<std::string, long long> overallTop();
    std::pair<std::string, long long> bestSong(int l, int r);
};

#endif
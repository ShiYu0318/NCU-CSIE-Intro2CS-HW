#ifndef REVIEWBOX_STUDENT_H
#define REVIEWBOX_STUDENT_H

#include <string>
#include <vector>

class ReviewBox {
private:
    std::vector<std::string> names;
    long long* totalScore;
    int* reviewCount;

    int findIndex(const std::string& song);

public:
    ReviewBox();
    void addReview(const std::string& song, int score);
    ~ReviewBox();
};

#endif
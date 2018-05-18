#ifndef STRINGSEARCH_H_
#define STRINGSEARCH_H_

#include <string>
#include <vector>

using namespace std;

class StringSearch {
    public:
        static bool kmp(string p, string t);
        static int editDistance(string p, strig t);

    private:
        static vector<int> prefixFunction(string p);
};


#endif
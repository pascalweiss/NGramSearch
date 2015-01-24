# include "BSScraper.h"
# include <iostream>
# include <utility>
#include <algorithm>

using namespace std;

string BSScraper::substringBeweenSeperators(string str, char seperator, int fromSeperator) {
    int subStrFrom = -1;
    int seperatorCount = 0;
    int i;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == seperator) {
            seperatorCount++;
            if (seperatorCount == fromSeperator) {
                subStrFrom = i+1;
            }
            else if (seperatorCount == fromSeperator + 1) {
                return str.substr(subStrFrom, i - subStrFrom);
            }
        }
        else if (str[i] == '\r' || str[i] == '\n') {
            return str.substr(subStrFrom, i - subStrFrom);
        }
    }
    return str.substr(subStrFrom, i - subStrFrom);
}

string BSScraper::toLower(string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
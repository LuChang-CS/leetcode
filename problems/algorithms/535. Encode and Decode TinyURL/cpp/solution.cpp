#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef unordered_map<string, string> Urlmap;

class Solution {
public:

    Urlmap urlmap;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        size_t size = urlmap.size();
        stringstream encoded;
        encoded << hex << size;
        string encoded_url = encoded.str();
        urlmap.insert(make_pair(encoded_url, longUrl));
        return encoded_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        Urlmap::iterator it = urlmap.find(shortUrl);
        if (it == urlmap.end()) return NULL;
        return it->second;
    }
};

int main() {
    Solution solution;
    cout << solution.decode(solution.encode("https://leetcode.com/problems/design-tinyurl")) << endl;
    return 0;
}

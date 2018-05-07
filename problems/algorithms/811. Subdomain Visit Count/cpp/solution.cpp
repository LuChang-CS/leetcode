#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {
    typedef unordered_map<string, int> DomainCount;
    DomainCount domain_count(500);
    for (auto &cpdomain: cpdomains) {
        int count = 0;
        int length = cpdomain.length();
        for (int i = 0; i < length; ++i) {
            switch(cpdomain[i]) {
            case ' ':  // find space
                // then we can know the count
                count = stoi(cpdomain.substr(0, i));
                // lowest domain level
                domain_count[cpdomain.substr(i + 1, length)] += count;
                break;
            case '.':
                // find each domain level by dot
                domain_count[cpdomain.substr(i + 1, length)] += count;
                break;
            }
        }
    }
    vector<string> result;
    result.reserve(domain_count.size());
    for (auto &dc: domain_count) {
        result.emplace_back(to_string(dc.second) + " " + dc.first);
    }
    return result;
}

int main() {
    vector<string> cpdomains;
    cpdomains.emplace_back("9001 discuss.leetcode.com");
    vector<string> result = subdomainVisits(cpdomains);
    for (auto &r: result) {
        cout << r << endl;
    }
}

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

bool isSeparator(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '?' || c == '!';
}

int main() {
    std::ifstream inFile("input.txt");
    if (!inFile) {
        std::cerr << "Error: cannot open input.txt\n";
        return 1;
    }
    std::string text, line;
    while (std::getline(inFile, line)) {
        text += line + ' ';
    }
    inFile.close();

    std::map<std::string,int> freq;
    std::string word;
    for (char c : text) {
        if (isSeparator(c)) {
            if (!word.empty()) {
                for (char &wc : word) wc = std::tolower(wc);
                ++freq[word];
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        for (char &wc : word) wc = std::tolower(wc);
        ++freq[word];
    }

    using Pair = std::pair<std::string,int>;
    auto cmp = [](Pair const &a, Pair const &b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first > b.first;
    };
    std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> pq(cmp);

    for (auto const &entry : freq) {
        pq.push({entry.first, entry.second});
    }

    while (!pq.empty()) {
        auto [w, count] = pq.top(); pq.pop();
        std::cout << w << " => " << count << "\n";
    }

    return 0;
}
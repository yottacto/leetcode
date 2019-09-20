#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>

struct Solution
{
    std::unordered_map<int, int> dis_begin;
    std::unordered_map<int, int> dis_end;

    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
    {
        if (wordList.empty() || std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        std::unordered_map<std::string, int> id;
        auto n = 0;
        for (auto const& word : wordList)
            id[word] = n++;
        if (!id.count(beginWord)) {
            wordList.emplace_back(beginWord);
            id[beginWord] = n++;
        }
        std::unordered_map<std::string, std::vector<int>> match;
        for (auto const& word : wordList) {
            int l = word.size();
            auto word_id = id[word];
            auto modified_word = word;
            for (auto i = 0; i < l; i++) {
                modified_word[i] = '*';
                match[modified_word].emplace_back(word_id);
                modified_word[i] = word[i];
            }
        }
        std::vector<std::vector<int>> g(n);
        for (auto const& p : match) {
            auto const& v = p.second;
            for (auto i = 0u; i < v.size(); i++)
                for (auto j = i + 1; j < v.size(); j++) {
                    g[v[i]].emplace_back(v[j]);
                    g[v[j]].emplace_back(v[i]);
                }
        }
        std::queue<std::pair<int, int>> begin_queue;
        begin_queue.emplace(id[beginWord], 0);
        std::queue<std::pair<int, int>> end_queue;
        end_queue.emplace(id[endWord], 0);
        dis_begin[id[beginWord]] = 0;
        dis_end[id[endWord]] = 0;
        while (!begin_queue.empty() && !end_queue.empty()) {
            {
                auto now = begin_queue.front();
                begin_queue.pop();
                for (auto next : g[now.first]) {
                    if (dis_end.count(next))
                        return now.second + dis_end[next] + 2;
                    if (dis_begin.count(next))
                        continue;
                    begin_queue.emplace(next, now.second + 1);
                    dis_begin[next] = now.second + 1;
                }
            }

            {
                auto now = end_queue.front();
                end_queue.pop();
                for (auto next : g[now.first]) {
                    if (dis_begin.count(next))
                        return now.second + dis_begin[next] + 2;
                    if (dis_end.count(next))
                        continue;
                    end_queue.emplace(next, now.second + 1);
                    dis_end[next] = now.second + 1;
                }
            }
        }
        return 0;
    }
};


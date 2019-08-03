#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

struct node
{
    std::unordered_map<char, node*> child;
    int end{-1};
};

struct Solution
{
    node* root{new node};
    node* rev_root{new node};
    std::vector<int> pos;

    template <class Iter>
    void insert(node* root, Iter begin, Iter end, int i)
    {
        auto p = root;
        for (auto it = begin; it != end; ++it) {
            if (!p->child.count(*it))
                p->child[*it] = new node;
            p = p->child[*it];
        }
        p->end = i;
    }

    template <class Vec>
    void manacher(std::string const& word, Vec& prefix, Vec& suffix)
    {
        prefix.resize(word.size());
        suffix.resize(word.size());
        std::string s{"!#"};
        for (auto ch : word) {
            s += ch;
            s += '#';
        }
        s += '~';
        int len = s.size() - 2;
        pos.clear();
        pos.resize(len + 1);
        auto r = 0;
        auto c = -1;
        for (auto i = 1; i <= len; i++) {
            if (i < r)
                pos[i] = std::min(pos[2 * c - i], r - i);
            while (s[i + pos[i]] == s[i - pos[i]])
                pos[i]++;
            if (i + pos[i] > r) {
                r = i + pos[i];
                c = i;
            }
            if (i - pos[i] == 0 && i > 1)
                prefix[(i + pos[i] - 1) / 2 - 1] = true;
            if (i + pos[i] == len + 1 && i < len)
                suffix[(i - pos[i]) / 2] = true;
        }
    }

    std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words)
    {
        int n = words.size();
        auto empty_index = -1;
        for (auto i = 0; i < n; i++) {
            auto const& word = words[i];
            insert(root, word.begin(), word.end(), i);
            insert(rev_root, word.rbegin(), word.rend(), i);
            if (word.empty())
                empty_index = i;
        }
        std::vector<std::vector<char>> prefix_palindrome(n);
        std::vector<std::vector<char>> suffix_palindrome(n);
        for (auto i = 0; i < n; i++)
            manacher(words[i], prefix_palindrome[i], suffix_palindrome[i]);
        std::vector<std::vector<int>> res;

        if (empty_index != -1)
            for (auto i = 0; i < n; i++) {
                auto const& word = words[i];
                if (word.empty())
                    continue;
                if (prefix_palindrome[i][word.size() - 1]) {
                    res.emplace_back(std::vector<int>{i, empty_index});
                    res.emplace_back(std::vector<int>{empty_index, i});
                }
            }

        for (auto i = 0; i < n; i++) {
            auto const& word = words[i];
            // forward traverse, (i, p->end)
            {
                auto p = rev_root;
                for (auto j = 0u; j < word.size(); j++) {
                    if (!p->child.count(word[j]))
                        break;
                    p = p->child[word[j]];
                    if (p->end != -1 && p->end != i
                            && (j == word.size() - 1 || suffix_palindrome[i][j + 1]))
                        res.emplace_back(std::vector<int>{i, p->end});
                }
            }

            // backward traverse, (p->end, i)
            {
                auto p = root;
                for (auto j = word.size() - 1; j >= 1; j--) {
                    if (!p->child.count(word[j]))
                        break;
                    p = p->child[word[j]];
                    if (p->end != -1 && p->end != i && prefix_palindrome[i][j - 1])
                        res.emplace_back(std::vector<int>{p->end, i});
                }
            }
        }

        return res;
    }
};


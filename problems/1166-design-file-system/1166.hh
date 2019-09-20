#include <string>
#include <unordered_map>

struct node
{
    std::unordered_map<std::string, node*> child;
    bool end{};
    int value{};
};

struct FileSystem
{
    node * root{new node};

    FileSystem()
    {
    }

    bool create(std::string path, int value)
    {
        int n = path.size();
        auto p = root;
        path += '/';
        for (auto i = 0; i < n - 1; ) {
            int next = path.find("/", i + 1);
            auto word = path.substr(i + 1, next - i - 1);
            auto last = next == n;
            if (!last) {
                if (!p->child.count(word))
                    return false;
            } else {
                if (p->child.count(word))
                    return false;
                p->child[word] = new node;
            }
            p = p->child[word];
            i = next;
        }
        p->end = true;
        p->value = value;
        return true;
    }

    int get(std::string path)
    {
        int n = path.size();
        auto p = root;
        path += '/';
        for (auto i = 0; i < n - 1; ) {
            int next = path.find("/", i + 1);
            auto word = path.substr(i + 1, next - i - 1);
            if (!p->child.count(word))
                return -1;
            p = p->child[word];
            i = next;
        }
        if (!p->end)
            return -1;
        return p->value;
    }
};


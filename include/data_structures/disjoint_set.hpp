#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <map>
#include <memory>

template <typename T>
class DisjointSet {
private:
    std::map<std::shared_ptr<T>, std::shared_ptr<T>> parent;
    std::map<std::shared_ptr<T>, int> rank;

public:
    void makeSet(std::shared_ptr<T> item) {
        parent[item] = item;
        rank[item] = 0;
    }

    std::shared_ptr<T> find(std::shared_ptr<T> item) {
        if(parent[item] != item) {
            parent[item] = find(parent[item]);
        }

        return parent[item];
    }

    bool unionSet(std::shared_ptr<T> a, std::shared_ptr<T> b) {
        std::shared_ptr<T> rootA = find(a);
        std::shared_ptr<T> rootB = find(b);
        
        if(rootA == rootB) {
            return false;
        }

        if(rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if(rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }
};

#endif // DISJOINT_SET_HPP

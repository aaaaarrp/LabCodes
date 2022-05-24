#include <iostream>
using namespace std;

class UnionFind {
    private:
        int length;
        int* id;
        int total_components;
        int* component_size;

    public:
        UnionFind(int size) {
            if (size < 0) {
                throw invalid_argument("size must be positive");
            }

            this -> length = size;
            this -> total_components = size;
            this -> id = new int[size];
            this -> component_size = new int[size];

            for (int i = 0; i < size; ++i) {
                id[i] = i;
                component_size[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] (this -> id);
            delete[] (this -> component_size);
        }

        int find(int p) {
            if (p == id[p]) return p;
            return id[p] = find(id[p]);
        }

        void unify(int a, int b) {
            if (connected(a, b)) return;

            int root1 = find(a);
            int root2 = find(b);

            if (component_size[root1] < component_size[root2]) {
                component_size[root2] += component_size[root1];
                id[root1] = root2;
                component_size[root1] = 0;
            } else {
                component_size[root1] += component_size[root2];
                id[root2] = root1;
                component_size[root2] = 0;
            }

            total_components -= 1;
        }

        bool connected(int a, int b) {
            return find(a) == find(b);
        }

        int size(int n) {
            return component_size[find(n)];
        }

        int size() {
            return length;
        }

        int components() {
            return total_components;
        }
};

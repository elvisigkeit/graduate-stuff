#ifndef UNIONFINDHPP
#define UNIONFINDHPP
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class DisjointSet {
private:
public:
    vector<T> objects;
    vector<unsigned> disjoint;
    
    void print(unsigned root, unsigned level) {
        for(unsigned i = 0; i < disjoint.size(); i++) {
            if(disjoint[i] == root && disjoint[i] != i) {
                for(unsigned j = 0; j < level; j++)
                    cout << "  ";
                cout << objects[i] << endl;
                print(i, level+1);
            }
        }
    }

    DisjointSet(vector<T> set) : objects(set) {
        for(unsigned i = 0; i < set.size(); i++) 
            disjoint.push_back(i);
    }

    //The main goal of this print is to show height in the heap,
    //otherwise it could be using the class find to define sets
    void print() {
        for(unsigned i = 0; i < disjoint.size(); i++) {
            if(disjoint[i] == i) {
                cout << objects[i] << endl;
                print(i, 1);
                cout << endl;
            }
        }
    }
};


template<typename T>
class QuickFind: public DisjointSet<T> {
private:
public:
    using DisjointSet<T>::DisjointSet;
    using DisjointSet<T>::objects;
    using DisjointSet<T>::disjoint;

    bool find(T first, T second) {
        unsigned first_index;
        unsigned second_index;

        for(unsigned i = 0; i < disjoint.size(); i++) {
            if(objects[i] == first)
                first_index = i;
            if(objects[i] == second)
                second_index = i;
        }

        return disjoint[first_index] == disjoint[second_index];
    }

    void join(T first, T second) {
        unsigned first_index;
        unsigned second_index;

        for(unsigned i = 0; i < disjoint.size(); i++) 
            if(objects[i] == first)
                first_index = i;
        for(unsigned i = 0; i < disjoint.size(); i++) 
            if(objects[i] == second)
                second_index = i;

        for(unsigned i = 0; i < disjoint.size(); i++) 
            if(disjoint[i] == second_index)
                disjoint[i] = disjoint[first_index];
    }
};

template<typename T>
class QuickUnion: public DisjointSet<T> {
private:
public:
    using DisjointSet<T>::DisjointSet;
    using DisjointSet<T>::objects;
    using DisjointSet<T>::disjoint;

    unsigned find_root(unsigned item) {
        if(item == disjoint[item])
            return item;
        find_root(disjoint[item]);
    }

    bool find(T first, T second) {
        unsigned first_index;
        unsigned second_index;

        for(unsigned i = 0; i < disjoint.size(); i++) {
            if(objects[i] == first)
                first_index = i;
            if(objects[i] == second)
                second_index = i;
        }

        unsigned first_root = find_root(first_index);
        unsigned second_root = find_root(second_index);

        return first_root == second_root;
    }

    void join(T first, T second) {
        unsigned first_index;
        unsigned second_index;

        for(unsigned i = 0; i < disjoint.size(); i++) 
            if(objects[i] == first)
                first_index = i;
        for(unsigned i = 0; i < disjoint.size(); i++) 
            if(objects[i] == second)
                second_index = i;

        unsigned first_root = find_root(first_index);
        unsigned second_root = find_root(second_index);

        disjoint[second_root] = first_root;
    }
};



#endif
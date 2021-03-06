//
// Created by hani on 29/11/2019.
//

#ifndef EX2_EX2_H
#define EX2_EX2_H

#endif //EX2_EX2_H

#include <stdlib.h>
#include <unordered_map>
#include <list>
#include <fstream>
#include <functional>
#include <iostream>

using namespace std;

template<typename T>
class CacheManager {

private:
    std::list<string> keys;
    unordered_map<string, pair<T, list<string>::iterator>> map;
public:
    string class_name;
    unsigned int cacheSize;

    CacheManager(int capacity);

    void insert(string key, T obj);

    T get(string key);

    void foreach(const function<void(T &)> func);
};


template<typename T>
void CacheManager<T>::insert(string key, T obj) {
    //the key is not in the cache->write into the filesystem and into the cache
    if (map.find(key) == map.end()) {
        //cache is full->clear space to insert.
        if (keys.size() == cacheSize) {
            //delete the LRU
            string last = keys.back();
            keys.pop_back();
            map.erase(last);
        }
    }
        //the key IS in the cache->update the reference
    else {
        keys.erase(map[key].second);
    }
    //write to a file.
    //INSERT CODE OF WRITING TO A FILE HERE
    std::fstream out_file(key + ".txt", std::ios::out);
    out_file<<obj<<endl;
    out_file.close();
    keys.push_front(key);
    map[key] = make_pair(obj, keys.begin());
    cout<<"inserting " + key + ":" + obj<<endl;
}

template<typename T>
T CacheManager<T>::get(string key) {
    if (map.find(key) == map.end()) {
        //^can't find the key in the cache, try on the disk
        std::fstream in_file;
        in_file.open(key + ".txt", std::ios::in | std::ios::out);
        cout<<key<<endl;
        if (!in_file) {
            throw "error in opening file to read";
        }
        //got the object from the harddisk, now insert it
        T obj;
//        if (in_file.is_open()) {
//            in_file.read((char *) &obj, sizeof(obj));
//            in_file.close();
//        }
        string line, solution = "";
        while (std::getline(in_file, line)) {
          solution += line;
        }
        //delete the LRU if the cache is full
        if (keys.size() == cacheSize) {
            //delete the LRU
            string last = keys.back();
            keys.pop_back();
            //deletes the last one
            map.erase(last);
        }
        //insert the object to MRU
        keys.push_front(key);
        map[key] = make_pair(solution, keys.begin());
        return solution;
    } else {
        cout<<"found in map"<<endl;
        T obj = map[key].first;
        keys.erase(map[key].second);
        keys.push_front(key);
        map[key] = make_pair(obj, keys.begin());
        return obj;
    }

}


template<typename T>
CacheManager<T>::CacheManager(int capacity) {
    cacheSize = capacity;
}

template<typename T>
void CacheManager<T>::foreach(const function<void(T &)> func) {
    for (auto it = keys.begin(); it != keys.end(); it++) {
        T obj = map[*it].first;
        func(obj);
    }
}

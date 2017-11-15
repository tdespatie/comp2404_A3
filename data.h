
// File Name: Data.h
// Created by Tyler Despatie on 11/12/2017.
// Student Number: 101010622
// Assignment: 1
// Course: COMP 2404
// Section: A4



#ifndef ANSWER_CODE_DATA_H
#define ANSWER_CODE_DATA_H

#include <vector>

template <typename T>
class data {
public:
    int id;
    vector<T*> collection;
    int getID() const {
        return id;
    }
    typename vector<T*>::iterator findPosition(T &item) {
        for(typename vector<T*>::iterator it = collection.begin(); it != collection.end(); ++it)
            if (*it == &item) return it;
        return collection.end();
    }
};


#endif //ANSWER_CODE_DATA_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel								 */
/*  Contributors: Tyler Despatie 101010622			 */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef ANSWER_CODE_MYTUNESCOLLECTION_H
#define ANSWER_CODE_MYTUNESCOLLECTION_H

#include "UI.h"
#include <typeinfo>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class MyTunesCollection {
public:
    ~MyTunesCollection() {
        for (int i=0; i<collection.size(); i++)
            delete collection[i];
    }

    T * findByID(const int& anID) {
        for (typename vector<T *>::iterator it = collection.begin(); it != collection.end(); ++it)
            if ((*it)->getID() == anID) return *it;
        return NULL;
    }

    T * findByID(const string& anID) {
        for (typename vector<T*>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
            if((*itr)->getUserID() == anID) return *itr;
    }

    void add(T &item) {
        collection.push_back(&item);
    }
    void remove(T &item) {
        typename vector<T*>::iterator index = findPosition(item);
        if (index != collection.end()) {
            T * theItem = *index;
            collection.erase(index);
            delete theItem;
        }
    }
    void showOn(UI & aView) {
        aView.printOutput("Print:");
        for (int i=0; i<collection.size(); i++)
            aView.printOutput((*collection[i]).toString());
    }

    // Refactored CODE
    template<typename V>
    void showOn(UI & aView, V memberID) {
        T * item = findByID(memberID);
        if (item != NULL)
            aView.printOutput(item->toString());
    }

    friend std::ostream& operator<<(ostream& out, const T& t) {
        return out << t.toString() << endl;
    }

    vector<T*> getCollection() const {
        return collection;
    }

private:
    vector<T*> collection;
    typename vector<T*>::iterator findPosition(T &item) {
        for(typename vector<T*>::iterator it = collection.begin(); it != collection.end(); ++it)
            if (*it == &item) return it;
        return collection.end();
    }

};

#endif //ANSWER_CODE_MYTUNESCOLLECTION_H

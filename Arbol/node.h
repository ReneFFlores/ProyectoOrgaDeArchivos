#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "index.h"
#include <QString>

class Node{
    //private
    int page, father;
    vector<int> sons;
    vector<Index> keys;
public:
    Node();
    void setKeys(vector <Index>);
    vector <Index> getKeys();
    void setPage(int);
    int getPage();
    void setFather(int);
    int getFather();
    void setSons(vector<int>);
    vector<int> getSons();
    string toString();
};

#endif // NODE_H

#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "index.h"
#include <string>

class Tree{
    vector<Node*> arbol;
    int orden;
    int root;
public:
    Tree();
    Tree(int);
    ~Tree();
    int BusquedaBinaria(vector<Index> ,unsigned long);
    int EliminarBusquedaBinaria(vector<Index> ,unsigned long);
    void Split(int);
    int Promote(int , int );
    void Eliminar(Index);
    void Agregar(Index);
    void setRoot(int);
    int getRoot();
    int Buscar(unsigned long);
    void Underflow(Node* );
    int PaginaSucesorInmediato(Node* ,int);
    int PaginaPredecesorInmediato(Node* ,int);
};

#endif // BTREE_H

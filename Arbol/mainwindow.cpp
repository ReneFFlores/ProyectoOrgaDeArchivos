#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "index.h"
#include "node.h"
#include "btree.h"
#include <QString>
#include <string>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pb_arbol_clicked(){
    //Node nodo;
    Tree btree(16);
    vector<Index> indices;

    //agregar al arbol 30 registros de prueba
    for(unsigned long int i = 1; i < 31; i++){
        Index indice((i+1000),i);
        indices.push_back(indice);
        btree.Agregar(indice);
        QString str_i = QString::number(i)+".-";
        str_i+=QString::number(i+1000)+"\n";
        ui->te_lista->append(str_i);
    }


    QString final = "Arbol b\n";
    QString linea = "-------------------------";

    ui->te_lista->append(linea);
    ui->te_lista->append(final);

    //buscar 1021
    int q = btree.BinarySearch(indices,1021);
    ui->te_lista->append("Dato encontrado en: ");
    ui->te_lista->append(QString::number(q));
    ui->te_lista->append(linea);

    //Test de eliminar
    btree.Eliminar(indices.at(15));
    btree.Eliminar(indices.at(16));
    btree.Eliminar(indices.at(17));
    btree.Eliminar(indices.at(18));

    //a ver si elimino de vdd
    int m = btree.Buscar(1017);
    if(m==-1){
        ui->te_lista->append("Dato no encontrado");
        ui->te_lista->append(linea);
    }else{
        ui->te_lista->append("Llave encontrada en");
        ui->te_lista->append(QString::number(m));
        ui->te_lista->append(linea);
    }

}

void MainWindow::on_pb_salir_clicked(){
    exit(0);
}

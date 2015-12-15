#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool copiar(string);

int main(){
    ifstream file("ToJson.json");
    string ignore;
    getline(file,ignore);
    getline(file,ignore);
    while(!file.eof()){
       string line;
       getline(file,ignore);
       getline(file,line);
       getline(file,ignore);
       cout << line << endl;
    }
    
    if(copiar("ToJson.json")){
      cout << "copiado bien :)" << endl;
    }
    file.close();
    system("PAUSE");
    return 0;
}

bool copiar(string json_path){
     ifstream original(json_path.c_str());
     ofstream copied("JChepiado.json",ios::app);
     while(!original.eof()){
         string linea;
         getline(original, linea);
         copied << linea << endl;;
     }
     
     original.close();
     copied.close();
     return true;
}

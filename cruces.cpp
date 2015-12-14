#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;
using std::string;
using std::vector;
using std::stringstream;

int int_maker(char);

int main(int argc, char*argv[]){
    //se llama al archivo a pasar a xml
	ifstream get_txt("PersonFileToOutCruces.txt");
	
	string name = "CrucesPersonaCiudad";
		
	//vector q se usara
	vector<string> registros;
	
	//para infile
   string null_str;
	getline(get_txt,null_str);
	
	//buscamos los campos
	while(!get_txt.eof()){
      string temp_str;
      getline(get_txt,temp_str);
      registros.push_back(temp_str);
   }
   
   ifstream places("LugaresCruces.txt");
   getline(places,null_str);
   vector<string> lugares_todos;
   
   while(!places.eof()){
       string temp_str_c;
       getline(places,temp_str_c);
       lugares_todos.push_back(temp_str_c);
   }
	
	//a cruzado, se busca el nombre
	ofstream outdata;
	name+=".txt";
   
	outdata.open(name.c_str());
	
   for(int i = 0; i < registros.size();i++){
      string temp = "";
      int per_city = 0;
      temp+=(registros.at(i)).at(33);
      temp+=(registros.at(i)).at(34);
      //cout << registros.at(i) << " ";
      if(temp[0]!='0'){
        per_city++;
        per_city*=(int_maker(temp[0]))*10;
      }
      if(temp[1]!='0'){
        per_city+=(int_maker(temp[1]));
      }
      
      //cout << " " << lugares_todos.at(per_city-1) << endl;// << endl;
      
      outdata << registros.at(i) << " " << lugares_todos.at(per_city-1) << endl;
      
   }//for i 
      
   places.close();
   get_txt.close();
   outdata.close();
	system("pause");
	return 0;
}

int int_maker(char digit){
    if(digit=='1'){
       return 1;
    }else if(digit=='2'){
       return 2;
    }else if(digit=='3'){
       return 3;
    }else if(digit=='4'){
       return 4;
    }else if(digit=='5'){
       return 5;
    }else if(digit=='6'){
       return 6;
    }else if(digit=='7'){
       return 7;
    }else if(digit=='8'){
       return 8;
    }else if(digit=='9'){
        return 9;
    }
}

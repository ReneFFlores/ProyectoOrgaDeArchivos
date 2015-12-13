#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstring>

using namespace std;
using std::string;
using std::vector;

int int_maker(string);
int char_to_int(char);

int main(int argc, char*argv[]){
    //se llama al archivo a pasar a xml
	ifstream get_txt("PersonFile.txt");
	const string FILE_HEAD = "<xs:schema xmlns:xs=\"http://www.w3.org/2001/XMLSchema\">";
	
	//creamos variables y llamamos los primeros atributos del archivo
	int campos, registros;
	string name;
	get_txt >> name;
	get_txt >> campos;
	get_txt >> registros;
	vector<string> campo_nombre;
	vector<int> bytes_por_campo;
	vector<string> tipo_de_campo;
	vector<string> todos;
	vector<bool> are_keys;
	vector<int> decimals_values;
	
	//buscamos los campos
	for(int i = 0; i < campos; i++){
      string temp_name;
      string temp_type;
      int temp_size;
      string is_key;
      int decimals;
      get_txt >> temp_name;
      get_txt >> temp_size;
      get_txt >> temp_type;
      get_txt >> is_key;
      get_txt >> decimals;
      campo_nombre.push_back(temp_name);
      bytes_por_campo.push_back(temp_size);
      tipo_de_campo.push_back(temp_type);
      decimals_values.push_back(decimals);
      if(is_key[0]=='t'||is_key[0]=='T'){
         are_keys.push_back(true);      
      }else{
         are_keys.push_back(false);
      }
   }
   
   //agarramos los registros
   for(int i = 0; i < registros; i++){
      string line;
      getline(get_txt,line);
      todos.push_back(line);
   }
   
   //se lista para ver q ondas
   cout << name << endl;
   for(int i = 0; i < registros;i++){
       cout << todos.at(i) << endl;
   }
	
	//a xmlsxchema, se busca el nombre
	ofstream outdata;
	name+=".XSD";
   
	outdata.open(name.c_str(), ios::app);
	string columns = "";

	outdata << FILE_HEAD << endl;
	

   //imprime en el archivo xmlschema los campos
   /*for(int i = 0; i < registros; i++){
      outdata << "    <xs:sequence>" << endl;//secuence initia******************
      string per_record = "";
      string line;     
      for(int j = 0; j < campo_nombre.size(); j++){
          string this_temp = "";
          get_txt >> this_temp;
          outdata << campo_nombre.at(j) << " " << this_temp << " " << tipo_de_campo.at(i) << endl;
          if(j == campo_nombre.size()-1){
            outdata << endl;
          }
      }//for j
      
      outdata << "    <xs:sequence>" << endl;//fin sequence*********************
   }*/
   outdata << "</xs:complexType>" << endl;
   outdata << "</xs:element>" << endl;
   outdata << "</xs:schema>" << endl;
   get_txt.close();
   outdata.close();
	system("pause");
	return 0;
}

int int_maker(string values){
  int digits = 1, counter = 0;
  for(int i = values.length(); i > 0; i--){
     if(values[i]=='0'){
       digits*=10;
     }else{
       counter+=(char_to_int(values[i])*digits);
     }
  }//fin for
  return counter;
}

int char_to_int(char num){
  if(num=='1'){
     return 1;
  }else if(num=='2'){
     return 2;
  }else if(num=='3'){
     return 3;
  }else if(num=='4'){
     return 4;
  }else if(num=='5'){
     return 5;
  }else if(num=='6'){
     return 6;
  }else if(num=='7'){
     return 7;
  }else if(num=='8'){
     return 8;
  }else if(num=='9'){
     return 9;
  }
}

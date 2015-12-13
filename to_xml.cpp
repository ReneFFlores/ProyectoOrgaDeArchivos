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

int int_maker(string);
int char_to_int(char);

int main(int argc, char*argv[]){
    //se llama al archivo a pasar a xml
	ifstream get_txt("PersonFileToOut.txt");
	const string FILE_HEAD = "<?xml version=\"1.0\"?>";
	
	//creamos variables y llamamos los primeros atributos del archivo
	int campos, registros;
	string name, name_infile;
	get_txt >> name;
	get_txt >> campos;
	get_txt >> registros;
	
	//vector q se usara
	vector<string> campo_nombre;
	
	//para infile
	name_infile = name;
	
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
   }
	
	//a xml-schema, se busca el nombre
	ofstream outdata;
	name+=".xml";
   
	outdata.open(name.c_str(), ios::app);

	outdata << FILE_HEAD << endl;
	outdata << '<' << name_infile << '>' << endl;
	
   for(int i = 0; i < registros;i++){
      string fout[campos];
      for(int j = 0; j < campos; j++){
         get_txt >> fout[j];
         cout << campo_nombre.at(j) << " " << fout[j] << " ";
         outdata << '\t' << '<' << campo_nombre.at(j) << ">" << fout[j] << "</" << campo_nombre.at(j) << '>' << endl;
      }
      
      cout << endl;
      
   }//for i 
   
   outdata << "</" << name_infile << '>';
      
   get_txt.close();
   outdata.close();
	system("pause");
	return 0;
}

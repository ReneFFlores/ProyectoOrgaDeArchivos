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
	
	string name = "This_Json_example";
		
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
	
	//a xml-schema, se busca el nombre
	ofstream outdata;
	name+=".json";
   
	outdata.open(name.c_str(), ios::app);

	outdata << '{' << endl << '\t' << "\"registros\": [";
	
   for(int i = 0; i < registros.size();i++){
      outdata << endl << '\t' << '{' << endl << "\t\t\"registry" << '\"' << ": " << registros.at(i) << endl << "\t" << '}';
      if(i!=registros.size()-1){
        outdata << ',';
      }
   }//for i 
      
   get_txt.close();
   outdata.close();
	system("pause");
	return 0;
}

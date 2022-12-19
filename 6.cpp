#include <iostream>
#include <fstream>
#include <string>

int main(void){

	std::ifstream infile;
	infile.open("6.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line;

	while(!infile.eof()){
		getline(infile,line);
		std::cout << line << std::endl;		
	}
	for(int i = 0; i < line.length() / 4 ; i++){
		std::cout << line.substr(i * 4, 4) << std::endl;
	}
	
}

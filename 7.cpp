#include <iostream>
#include <fstream>
#include <string>

int main(void){

	std::ifstream infile;
	infile.open("4.txt");
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
}

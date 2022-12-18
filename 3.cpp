#include <iostream>
#include <fstream>
#include <string>

int main(void){

	std::ifstream infile;
	infile.open("3.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line;

	while(!infile.eof()){
		getline(infile,line);
		printf("%s %u\n", line.c_str(), line.length());
		std::cout << line.substr(0,line.length()/2) << std::endl;
		std::cout << line.substr(line.length()/2, line.length()) << std::endl;
		for(int i = line.length()/2; i < line.length(); i++){
			std::cout << line.at(i);
		}
		printf("\n");
		for(int i = line.length(); i > 0; i--){
			printf("-");
		}
		printf("\n");
	}
		
	
	infile.close();

}

#include <iostream>
#include <fstream>
#include <string>
#include "elf1.h"


int main(void){

	int elfcount = 0;
	int highest = 0;
	
	elf e;

	std::ifstream infile;
	infile.open("1.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line;
	while(!infile.eof()){
		getline(infile,line);
		if (line.length() > 0){
			e.addFruit(stoi(line));
		}
		else{
			if(e.total() > highest){
				highest = e.total();
			}
			e.clearAll();
		}
		
		std::cout << line << " : " << line.length() << std::endl;
	}
	printf("Highest : %d\n", highest);

}


#include <iostream>
#include <fstream>
#include <string>

int main(void){

	int partSize = 14;
	std::ifstream infile;
	infile.open("6.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line;

	getline(infile,line);
	for(int i = 0; i < line.length() - partSize; i++){
		std::string part = line.substr(i , partSize);
		std::cout << part << "  ";
		for(int j = 0; j < partSize - 1; j++){
			std::string car = part.substr(j,1);
			std::string cdr = part.substr(j + 1, part.length() - j - 1);
			int found = cdr.find(car);
			std::cout << "|" << car << "-" << cdr << ":" << found;
//			std::cout << " | " << part.substr(i,1) << "-" << part.substr(i + 1, part.length() - i - 1);
			if(found != -1){
				break;
			}
			else if(j == partSize - 2){
				std::cout << std::endl << i + partSize << " - Marker: " << part << std::endl;
				return 0;
			}
			else{
				continue;
			}
		}
		std::cout << std::endl;
		
	}
	
}

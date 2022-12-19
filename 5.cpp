#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void){

	std::vector<char> crates[9];
	
	std::ifstream infile;
	infile.open("5_test.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line = "filler";

	//Get the starting state of the crates
	while(!infile.eof()) {
		getline(infile,line);
		if(line.at(1) == '1'){
			break;
		}

		for(int i = 0; i < 9; i++){
			if(line.length() < i * 4 + 1){
				break;
			}
			else if(line.at(i * 4 + 1) == ' '){
				continue;
			}
			else{
				crates[i].insert(crates[i].begin(),line.at(i * 4 + 1));
			}
		}
		std::cout << line << std::endl;		
/*		for(int i = 0; i < line.length(); i++){
			printf("%d", i % 10);		
		}
		printf("\n");		*/
	}
	for(int i = 0; i < 9; i++){
		if(crates[i].size() == 0){
			continue;
		}
		
		for(int j = 0; j < crates[i].size(); j++){
			std::cout << crates[i][j];
		}
		std::cout << std::endl;

	}
	while (!infile.eof()){
		getline(infile,line);
		std::cout << line << std::endl;
		int d1 = line.find(" ");
		int d2 = line.find(" ", d1 + 1);
		int d3 = line.find(" ", d2 + 1);
		int d4 = line.find(" ", d3 + 1);
		int d5 = line.find(" ", d4 + 1);
		for(int i = 0; i <= d5; i++){
			if(i == d1 || i == d2 || i == d3 || i == d4 || i == d5){
				printf("%c",'_');
			}
			else{
			printf("%d", i % 10);
			}
		}
		printf("\n");
//		int quantity, source, destination;
//		
		std::cout << "|" << line.substr(d1 + 1, d2 - d1 - 1) << "|" << std:: endl;
		std::string temp = line.substr(d1 + 1, d2 - d1 - 1);
		std::cout << "|" << temp << "|" << std::endl;
		std::cout <<stoi(temp) << std::endl;
// 		int quantity = stoi(line.substr(d1 + 1, d2 - d1 - 1));

		std::cout << "|" << line.substr(d3 + 1, d4 - d3 - 1) << "|" << std::endl;
	}
	
}

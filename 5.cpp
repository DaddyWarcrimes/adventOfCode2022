#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define DEBUG

void printCrates(std::vector<char> crates[9], int highlight = 10){
	for(int i = 0; i < 9; i++){
		if(crates[i].size() == 0){
			std::cout << "[\n";
			continue;
		}
		
		for(int j = 0; j < crates[i].size(); j++){
			std::cout << crates[i][j];
		}
		if(i == highlight){
			std::cout << "  <----- " << highlight + 1 ;
		}
		
		std::cout << std::endl;
	}
}

int main(void){

	
	std::vector<char> crates[9];
	
	std::ifstream infile;
	infile.open("5.txt");
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
	}

	printCrates(crates);

	while (!infile.eof()){
		getline(infile,line);
		if(line.length() == 0){
			continue;
		}
		
		std::cout << "------------------------------------------------" << std::endl << line << std::endl << "------------------------------------------------" << std::endl;;
		// Find the delimiters
		int d1 = line.find(" ");
		int d2 = line.find(" ", d1 + 1);
		int d3 = line.find(" ", d2 + 1);
		int d4 = line.find(" ", d3 + 1);
		int d5 = line.find(" ", d4 + 1);

		// Store the numbers from the string
		unsigned long int quantity = stoul(line.substr(d1 + 1, d2 - d1 - 1));
		unsigned long int source = stoul(line.substr(d3 + 1, d4 - d3 - 1)) - 1;
		unsigned long int destination = stoul( line.substr(d5 + 1, line.length() - d5 - 1)) - 1;

		printCrates(crates, source);
		//Move crates from source to destination
		std::cout << "---------------" << std::endl;
		for(int i = quantity; i > 0 ; i--){
			crates[destination].push_back(crates[source][crates[source].size() - i]);
			std::cout << crates[source][crates[source].size() - i];
		}
		for(int i = 0; i < quantity; i++){
			crates[source].pop_back();
		}
		

		//part 1
		/*for(int i = 0; i < quantity; i++){
			std::cout << crates[source][crates[source].size() - 1] ;
			crates[destination].push_back(crates[source][crates[source].size() - 1]);
			crates[source].pop_back();
		}*/
		std::cout << std::endl;
		std::cout << "---------------" << std::endl;
		printCrates(crates, destination);
		
	}
	
	std::cout << std::endl  << "Final top layer: ";
	for(int i = 0; i < 9; i++){
		std::cout  << crates[i][crates[i].size() - 1];
	}
	std::cout << std::endl;
	
}

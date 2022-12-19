#include <iostream>
#include <fstream>
#include <string>

int main(void){

	int overlaps = 0;
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
		if(line.length() ==0){
			continue;
		}
		//Identify the delimiters
		int hyp1 = line.find("-");
		int hyp2 = line.find("-", hyp1 + 1);
		int comma = line.find(",");
		std::cout << line <<  " " << std::endl;

		//Get and store the sectors
		int A = stoi(line.substr(0,hyp1));	
		int B = stoi(line.substr(hyp1 + 1, comma - hyp1 - 1));
		int C = stoi(line.substr(comma + 1, hyp2 - comma - 1 ));
		int D = stoi(line.substr(hyp2 + 1, line.length() - hyp2 - 1));
	//	std::cout << line.substr(hyp2 + 1, line.length() - hyp2 - 1) << std::endl;
		//Identify the overlaps
		if((A <= C && D <= B) || ((C <= A && B <= D)) ){
			std::cout << "Overlap" << std::endl;
			overlaps ++;
		}
		
		
	}
	std::cout << "Overlaps: " << overlaps << std::endl;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "elf1.h"


int main(void){

	int elfcount = 0;
	int highest = 0;
	
	elf e;
	std::vector<int> totals;

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
			totals.push_back(e.total());
			if(e.total() > highest){
				highest = e.total();
			}
			e.clearAll();
		}
		
	}
	printf("Highest : %d\n", highest);
	std::sort(totals.begin(), totals.end(), std::greater<int>());
	int highThree = 0;
	for(int i = 0; i < 3; i++){
		highThree += totals[i];
	}
	
		printf("Highest 3 : %d\n",highThree);

}


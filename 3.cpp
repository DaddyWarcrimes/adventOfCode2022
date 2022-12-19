#include <iostream>
#include <fstream>
#include <string>

int priority(char item){
	if(item < 91){
		return item - 38;
	}
	else{
		return item - 96;
	}

}

int main(void){

	int total = 0;
	std::ifstream infile;
	infile.open("3.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line[3];
	
	while(!infile.eof()){
		printf("--------------------------------------\n");
		for(int i = 0; i < 3 && !infile.eof(); i++){
			getline(infile, line[i]);	
		}
		
		int small;
		if(line[0].length() < line[1].length() && line[0].length() < line[2].length()){
			small = 0;
		}
		else if(line[1].length() < line[0].length() && line[1].length() < line[2].length()){
			small = 1;
		}
		else if(line[2].length() < line[0].length() && line[2].length() < line[1].length()){
			small = 2;
		}
		std::cout << line[0] << std::endl << line[1] << std::endl << line[2] << std::endl << line[small] << " Shortest" << std::endl;

		for(int i = 0; i < line[small].length(); i++){
		//	std::cout << "Looking for " << small.substr(i,1) << std::endl;			
			if(line[0].find(line[small].substr(i,1)) == -1 || line[1].find(line[small].substr(i,1)) == -1 || line[2].find(line[small].substr(i,1)) == -1){
				continue;
			}
			else{
				std::cout << "Found " << line[small].at(i) << " at " << i << " with a value of " << priority(line[small].at(i)) << std::endl;
				total += priority(line[small].at(i));
				std::cout << "Running total: " << total << std::endl;
				i = line[small].length();
			}
		}



	/*	
		printf("%s %u\n", line.c_str(), line.length());
		std::string first = line.substr(0,line.length()/2);
		std::string second = line.substr(line.length()/2,line.length()/2);
		std::cout << first << std::endl << second << std::endl;
		
		for(int i = 0; i < first.length(); i++){
			std::cout << "looking for " << first.substr(i,1)  << " at " << i << std::endl;
			int found = second.find(first.substr(i,1));
			if(second.find(first.substr(i,1)) == -1){
				continue;
			}
			else{
				int value;
				if(first.at(i) < 91){
					value = first.at(i) - 38;
				}
				else{
					value = first.at(i) - 96;
				}
				printf("%c %d\n",first.at(i), value);
				i = first.length();
				total += value;
			}
		}
		for(int i = line.length(); i > 0; i--){
			printf("-");
		}
		printf("\n");*/
	}
	infile.close();
	printf("total: %d\n",total);

}

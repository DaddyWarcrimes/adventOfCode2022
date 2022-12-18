#include <iostream>
#include <fstream>
#include <string>

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
	std::string line;

	while(!infile.eof()){
		getline(infile,line);
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
		printf("\n");
	}
	infile.close();
	printf("total: %d\n",total);

}

#include <iostream>
#include <fstream>
#include <string>


int main(void){

	std::ifstream infile;
	infile.open("9.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line;
	int hH = 0;
	int hV = 0;
	int maxH = 0;
	int minH = 0;
	int maxV = 0;
	int minV = 0;

	while(!infile.eof()){
		getline(infile,line);
		if(line.length() < 3){
		continue;
		}
		char dir = line.at(0);
		int q = stoi(line.substr(2,line.length() ));
		std::cout << dir << " | " << q << std::endl;
		switch(dir){
			case 'R':
				hH += q;
				if(hH > maxH){
					maxH = hH;
				}
				break;
			case 'L':
				hH -=q;
				if(hH < minH){
					minH = hH;
				}
				break;
			case 'U':
				hV -=q;
				if(hV < minV){
					minV = hV;
				}
				break;
			case 'D':
				hV +=q;
				if(hV > maxV){
					maxV = hV;
				}
				break;
			default:
				break;
		}
	}
	printf("%d %d %d %d \n", maxH, minH, maxV, minV);
}

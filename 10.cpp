#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int newCycle(){
	static int currentCycle = 0;
	return ++currentCycle;
}

int signal(int X, int C){
	static int sum = 0;
	if((C + 20) % 40 == 0){
		printf("Cycle %d: %d\n",C, C * X);
		sum += X * C;
		printf("sum: %d\n",sum);
	}
	return X * C;
	
}
int main(void){

	std::ifstream infile;
	infile.open("10.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line;
	static int cycle = 0;
	std::vector<std::string> instructions;
	int X = 1;
	bool display[240];
	for(int i = 0; i < 240; i++){
			display[i] = false;
	}
	

	while(!infile.eof()){
		getline(infile,line);
//		std::cout << line << std::endl;		
		if(line.length() == 0){
			continue;
		}
		instructions.insert(instructions.begin(),line);
		if (line.at(0) == 'n'){
			signal(X, newCycle());
		}
		else{
			signal(X, newCycle());
			signal(X, newCycle());
			X += stoi(line.substr(5,line.length() - 5));
		}
//		printf("->%d\n",X);
		
		
	}
}

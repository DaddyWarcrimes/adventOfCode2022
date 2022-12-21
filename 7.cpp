#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void){

	std::ifstream infile;
	infile.open("7.txt");
	if(!infile){
		printf("failed to open infile\n");
	}
	else{
		printf("infile opened\n");
	}
	std::ofstream outfile;
	outfile.open("7out.txt");
	if(!infile){
		printf("failed to open outfile\n");
	}
	else{
		printf("outfile opened\n");
	}
	std::string path;
	std::string line;
	int i = 0;
	getline(infile,line);
	while(!infile.eof()){
//		std::cout << line << std::endl;
		if(line.substr(0,6) == "$ cd /"){
			std::cout << line << std::endl;
			path = "/";
			outfile << path << std::endl;
			std::cout << path << std::endl;
			getline(infile,line);
			continue;
		}

		else if(line.substr(0,7) == "$ cd .."){
			std::cout << line << std::endl;
			path = path.substr(0,path.find_last_of('/'));
			if(path.length() == 0){
				path = "/";
			}
			
			std::cout << path << std::endl;
			getline(infile,line);
			continue;
		}
		else if(line.substr(0,4) == "$ cd"){
			std::cout << line << std::endl;
			if(path.length() > 1){
				path.append("/");
			}
			path.append(line.substr(5,line.length() - 4));
			std::cout << path << std::endl;
			outfile << path << std::endl;
			std::cout << path << std::endl;
			getline(infile,line);
			continue;
		}	
		else if(line.substr(0,4) == "$ ls"){
			//std::cout << line << std::endl;

			unsigned long int dirSize = 0;
			getline(infile,line);
			while(line.substr(0,1) != "$" && !infile.eof()){
				if(line.substr(0,3) == "dir"){
				getline(infile,line);
				continue;
				}
				else{
				dirSize += stoul(line.substr(0,line.find_first_of(' ')));
				getline(infile,line);
				continue;
				}
			}
			outfile << dirSize << std::endl;
			std::cout << dirSize << std::endl;
		}
	}
	infile.close();
	outfile.close();
	infile.open("7out.txt");
	if(!infile){
		printf("failed to open infile\n");
	}
	else{
		printf("infile opened\n");
	}
	std::vector<std::string> directories;
	
	while(!infile.eof()){
		getline(infile,line);
		std::cout << "-" << line.find_first_of('/') << std::endl;
		if(line.find_first_of('/') == 0){
			directories.push_back(line);
		}
	}
	std::cout << "over 30m:\n";
	int totalSub100k = 70000000;
	for(int i = 0; i < directories.size(); i++){
//	for(int i = 0; i < 1; i++){
		infile.clear();
		infile.seekg(0);
		unsigned long int dirTotal = 0;
		while(!infile.eof()){
			getline(infile,line);
			if(line.find(directories[i]) == 0){
				getline(infile,line);
				dirTotal += stoul(line);
			}
		}
		if(dirTotal >= 7442399){
			if(dirTotal < totalSub100k){
				totalSub100k = dirTotal;
			}
			
			std::cout << directories[i] << " | " << dirTotal << std::endl;
		}
		

	}
	std::cout << std::endl << totalSub100k << std::endl;
}

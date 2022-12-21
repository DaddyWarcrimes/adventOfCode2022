#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

bool fromLeft(int map[99][99], int Y, int X){
	if(X == 0){
		return true;
	}
	for(int i = 0; i < X; i++){
		if(map[Y][i] >= map[Y][X]){
			return false;
		}
		else{
			continue;
		}	
	}
	return true;
}

bool fromRight(int map[99][99], int Y, int X){
	if(X == 98){
		return true;
	}
	for(int i = 98; i > X; i--){
		if(map[Y][i] >= map[Y][X]){
			return false;
		}
		else{
			continue;
		}
	}
	return true;
}

bool fromTop(int map[99][99], int Y, int X){
	if(Y == 0){
		return true;
	}
	for(int i = 0; i < Y; i++){
		if(map[i][X] >= map[Y][X]){
			return false;
		}
		else{
			continue;
		}
	}
	return true;
}

bool fromBottom(int map[99][99], int Y, int X){
	if(Y == 98){
		return true;
	}
	for(int i = 98; i > Y; i --){
		if(map[i][X] >= map[Y][X]){
			return false;
		}
		else{
			continue;
		}
	}
	return true;
}

bool isVisible(int map[99][99], int Y, int X){
	return fromRight(map, Y, X) || fromLeft(map, Y, X) || fromTop(map, Y, X) || fromBottom(map, Y, X);
}

int scenicScore(int map[99][99], int Y, int X){
	int L = 0;
	int R = 0;
	int T = 0;
	int B = 0;
	//Math shortcut
	if(X == 0 || Y == 0 || X == 98 || Y ==98){
		return 0;
	}
	//find L
	for(int i = X - 1; i >=0; i--){
		if(map[Y][i] >= map[Y][X] || i == 0){
			L = X - i;
		}
	}
	//find R
	for(int i = X + 1; i < 99; i ++){
		if(map[Y][i] >= map[Y][X] || i == 98){
			R = i - X;
		}
	}
	//find T
	for(int i = Y - 1; i >= 0; i--){
		if(map[i][X] >= map[Y][X] || i == 0){
			T = Y - i;
		}
	}
	//find B
	for(int i = Y + 1; i < 99; i++){
		if(map[i][X] >= map[Y][X]){
			B = i - X;
		}
	}
	return L * R * T * B;
}

int main(void){

	std::ifstream infile;
	infile.open("8.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	std::string line;

	int map[99][99];
	int mapY = 0;

	while(!infile.eof()){
		getline(infile,line);
		if(line.length() == 0){
			continue;
		}
		else{
			for(int i = 0; i < 99; i++){
				map[mapY][i] = line.at(i) - 48;	
			}
			
		}
		/*else{
			strcpy(map[mapY++],line.c_str());
		}*/
		mapY ++;
	}
	int visCount = 0;
	for(int i = 0; i < 99; i++){
		for(int j = 0; j < 99; j++){
			if(isVisible(map,i,j)){
				visCount++;
			}
		}
	}
	printf("%d\n",visCount);

	int maxVis = -1;
	for(int i = 0; i < 99; i++){
		for(int j = 0; j < 99; j++){
			int s = scenicScore(map,i,j);
			if(s > maxVis){
				maxVis = s;
			}
			
		}
		
	}
	printf("\n%d\n",maxVis);
}

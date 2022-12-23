#include <iostream>
#include <fstream>
#include <string>
#define MAXH 364
#define MAXV 322

void follow(int hY, int hX, int* tY, int* tX ){
	if(hY - *tY == 2){
		*tY = hY -1;
		*tX = hX;
	}
	if(hY - *tY == -2){
		*tY = hY + 1;
		*tX = hX;
	}
	if(hX - *tX == 2){
		*tX = hX -1;
		*tY = hY;
	}
	if(hX - *tX == -2){
		*tX = hX + 1;
		*tY = hY;
	}
	
	
}

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
	int hY = 220;
	int hX = 17;
	int tY = hY;
	int tX = hX;
	int maxH = 0;
	int minH = 0;
	int maxV = 0;
	int minV = 0;
	
	//initialize map;
	bool map[MAXH][MAXV];
	for(int i = 0; i < MAXH; i++){
		for(int j = 0; j < MAXV; j++){
			map[i][j] = false;
		}
	}
	

	while(!infile.eof()){
		getline(infile,line);
		if(line.length() < 3){
		continue;
		}
		char dir = line.at(0);
		int q = stoi(line.substr(2,line.length() ));
		switch(dir){
			case 'R':
				//hX += q;
				for(int i = 0; i < q; i++){
					hX += 1;
					follow(hY, hX, &tY, &tX);
					map[tY][tX] = true;
				}
				break;
			case 'L':
//				hX -=q;
				for(int i = 0; i < q; i++){
					hX -= 1;
					follow(hY, hX, &tY, &tX);
					map[tY][tX] = true;
				}
				break;
			case 'U':
//				hY -=q;
				for(int i = 0; i < q; i++){
					hY -= 1;
					follow(hY, hX, &tY, &tX);
					map[tY][tX] = true;
				}
				break;
			case 'D':
//				hY +=q;
				for(int i = 0; i < q; i++){
					hY += 1;
					follow(hY, hX, &tY, &tX);
					map[tY][tX] = true;
				}
				break;
			default:
				break;
		}
		std::cout << line << std::endl << " | " << hY << "," << hX << std::endl << " | " << tY << "," << tX << std::endl;
	}
	int visited = 0;
	for(int i = 0; i < MAXH; i++){
		for(int j = 0; j < MAXV; j++){
			if(map[i][j]){
				visited++;
			}
		}
	}
	printf("\n..........\n%d\n",visited);
}


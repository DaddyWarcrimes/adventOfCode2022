#include <iostream>
#include <fstream>
#include <string>
#define MAXH 364
#define MAXV 364

#define HBUFFER 25
#define VBUFFER 18
#define DELAY "sleep .1"

void follow(int hY, int hX, int* tY, int* tX ){
	if(hY - *tY >= 2){
		*tY = hY -1;
		*tX = hX;
	}
	if(hY - *tY <= -2){
		*tY = hY + 1;
		*tX = hX;
	}
	if(hX - *tX >= 2){
		*tX = hX -1;
		*tY = hY;
	}
	if(hX - *tX <= -2){
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
	int tY1 = hY;
	int tX1 = hX;
	
	int tY2 = hY;
	int tX2 = hX;
	int tY3 = hY;
	int tX3 = hX;
	int tY4 = hY;
	int tX4 = hX;
	int tY5 = hY;
	int tX5 = hX;
	int tY6 = hY;
	int tX6 = hX;
	int tY7 = hY;
	int tX7 = hX;
	int tY8 = hY;
	int tX8 = hX;
	int tY9 = hY;
	int tX9 = hX;

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
					follow(hY, hX, &tY1, &tX1);
					follow(tY1, tX1, &tY2, &tX2);
					follow(tY2, tX2, &tY3, &tX3);
					follow(tY3, tX3, &tY4, &tX4);
					follow(tY4, tX4, &tY5, &tX5);
					follow(tY5, tX5, &tY6, &tX6);
					follow(tY6, tX6, &tY7, &tX7);
					follow(tY7, tX7, &tY8, &tX8);
					follow(tY8, tX8, &tY9, &tX9);
					map[tY9][tX9] = true;
				}
				break;
			case 'L':
//				hX -=q;
				for(int i = 0; i < q; i++){
					hX -= 1;
					follow(hY, hX, &tY1, &tX1);
					follow(tY1, tX1, &tY2, &tX2);
					follow(tY2, tX2, &tY3, &tX3);
					follow(tY3, tX3, &tY4, &tX4);
					follow(tY4, tX4, &tY5, &tX5);
					follow(tY5, tX5, &tY6, &tX6);
					follow(tY6, tX6, &tY7, &tX7);
					follow(tY7, tX7, &tY8, &tX8);
					follow(tY8, tX8, &tY9, &tX9);
					map[tY9][tX9] = true;
				}
				break;
			case 'U':
//				hY -=q;
				for(int i = 0; i < q; i++){
					hY -= 1;
					follow(hY, hX, &tY1, &tX1);
					follow(tY1, tX1, &tY2, &tX2);
					follow(tY2, tX2, &tY3, &tX3);
					follow(tY3, tX3, &tY4, &tX4);
					follow(tY4, tX4, &tY5, &tX5);
					follow(tY5, tX5, &tY6, &tX6);
					follow(tY6, tX6, &tY7, &tX7);
					follow(tY7, tX7, &tY8, &tX8);
					follow(tY8, tX8, &tY9, &tX9);
					map[tY9][tX9] = true;
				}
				break;
			case 'D':
//				hY +=q;
				for(int i = 0; i < q; i++){
					hY += 1;
					follow(hY, hX, &tY1, &tX1);
					follow(tY1, tX1, &tY2, &tX2);
					follow(tY2, tX2, &tY3, &tX3);
					follow(tY3, tX3, &tY4, &tX4);
					follow(tY4, tX4, &tY5, &tX5);
					follow(tY5, tX5, &tY6, &tX6);
					follow(tY6, tX6, &tY7, &tX7);
					follow(tY7, tX7, &tY8, &tX8);
					follow(tY8, tX8, &tY9, &tX9);
					map[tY9][tX9] = true;
}
				break;
			default:
				break;
		}

		char display[MAXV][MAXH];
		for(int i = 0; i < MAXV; i++){
			for(int j = 0; j < MAXH; j++){
				display[i][j] = '.';
			}
		}
		display[tY9][tX9] = '9';
		display[tY8][tX8] = '8';
		display[tY7][tX7] = '7';
		display[tY6][tX6] = '6';
		display[tY5][tX5] = '5';
		display[tY4][tX4] = '4';
		display[tY3][tX3] = '3';
		display[tY2][tX2] = '2';
		display[tY1][tX1] = '1';
		display[hY][hX] = 'H';

		int starty = 0;
		if (hY > VBUFFER - 1){
			starty = hY - VBUFFER;
		}
		int endy = MAXV;
		if(hY + VBUFFER - 1 < MAXV){
			endy = hY + VBUFFER;
		}
		int startx = 0;
		if(hX > HBUFFER - 1){
			startx = hX - HBUFFER;
		}
		int endx = MAXH;
		if(hX + HBUFFER - 1 < MAXH){
			endx = hX + HBUFFER;
		}

		system("clear");
		for(int i = startx; i < endx; i++){
			printf("%d", i % 10);
			}
		printf("\n");

		for(int i = starty; i < endy; i++){
			for(int j = startx; j < endx; j++){
				printf("%c",display[i][j]);
			}
			printf(" %d\n",i);
		}
 
		std::cout << line << std::endl << " | " << hY << "," << hX << std::endl << " | " << tY9 << "," << tX9 << std::endl;
		system(DELAY);
	}
	int visited = 0;
	for(int i = 0; i < MAXH; i++){
		for(int j = 0; j < MAXV; j++){
			if(map[i][j]){
				visited++;
			}
		}
	}
/*	for(int i = 0; i < MAXH; i++){
		printf("%d",i % 10);
	}
	printf("\n\n");

	for(int i = 0; i < MAXV; i++){
		for(int j = 0; j < 226; j++){
			printf("%c",(int)map[i][j] + 32);
		}
		printf("\n");
	}*/
	printf("\n..........\n%d\n",visited);
}


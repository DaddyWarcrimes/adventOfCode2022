#include <iostream>
#include <fstream>
#include <string>

#define DEBUG
int roundScore(char enemy, char me){
	// A X rock
	// B Y paper
	// C Z scissors
	
	int win = 6;
	int lose = 0;
	int draw = 3;

	switch(enemy) {
		case 'A': //Rock
			switch(me) {
				case 'X': //Rock
					return draw + 1;
					break;
				case 'Y': //Paper
					return win + 2;
					break;
				case 'Z': //Scissors
					return lose + 3;
					break;
				default:
					return -1;
			}
		case 'B': //Paper
			switch(me) {
				case 'X': //Rock
					return lose + 1;
					break;
				case 'Y': //Paper
					return draw + 2;
					break;
				case 'Z': //Scisors
					return win + 3;
					break;
				default:
					return -1;
			}
		case 'C': //Scissors
			switch(me) {
				case 'X': //Rock
					return win + 1;
					break;
				case 'Y': //Paper
					return lose + 2;
					break;
				case 'Z': //Scisors
					return draw + 3;
					break;
				default:
					return -1;
			}
	
		default:
			return -1;
	}

}

int roundScore2(int enemy, int me){
	int score = ((int)me - 88) * 3;
	// A X rock
	// B Y paper
	// C Z scissors
	
	switch(enemy){
		case 'A': //Rock
			switch(me){
				case 'X': //lose, scissors
					return 3 + score;
					break;
				case 'Y': //draw, Rock
					return 1 + score;
					break;
				case 'Z': //win, paper
					return 2 + score;
				default:
					return -1;
			}
		case 'B': //paper
			switch(me){
				case 'X': //lose, rock
					return 1 + score;
					break;
				case 'Y': //draw, paper
					return 2 + score;
					break;
				case 'Z': //win, scissors
					return 3 + score;
				default:
					return -1;
			}
		case 'C': //scissors
			switch(me){
				case 'X': //lose, paper
					return 2 + score;
					break;
				case 'Y': //draw, scissors
					return 3 + score;
					break;
				case 'Z': //win, rock
					return 1 + score;
				default:
					return -1;
			}
		default:
			return -1;
	}
}

int main(void){
	std::ifstream infile;
	infile.open("2.txt");
	if(!infile){
		printf("failed to open\n");
	}
	else{
		printf("file opened\n");
	}
	const char* selections[3] = {"Rock", "Paper", "Scissor"};
	std::string line;
	int total = 0;
	int count = 0;
	//test
/*	for(char e = 'A'; e < 'D'; e++){
		for(char m = 'X'; m <= 'Z'; m++){
			printf("%c %c %d \n",e,m,roundScore2(e,m));
		}
	}*/
	
	while(!infile.eof()){
		getline(infile,line);
		if(line.length() < 3){
			continue;
		}
		total += roundScore2(line.c_str()[0], line.c_str()[2]);
		continue;
		printf("%s : ",line.c_str());
		printf("%s ", selections[line.c_str()[0] - 65]);
		printf("%s : ", selections[line.c_str()[2] - 88]);
		printf("%d : total ", roundScore2(line.c_str()[0], line.c_str()[2]));
		printf("%d : %d\n",total, ++count);
	}
	printf("Total: %d\n", total);
}


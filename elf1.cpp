#include "elf1.h"

elf::elf(){
return;
}

elf::~elf(){
	fruit.clear();
	return;
}

void elf::addFruit(int add){
	fruit.push_back(add);
	return;
}

void elf::clearAll(){
	fruit.clear();
	return;
}

int elf::total(){
	int ret = 0;
	for(int i = 0; i < fruit.size(); i++){
		ret += fruit[i];
	}
	return ret;
}
		

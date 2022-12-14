
#pragma once
#include <vector>

class elf{
	private:
		std::vector<int> fruit;
	public:
		elf();
		~elf();
		void addFruit(int add);
		int total();
		void clearAll();

};

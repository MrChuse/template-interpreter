#include "custom_interpreter.h"
#include <iostream>

int test_interpreter(std::vector<int> memory, std::vector<std::vector<int>> correct, int id) {
	std::cout << id << std::endl;
	Command<int> photosynthesis(0, true);
	Command<int> eat(1, true);
	Command<int> com10(10, true);

	std::vector<Command<int>> commands = { photosynthesis, eat, com10 };
	std::vector<int> data;

	Interpreter<int> brain(memory, commands, 64, 10);
	for (int i = 0; i < correct.size(); i++) {
		std::vector<int> ans = brain.make_a_move(data);

		bool f = false;
		for (int j = 0; j < ans.size(); j++) {
			if (correct[i][j] != ans[j]) {
				f = true;
				break;
			}
		}
		if (f) {
			std::cout << "move number " << i << " correct: ";
			for (int j = 0; j < correct[i].size(); j++)
				std::cout << correct[i][j] << " ";
			std::cout << ", but answer was ";
			for (int j = 0; j < ans.size(); j++)
				std::cout << ans[j] << std::endl;
			system("pause");
			return -1;
		}
	}
	return 0;
}

void test_case_interpreter() {
	std::cout << "interpreter tests started" << std::endl;

	std::vector<int> memory = { 0, 0, 0, 1, 10 };
	std::vector< std::vector<int> > correct = { { 0 },{ 0 },{ 0 },{ 1, 10 },{ 0 },{ 0 },{ 0 },{ 1, 10 } };
	test_interpreter(memory, correct, 1);

	memory = { 0 };
	correct = { { 0 },{ 0 },{ 0 },{ 0 } };
	test_interpreter(memory, correct, 2);

	memory = { 11, 0, 0, 1 };
	correct = { { 0 },{ 0 },{ 1, 11 },{ 0 },{ 0 },{ 1, 11 } };
	test_interpreter(memory, correct, 3);

	memory = { 2, 0 };
	correct = { { 2, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2 },{ 0 } };
	test_interpreter(memory, correct, 4);

	std::cout << "interpreter tests ended" << std::endl << std::endl;
}

void run_tests() {
	std::cout << "-------------------tests started-----------------------" << std::endl;

	test_case_interpreter();
}

int main() {
	run_tests();

	system("pause");
	return 0;
}

#include <future>
#include <functional>
#include <random>
#include <thread>

#include "binary_tree.h"
#include "array.h"
#include "figure.h"
#include "rectangle.h"

int main()
{
	TArray <Rectangle> arrRect;
	typedef std::function<void(void) > command;
	TBinaryTree <command> btrCmd;

	

	command cmdInsert = [&]() {
		std::cout << "Creating random array" << std::endl;
		std::default_random_engine generator(time(NULL));
		std::uniform_int_distribution<int> distribution(1, 20);
		for (int i = 0; i < 10; i++) {
			int side_a = distribution(generator);
			int side_b = distribution(generator);
			std::shared_ptr<Rectangle> ptr = std::make_shared<Rectangle>(side_a, side_b);
			int ind = distribution(generator);
			arrRect.ElementInsert(ptr, ind);
		}
	};

	command cmdPrint = [&]() {
		std::cout << "Printing array" << std::endl;
		arrRect.print();
	};

	command removeIfEqualN = [&]() {
		if (arrRect.Size()==0) {
			std::cout << "Array is empty" << std::endl;

		}
		else {
			size_t n;
			std::cout << "Enter N: ";
			std::cin >> n;
			arrRect.ElementDelete(n);
		}
	};

	btrCmd.push(std::shared_ptr<command>(&cmdInsert, [](command*){}));
	btrCmd.push(std::shared_ptr<command>(&cmdPrint, [](command*) {}));
	btrCmd.push(std::shared_ptr<command>(&removeIfEqualN, [](command*) {}));
	btrCmd.push(std::shared_ptr<command>(&cmdPrint, [](command*) {}));

	while (btrCmd.Size()>0) {
		std::shared_ptr<command> cmd = btrCmd.remove(0);
		std::future<void> ft = std::async(*cmd);
		ft.get();

	}
	system("pause");
    return 0;
}

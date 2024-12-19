#include "utils.h"
#include "algorithm.h"
#include "generator.h" 

std::vector<std::string> ALGORITHMS_NAME = {
	"selection-sort",
	"quick-sort",
	"insertion-sort",
	"bubble-sort",
	"heap-sort",
	"merge-sort",
	"radix-sort",
	"shaker-sort",
	"shell-sort",
	"counting-sort",
	"flash-sort"
};

int main(int argc, char* argv[]){
	if (argc == 5 || argc == 6) {
		// Run command line if multiple argument passed
		commandLine(argc, argv);
	}
	else {
		// Run testing case
		cout << "TESTING MODE\n";
		cout << "Available algorithms: \n";
		for (string name : ALGORITHMS_NAME) {
			cout << "----" << name << "\n";
		}
		cout << "\nEnter 'all' to test all algorithms: \n";
		cout << "Enter name of algorithm(Ex: selection-sort): ";
		string name; cin >> name;
		if (name == "all") {

			testAlgorithms(ALGORITHMS_NAME);
			cout << "Output of test: test_algorithms.csv";
		}
		else {
			cout << "Enter number of testcase(Ex: 5): ";
			int testcase = 0; cin >> testcase;
			testAlgorithm(name, testcase);
			cout << "Output of test: test_" << name << ".csv";
		}
	}
	return 0;
}



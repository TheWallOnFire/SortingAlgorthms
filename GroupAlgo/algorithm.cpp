#include "algorithm.h"
#include "generator.h"
#include "utils.h"


void getAlgorithm(const char* name, FuncPtr& algo)
{
	algo = NULL;
	if (strcmp(name, "selection-sort") == 0) {
		algo = selection_sort;
	}
	else if (strcmp(name, "quick-sort") == 0) {
		algo = quick_sort;
	}
	else if (strcmp(name, "insertion-sort") == 0) {
		algo = InsertionSort;
	}
	else if (strcmp(name, "bubble-sort") == 0) {
		algo = BubbleSort;
	}
	else if (strcmp(name, "heap-sort") == 0) {
		algo = HeapSort;
	}
	else if (strcmp(name, "merge-sort") == 0) {
		algo = MergeSort;
	}
	else if (strcmp(name, "radix-sort") == 0) {
		algo = RadixSort;
	}
}

void command1(const char* algorithm, const char* given_input, const char* output_parameter)
{
	// Get function pointer
	FuncPtr algo = NULL;
	getAlgorithm(algorithm, algo);
	if (!algo) {
		cout << "Can't find algorithm\n";
		return;
	}
	cout << "Algorithm: " << algorithm << endl; // Add name

	// Load file
	cout << "Input file: " << given_input << endl;
	int n = 0; int* arr = loadArr(n, given_input);
	if (!arr) {
		cout << "Can't create arr!\n";
		return;
	}
	cout << "Input size: " << n << endl;
	cout << "-----------------------------------------\n";

	// Running
	long long comp = 0;

	auto start = std::chrono::high_resolution_clock::now();
	algo(arr, n, comp);
	auto end = std::chrono::high_resolution_clock::now();

	// Calculate elapsed time
	auto timer = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	float time = (float)(timer.count()) / 1'000'000.0;

	// Output parameter
	if (strcmp(output_parameter,"-time") == 0 || strcmp(output_parameter,"-both") == 0) {
		cout << "Running time: " << time << " (second)\n";
	}
	if (strcmp(output_parameter,"_comp") == 0 || strcmp(output_parameter,"-both") == 0) {
		cout << "Comparisons : " << comp << " (time)\n";
	}

	// Save to file
	saveArr(arr, n, "output.txt");

	// Release
	delete[] arr;
}

void command2(const char* algorithm, const char* input_size,
	const char* input_order, const char* output_parameter)
{
	// Get function pointer
	FuncPtr algo = NULL;
	getAlgorithm(algorithm, algo);
	if (!algo) {
		cout << "Can't find algorithm\n";
		return;
	}
	cout << "Algorithm: " << algorithm << endl; // Add name

	// Generate Arr
	if (!canConvertToInt(input_size)) {
		cout << "Wrong input size!!!\n";
		return;
	}
	int n = stoi(input_size);
	cout << "Input size: " << n << endl;

	int order = getOrder(input_order);
	if (order == -1) {
		cout << "Wrong input other!!!\n";
		return;
	}
	cout << "Input order: " << getOrderName(order) << endl;

	int* arr = new int[n];
	GenerateData(arr, n, order);
	if (!arr) {
		cout << "Can't create arr!\n";
		return;
	}
	saveArr(arr, n, "output.txt");
	cout << "-----------------------------------------\n";

	// Running
	long long comp = 0;

	auto start = std::chrono::high_resolution_clock::now();
	algo(arr, n, comp);
	auto end = std::chrono::high_resolution_clock::now();

	// Calculate elapsed time
	auto timer = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	float time = (float)(timer.count()) / 1'000'000.0;

	// Output parameter
	if (strcmp(output_parameter, "-time") == 0 || strcmp(output_parameter, "-both") == 0) {
		cout << "Running time: " << time << " (second)\n";
	}
	if (strcmp(output_parameter, "_comp") == 0 || strcmp(output_parameter, "-both") == 0) {
		cout << "Comparisons : " << comp << " (time)\n";
	}

	// Save to file
	saveArr(arr, n, "output.txt");

	// Release
	delete[] arr;
}

void command3(const char* algorithm, const char* input_size, const char* output_parameter)
{
	// Get function pointer
	FuncPtr algo = NULL;
	getAlgorithm(algorithm, algo);
	if (!algo) {
		cout << "Can't find algorithm\n";
		return;
	}
	cout << "Algorithm: " << algorithm << endl; // Add name

	// Generate Arr
	if (!canConvertToInt(input_size)) {
		cout << "Wrong input size!!!\n";
		return;
	}
	int n = stoi(input_size);
	cout << "Input size: " << n << endl;

	for (int i = 0; i < n; i++) {
		cout << "Input order: " << getOrderName(i) << endl;
		int* arr = new int[n];
		GenerateData(arr, n, i);
		if (!arr) {
			cout << "Can't create arr!\n";
			return;
		}
		string file = string("input_") + to_string(i) + ".txt";
		saveArr(arr, n, file);
		cout << "-----------------------------------------\n";

		// Running
		long long comp = 0;

		auto start = std::chrono::high_resolution_clock::now();
		algo(arr, n, comp);
		auto end = std::chrono::high_resolution_clock::now();

		// Calculate elapsed time
		auto timer = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		float time = (float)(timer.count()) / 1'000'000.0;

		// Output parameter
		if (strcmp(output_parameter, "-time") == 0 || strcmp(output_parameter, "-both") == 0) {
			cout << "Running time: " << time << " (second)\n";
		}
		if (strcmp(output_parameter, "_comp") == 0 || strcmp(output_parameter, "-both") == 0) {
			cout << "Comparisons : " << comp << " (time)\n";
		}

		// Save to file
		saveArr(arr, n, "output.txt");

		// Release
		delete[] arr;
	}
}

void command4(const char* algorithm_1, const char* algorithm_2, const char* given_input)
{
	// Get function pointer
	FuncPtr algo1 = NULL;
	getAlgorithm(algorithm_1, algo1);
	if (!algo1) {
		cout << "Can't find algorithm 1\n";
		return;
	}
	FuncPtr algo2 = NULL;
	getAlgorithm(algorithm_2, algo2);
	if (!algo2) {
		cout << "Can't find algorithm 2\n";
		return;
	}

	cout << "Algorithm: " << algorithm_1 << "|" << algorithm_2 << endl; // Add name

	// Load file
	cout << "Input file: " << given_input << endl;
	int n = 0; int* arr = loadArr(n, given_input);
	if (!arr) {
		cout << "Can't create arr!\n";
		return;
	}
	cout << "Input size: " << n << endl;
	cout << "-----------------------------------------\n";

	// Running
	long long comp1 = 0, comp2 = 0;
	int* temp = duplicateArr(arr, n);

	// Create team arr
	auto start = std::chrono::high_resolution_clock::now();
	algo1(arr, n, comp1);
	auto end = std::chrono::high_resolution_clock::now();

	// Calculate elapsed time
	auto timer = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	float time1 = (float)(timer.count()) / 1'000'000.0;

	// Create team arr
	start = std::chrono::high_resolution_clock::now();
	algo2(temp, n, comp2);
	end = std::chrono::high_resolution_clock::now();

	// Calculate elapsed time
	timer = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	float time2 = (float)(timer.count()) / 1'000'000.0;

	// Output parameter
	cout << left << setw(15) << "Running time:" 
		 << right << setw(10) << time1 << " (second)" << " | " 
		 << right << setw(10) << time2 << " (second)\n";
	cout << left << setw(15) << "Comparisons:" 
		 << right << setw(10) << comp1 << " (time)"	 << " | " 
		 << right << setw(10) << comp2 << " (time)\n";

	// Save to file
	saveArr(arr, n, "output.txt");

	// Release
	delete[] arr;
	delete[] temp;
}

void command5(const char* algorithm_1, const char* algorithm_2,
	const char* input_size, const char* input_order)
{
	// Get function pointer
	FuncPtr algo1 = NULL;
	getAlgorithm(algorithm_1, algo1);
	if (!algo1) {
		cout << "Can't find algorithm 1\n";
		return;
	}
	FuncPtr algo2 = NULL;
	getAlgorithm(algorithm_2, algo2);
	if (!algo2) {
		cout << "Can't find algorithm 2\n";
		return;
	}

	cout << "Algorithm: " << algorithm_1 << "|" << algorithm_2 << endl; // Add name

	// Generate Arr
	if (!canConvertToInt(input_size)) {
		cout << "Wrong input size!!!\n";
		return;
	}
	int n = stoi(input_size);
	cout << "Input size: " << n << endl;

	int order = getOrder(input_order);
	if (order == -1) {
		cout << "Wrong input other!!!\n";
		return;
	}
	cout << "Input order: " << getOrderName(order) << endl;

	int* arr = new int[n];
	GenerateData(arr, n, order);
	if (!arr) {
		cout << "Can't create arr!\n";
		return;
	}
	saveArr(arr, n, "output.txt");
	cout << "-----------------------------------------\n";

	// Running
	long long comp1 = 0, comp2 = 0;
	int* temp = duplicateArr(arr, n);

	// Create team arr
	auto start = std::chrono::high_resolution_clock::now();
	algo1(arr, n, comp1);
	auto end = std::chrono::high_resolution_clock::now();

	// Calculate elapsed time
	auto timer = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	float time1 = (float)(timer.count()) / 1'000'000.0;

	// Create team arr
	start = std::chrono::high_resolution_clock::now();
	algo2(temp, n, comp2);
	end = std::chrono::high_resolution_clock::now();

	// Calculate elapsed time
	timer = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	float time2 = (float)(timer.count()) / 1'000'000.0;

	// Output parameter
	cout << left << setw(15) << "Running time:"
		<< right << setw(10) << time1 << " (second)" << " | "
		<< right << setw(10) << time2 << " (second)\n";
	cout << left << setw(15) << "Comparisons:"
		<< right << setw(10) << comp1 << " (time)" << " | "
		<< right << setw(10) << comp2 << " (time)\n";

	// Save to file
	saveArr(arr, n, "output.txt");

	// Release
	delete[] arr;
	delete[] temp;
}

void commandLine(int argc, char* argv[]) {
	// Conditional
	if (argv[1] == "-a") {
		cout << "ALGORITHM MODE\n";
		if (argc == 5) {
			if (!canConvertToInt(argv[3])) {
				// Command 1
				command1(argv[2], argv[3], argv[4]);
			}
			else {
				// Command 3
				command3(argv[2], argv[3], argv[4]);
			}
		}
		else if (argc == 6) {
			// Command 2
			command2(argv[2], argv[3], argv[4], argv[5]);
		}
		else
		{
			cout << "Too many argument!!!\n";
			return;
		}
	}
	else if (argv[1] == "-c") {
		cout << "COMPARE MODE\n";
		if (argc == 5) {
			// Command 4
			command4(argv[2], argv[3], argv[4]);
		}
		else if (argc == 6) {
			// Command 5
			command5(argv[2], argv[3], argv[4], argv[5]);
		}
		else
		{
			cout << "Too many argument!!!\n";
			return;
		}
	}
	else {
		cout << "Unknown command!!!\n";
		return;
	}
}

void testAlgorithm(const std::string name, int number){
	// Pass an array of pointers to functions
	// Save result to file test_result.csv
	const string filename = "test_" + name + ".csv";
	ofstream output; output.open(filename);
	if (!output.is_open()) {
		cout << "Failed to open test_result.csv\n";
		return;
	}

	// Create dataset for testing
	int data_order[] = { 0,1,2,3 };
	int data_size[] = { 10000, 30000, 50000, 100000, 300000, 500000 };
	FuncPtr algo = NULL; getAlgorithm(name.c_str(), algo);
	if (!algo) {
		cout << "Can't find algorithm name:" << name << endl;
		return;
	}
	// output << names of algorithms
	output << "Time running in seconds and the number of comparisons of algorithm in many cases:\n";
	output << "Algorithm: " << name << endl;
	output << "Order, Size,";
	for (int i = 0; i < number; i++) {
		output << "Test " << i + 1 << ",,";
	}
	output << "\n";
	// Loop for each dataset
	for (int order : data_order) {			// Data order
		// output << "-------------------------------------------------------\n";
		// output << "Dataset number : " << order << endl;

		// Rows: size of dataset
		for (int size : data_size) {			// Data size
			output << getOrderName(order) << "," << size << ",";

			for (int test = 0; test < number; test++) { // Number of testcase
				// Create an array with Data Order S1 and Data Size S2
				int* arr = new int[size]; // Create arr
				GenerateData(arr, size, order);
				// Take note of S1, S2, S3, running time and number of comparisons
				long long comp = 0; int tie = 0;
				// Sort the created array using the Sorting Algorithm S3

					// Record start time
				auto start = std::chrono::high_resolution_clock::now();

				// Call the function
				algo(arr, size, comp); // cout array inside algo

				// Record end time
				auto end = std::chrono::high_resolution_clock::now();

				// Calculate elapsed time
				auto timer = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
				float time = (float)(timer.count()) / 1'000'000.0;
				// Cout and save result
				cout << left << setw(15) << "Running time:" << setw(10) << time << "|" 
					 << left << setw(10) << "Comparisons: " << setw(10) << comp << endl;
				output << time << "," << comp << ",";

				delete[] arr;
			}
			output << "\n";
		}
	}
	output.close();
}




// Selection_sort
void selection_sort(int* arr, int n, long long& comp)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIndex] > arr[j])
				minIndex = j;
			comp++;
		}
		comp++;
		swap(arr[i], arr[minIndex]);
	}
}


// Quick sort
int partition_1(int* arr, int l, int r, long long& comps)
{
	int pivot = arr[r];// chọn chốt là phần tử cuối bên phải
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (arr[j] <= pivot)
		{
			++i;
			swap(arr[i], arr[j]);
		}

		comps++;
	}
	++i;
	swap(arr[i], arr[r]);//đưa chốt về giữa
	return i;// trả về vị trí của chốt
}

void quick_sort_1(int* arr, int l, int r, long long& comps)
{
	if (l >= r)
		return;
	int p = partition_1(arr, l, r, comps);
	quick_sort_1(arr, l, p - 1, comps);
	quick_sort_1(arr, p + 1, r, comps);
}// lam voi phan hoach lomuto

void quick_sort(int* arr, int n, long long& comps)
{
	quick_sort_1(arr, 0, n-1, comps);
}

// Insertion sort
void InsertionSort(int* arr, int n, long long& comp) {
	comp = 0;
	for (int i = 0; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			comp++;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		if (j >= 0) {
			comp++;
		}
		arr[j + 1] = key;
	}

}

// Bubble sort
void BubbleSort(int* arr, int n, long long& comp) {
	comp = 0;
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;

		for (int j = 0; j < n - i - 1; j++) {
			comp++;
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}

		}
		if (!swapped)
			break;
	}
}

// Heap sort
void Heapify(int* arr, int n, int i, long long& comp) {
	int max = i;         // Khởi tạo max là i
	int left = 2 * i + 1;    // Chỉ số con trái
	int right = 2 * i + 2;   // Chỉ số con phải

	// So sánh con trái
	if (left < n) {
		if (arr[left] > arr[max]) {
			comp++; // Đếm so sánh giữa arr[left] và arr[max]
			max = left;
		}
	}

	// So sánh con phải
	if (right < n) {
		if (arr[right] > arr[max]) {
			comp++; // Đếm so sánh giữa arr[right] và arr[max]
			max = right;
		}
	}

	if (max != i) {
		swap(arr[i], arr[max]);
		Heapify(arr, n, max, comp); // Đệ quy tiếp tục
	}
}

void HeapSort(int* arr, int n, long long& comp) {
	// Xây dựng Max Heap từ mảng
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(arr, n, i, comp);
	}

	// Tiến hành sắp xếp
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);//Thằng lớn nhất mảng sẽ luôn là a[0]
		Heapify(arr, i, 0, comp);  // Duy trì Max Heap sau khi swap
	}
}

// Merge Sort
void Merge(int* a, int left, int mid, int right, long long& comp) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = a[mid + 1 + j];
	}
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		comp++;
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

void MergeSort(int* a, int left, int right, long long& comp) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	MergeSort(a, left, mid, comp);
	MergeSort(a, mid + 1, right, comp);
	Merge(a, left, mid, right, comp);
}

void MergeSort(int* a, int n, long long& comp) {
	MergeSort(a, 0, n-1, comp);
}


// Counting sort function to sort based on a specific digit
void countingSort(int* arr, int n, int exp, long long& comp) {
	int* output = new int[n];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++, comp++)
		count[(arr[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++, comp++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--, comp++) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++, comp++)
		arr[i] = output[i];

	delete[] output;
}

void RadixSort(int* arr, int n, long long& comp) {
	comp = 0;

	// Find max value
	int max = 0;
	for (int i = 0; i < n; i++, comp++) {
		if (max < arr[i]) max = arr[i];
		comp++;
	}

	// Loop for each char
	for (int exp = 1; max / exp > 0; exp *= 10, comp++) {
		countingSort(arr, n, exp, comp);
	}
}
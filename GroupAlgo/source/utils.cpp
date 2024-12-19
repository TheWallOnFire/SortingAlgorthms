#include "utils.h"
#include "utils.h"

int* loadArr(int& n, string file)
{
    // Load file
    ifstream input;
    input.open(file);
    if (!input.is_open()) return NULL;
    input >> n; // Number of arr

    // Create arr
    int* arr = new int[n];
    if (!arr) return NULL;

    // Load arr
    for (int i = 0; i < n; i++) {
        input >> arr[i];
    }

    return arr;
}

void saveArr(int* arr, int n, const string& file)
{
    if (!arr) return;

    // File stream
    ofstream output;
    output.open(file);
    if (!output.is_open()) return;

    // Save arr
    output << n << endl;
    for (int i = 0; i < n; i++) {
        output << arr[i] << " ";
    }

    return;
}

bool canConvertToInt(const char* text) {
    if (text == nullptr || *text == '\0') {
        return false; // Null or empty string cannot be converted
    }

    char* endPtr = nullptr;
    long value = std::strtol(text, &endPtr, 10); // Convert to long, base 10

    // Check if the entire string was parsed and the value fits in int range
    if (*endPtr != '\0') {
        return false; // Non-numeric characters found
    }

    if (value < INT_MIN || value > INT_MAX) {
        return false; // Out of int range
    }

    return true;
}

int getOrder(const char* order) {
    if (strcmp("-rand",order) == 0)
        return 0;
    if (strcmp("-nsorted", order) == 0)
        return 1;
    if (strcmp("-sorted", order) == 0)
        return 2;
    if (strcmp("-rev", order) == 0)
        return 3;
    return -1;
}
const char* getOrderName(int order) {
    if (order == 0)
        return "Randomize";
    if (order == 1)
        return "Nearly Sorted";
    if (order == 2)
        return "Sorted";
    if (order == 3)
        return "Reversed";
    return "Unknown";
}

int* duplicateArr(int* arr, int n) {
    int* temp = new int[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    return temp;
}
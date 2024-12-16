#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <string>
#include <vector>
using namespace std;

int* loadArr(int& n, std::string file);
void saveArr(int* arr, int n, const string& file);
bool canConvertToInt(const char* text);
int getOrder(const char* order);
const char* getOrderName(int order);
int* duplicateArr(int* arr, int n);


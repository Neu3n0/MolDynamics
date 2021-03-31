#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <chrono>
#include <assert.h>
#pragma warning (disable : 4996)
////////////////////Memory Leaks/////////////////////////
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
/////////////////////////////////////////////////////////

using namespace std;
using namespace std::chrono;

const int MAX_MOLS = 100000;
const int MAX_ATOMS_IN_CELL = 10;
const int MAX_CELLS = 30;
const double K_b = 0.00138;						//Boltzmann's constant
const double A = 61625.553346;					//A = 12 * pow(SIGMA, 12) * EPS;
const double B = 89.788794;						//B = 12 * pow(SIGMA, 6) * EPS;
const double AA = 5135.462778;					//AA = pow(SIGMA, 12) * EPS;
const double BB = 14.964799;					//BB = 2 * pow(SIGMA, 6) * EPS;



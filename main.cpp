#include "md.h"

int main() {
	Space* space = new Space;
	int amount_steps;
	std::cin >> amount_steps;
	Print_config(*space, amount_steps);

	space->Init_molecules();

	Print_atoms(*space);
	Print_mol(*space);

	auto start = steady_clock::now();
	for (int step = 0; step < amount_steps; ++step) {
		std::cout << step << std::endl;
		space->MDStep();
		if ((step % 100 == 0)) {
			WriteVTK(space);
		}
	}
	auto finish = steady_clock::now();
	std::cout << "Program calculation time: " << duration_cast<milliseconds>(finish - start).count() << " ms\n";

	delete space;
	_CrtDumpMemoryLeaks();
	return 0;
}
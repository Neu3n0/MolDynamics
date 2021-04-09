#include "md.h"

int main() {
	Space* space = new Space;
	int amount_steps;
	std::cin >> amount_steps;
	Print_config(*space, amount_steps);

	space->Init_molecules();

	Print_atoms(*space);
	Print_mol(*space);

	std::ofstream fouten;
	fouten.open("C:\\Drive\\Code\\MolDynamics\\md_v1.0\\Output\\get_energy.txt", std::ios::app);

	auto start = steady_clock::now();
	for (int step = 0; step < amount_steps; ++step) {
		std::cout << step << std::endl;
		space->MDStep();
		Get_energy(fouten, *space);
		if ((step % 100 == 0)) {
			WriteVTK(space);
		}
	}
	auto finish = steady_clock::now();
	std::cout << "Program calculation time: " << duration_cast<milliseconds>(finish - start).count() << " ms\n";

	fouten.close();
	delete space;
	_CrtDumpMemoryLeaks();
	return 0;
}
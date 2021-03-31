#include "header.h"

class Atom;
class Molecule_N2;
class Space;
class Cell;

class Atom {
public:
	double coord[3];
	double vel[3];
	double power[3];
	double LJ_potential;
	void Coord_shift(Space* space);		//Coordinates shift
	void Power_shift(Atom* mol_prob, const double* shift);		//Power shift
	void Veloc_shift(Space* space);		//Velocitie shift
	int Change_Cell(Space* space, int i0, int j0, int k0, int l);		//Change cell
};

class Molecule_N2 {
public:
	Atom* atom[2];
	double KX_power[3];
};

class Cell {
public:
	Cell() : amount_atoms(0), atom_N() {}
	~Cell() {
		while (amount_atoms) {
			delete atom_N[amount_atoms - 1];
			--amount_atoms;
		}
	}
	Atom* atom_N[MAX_ATOMS_IN_CELL];
	int amount_atoms;
};

class Space {
public:
	Space();
	double spacesize, cellsize, T, p, dt;
	int total_mol, amount_cells;
	double m_N;
	Cell cells[MAX_CELLS][MAX_CELLS][MAX_CELLS];
	Molecule_N2 N_2[MAX_MOLS];
	void Init_molecules();		//Initialize molecules
	void MDStep();
};

void Print_config(const Space& space, const int& amount_steps);		//Print surface parameters
void Print_atoms(const Space& space);		//Print atoms
void Print_mol(const Space& space);			//Print molec
double LJ_F(const double& r);		//Lennard jones power
double LJ_P(const double& r);		//Lennard jones potential
void SetNullMacro(Space* space);		//Set null macro
int WriteVTK(Space* space);		//VTK
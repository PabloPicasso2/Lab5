#include "gen/gen.hpp"
#include "loop/loop.hpp"
#include "square/square.hpp"
#include "sinus/sinus.hpp"
#include "triangle/triangle.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

int main()
{
	// create LEAFs
	//Comp_Loop

	// create generator
    Comp_Gen *generator = new Comp_Concrete(1.0);
	// generator parameters
    //double period1 = 12.0, amplitude1 = 1.0;
	// input generator
    //Comp_Gen *generator1 = new Dec_square(generator, amplitude1, period1);
	//std::cout << "basic input = " << generator->simulate() << "\n";
	//std::cout << "input with generator = " << generator1->simulate() << "\n";

	//


	// create COMPOSITEs



	// create 

    delete generator;
    //delete generator1;
    std::cin.get();
}

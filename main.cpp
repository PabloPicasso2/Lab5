/**
 * @file main.cpp
 * @author Pawel Smieja
 * @brief program for testing generator decorator - sinus, square and triangle. You can decorate basic input by these decorators separately or by superimpose
 * @version 0.1
 * @date 2023-05-31
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "loop/loop.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	// create LEAFs

    // create COMPOSITEs




    // create basic input
    Comp_Gen *generator = new Comp_Concrete(2.0);
    // parameters for decorators
    double period1 = 12.0, amplitude1 = 1.0;
    // decorating by square
    Comp_Gen *generator1 = new Dec_square(generator, amplitude1, period1);



    // get memory back
    delete generator;
    delete generator1;

    std::cin.get();
}
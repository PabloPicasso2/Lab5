/**
 * @file loop.hpp
 * @author Pawel Smieja
 * @brief class of component of the loop control
 * @version 0.1
 * @date 2023-06-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef COMPON_LOOP_H
#define COMPON_LOOP_H

#include <algorithm>
#include <iostream>
#include "../gen/gen.hpp"
#include "../square/square.hpp"
#include "../sinus/sinus.hpp"
#include "../triangle/triangle.hpp"
#include "../siso/siso.hpp"
#include "../leaf_arx/leaf_arx.hpp"
#include "../leaf_pi/leaf_pi.hpp"
#include "../leaf_pd/leaf_pd.hpp"
#include "../leaf_pid/leaf_pid.hpp"

/**
 * The base Component class declares common operations for composites and leafs
 */
class Compon_Loop
{
public:
	virtual ~Compon_Loop() = default;
	virtual void Add(Compon_Loop *component) = 0;
	virtual void Remove(Compon_Loop *component) = 0;

	// get output of the component/leaf
	virtual double simulate(double x) = 0;

	// for component, where leafs are in series
	// virtual double simulate_series(double x) = 0;
	// for component, where leafs are in pararell
	// virtual double simulate_pararell(double x) = 0;
};

#endif

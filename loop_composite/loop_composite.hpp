/**
 * @file loop_composite.hpp
 * @author Pawel Smieja
 * @brief 
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOOP_COMPOSITE_H
#define LOOP_COMPOSITE_H

#include "../compon_loop/compon_loop.hpp"
#include <vector>

/**
 * The Composite class represents the complex components that may have children.
 * Usually, the Composite objects delegate the actual work to their children and
 * then "sum-up" the result.
 */
class Composite_Loop : public Compon_Loop
{
public:
	// add new component
	void Add(Compon_Loop *component) override { m_children.push_back(component); }
	// remove component
	void Remove(Compon_Loop *component) override { m_children.remove(component); }
	// get output of the component
	double simulate(double x) override;

protected:
	// Object storage
	std::vector<Compon_Loop> m_children;
};

#endif
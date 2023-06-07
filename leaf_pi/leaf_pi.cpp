/**
 * @file leaf_pi.cpp
 * @author Pawel Smieja
 * @brief 
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "leaf_pi.hpp"
#include <cmath>

/**
 * @brief Construct a new Leaf_PI::Leaf_PI object
 * 
 * @param min minimum controller output
 * @param max maximum controller output
 * @param dt time step
 * @param kp proportional coef
 * @param ki integral coef
 */
Leaf_PI::Leaf_PI(double min, double max, double dt, double kp, double ki)
{
    m_dt = dt;
    m_Kp = kp;
    m_Ki = ki;
    m_min = min;
    m_max = max;
    // sum of previous and current integrals
    integral_temp = 0.0;
}

// calculate error
double Leaf_PI::calc_error(double pv, double set_point)
{
    double error = set_point - pv;
    return error;
}

// calculate proportional term
double Leaf_PI::calc_prop(double error)
{
    double prop = m_Kp * error;
    return prop;
}

// calculate integral term
double Leaf_PI::calc_integr(double error)
{
    // calculate sum of previous and current integrals
    integral_temp += error * m_dt;
    // calculate integral term
    double integr = m_Ki * integral_temp;
    return integr;
}

// update setpoint
void Leaf_PI::set_setPoint(double sp)
{
    set_point = sp;
}

double Leaf_PI::simulate(double pv)
{
    // Calculate controller output
    double error = calc_error(pv, set_point);
    double prop = calc_prop(error);
    double integr = calc_integr(error);
    double output = prop + integr;

    // Restrict to max/min
    if (output > m_max)
        output = m_max;
    else if (output < m_min)
        output = m_min;

    return output;
}

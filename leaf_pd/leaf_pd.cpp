/**
 * @file Leaf_PD.cpp
 * @author Pawel Smieja
 * @brief 
 * @version 0.1
 * @date 2023-05-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "leaf_pd.hpp"
#include <cmath>

/**
 * @brief Construct a new Leaf_PD::Leaf_PD object
 *
 * @param min minimum controller output
 * @param max maximum controller output
 * @param dt time step
 * @param kp proportional coef
 * @param kd derivative coef
 */
Leaf_PD::Leaf_PD(double min, double max, double dt, double kp, double kd)
{
    m_dt = dt;
    m_Kp = kp;
    m_Kd = kd;
    m_min = min;
    m_max = max;
    // previous error
    prev_error = 0.0;
}

// calculate error
double Leaf_PD::calc_error(double pv, double set_point)
{
    double error = set_point - pv;
    return error;
}

// calculate proportional term
double Leaf_PD::calc_prop(double error)
{
    double prop = m_Kp * error;
    return prop;
}

// calculate derivative term
double Leaf_PD::calc_deriv(double error)
{
    double deriv = m_Kd * ((error - prev_error) / m_dt);
    // Save error to previous error
    prev_error = error;

    return deriv;
}

// uLeaf_PDate setpoint
void Leaf_PD::set_setPoint(double sp)
{
    set_point = sp;
}

// calculate controller output
double Leaf_PD::simulate(double pv)
{
    double error = calc_error(pv, set_point);
    double prop = calc_prop(error);
    double deriv = calc_deriv(error);
    double output = prop + deriv;

    // Restrict to max/min
    if (output > m_max)
        output = m_max;
    else if (output < m_min)
        output = m_min;

    return output;
}
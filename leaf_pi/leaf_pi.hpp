/**
 * @file leaf_pi.hpp
 * @author Pawel Smieja
 * @brief
 * @version 0.1
 * @date 2023-06-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef LEAF_PI_H
#define LEAF_PI_H

#include "../siso/siso.hpp"

/**
 * @brief
 *
 */
class Leaf_PI : virtual public SISO, public Compon_Loop
{
public:
    Leaf_PI(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double ki = 0.5);
    ~Leaf_PI() = default;

    virtual double simulate(double pv) override;

    virtual double calc_error(double pv, double set_point);
    virtual double calc_prop(double error);
    virtual double calc_integr(double error);
    virtual void set_setPoint(double sp);

private:
    double set_point, m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp;
};

#endif

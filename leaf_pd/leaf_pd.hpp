#ifndef LEAF_PD_H
#define LEAF_PD_H

#include "../siso/siso.hpp"

/**
 * @brief 
 * 
 */
class Leaf_PD : virtual public SISO, public Compon_Loop
{
public:
    Leaf_PD(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double kd = 0.05);
    ~Leaf_PD() = default;

    virtual double simulate(double pv) override;

    virtual double calc_error(double pv, double set_point);
    virtual double calc_prop(double error);
    virtual double calc_deriv(double error);
    virtual void set_setPoint(double sp);

private:
    double set_point, m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif
/**
 * @file leaf_pid.hpp
 * @author Pawel Smieja
 * @brief
 * @version 0.1
 * @date 2023-06-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef LEAF_PID_H
#define LEAF_PID_H

#include "../leaf_pd/leaf_pd.hpp"
#include "../leaf_pi/leaf_pi.hpp"

class Leaf_PID : public Leaf_PD, public Leaf_PI, public Compon_Loop
{
public:
    PID(double min = 0.0, double max = 100.0, double dt = 0.1, double kp = 1.0, double ki = 0.5, double kd = 0.05);
    ~PID() = default;

    double calc_error(double pv, double set_point) override;
    double calc_prop(double error) override;
    double calc_integr(double error) override;
    double calc_deriv(double error) override;
    void set_setPoint(double sp) override;
    double simulate(double pv) override;

private:
    double set_point, m_min, m_max, m_dt, m_Kp, m_Ki, m_Kd, integral_temp, prev_error;
};

#endif

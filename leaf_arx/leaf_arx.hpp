/**
 * @file leaf_arx.hpp
 * @author Pawel Smieja
 * @brief 
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LEAF_ARX_H
#define LEAF_ARX_H

#include "../loop/loop.hpp"
#include "../siso/siso.hpp"
#include <vector>
#include <deque>
#include <string>

/**
 * @brief 
 * 
 */
class Leaf_ARX : public SISO, public Compon_Loop
{
public:
    using vector = std::vector<double>;
    using state = std::deque<double>;

    /**
     * @brief Construct a new ARX object
     *
     * @param a
     * @param b
     * @param k
     * @param evar
     */
    Leaf_ARX(const vector &a, const vector &b, unsigned k = 0, double evar = 0.0);
    ~Leaf_ARX() = default;

    double simulate(double x) override;
    void save(const std::string &path);

private:
    vector m_a, m_b;
    state m_x, m_y;
    double m_evar;
    unsigned m_k, m_x_depth, m_y_depth;

    void create_states();
    void update_state(state &state, double new_state);
};

#endif

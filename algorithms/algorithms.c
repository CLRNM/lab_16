//
// Created by User.
//


#include "algorithms.h"


void swap_min_max_rows(matrix* m) {
    position mx = get_max_value_pos(*m);
    position mn = get_min_value_pos(*m);

    swap_rows(m, mx.row_index, mn.row_index);
}
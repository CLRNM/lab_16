//
// Created by User.
//


#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"




// 1
void swap_min_max_rows(matrix* m) {
    position mx = get_max_value_pos(*m);
    position mn = get_min_value_pos(*m);

    swap_rows(m, mx.row_index, mn.row_index);
}


// 2
int get_max_(const int a[],const int n) {
    int max = a[0];

    for (size_t i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}


void sort_rows_by_max_element(matrix* m) {
    insertion_sort_rows_matrix_by_row_criteria(m, get_max_);
}
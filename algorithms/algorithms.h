//
// Created by User.
//

#ifndef LAB_16_ALGORITHMS_H
#define LAB_16_ALGORITHMS_H

#include "../data_structures/matrix/matrix.h"


void swap_min_max_rows(matrix* m);


void sort_rows_by_max_element(matrix* m);


void sort_cols_by_min_element(matrix* m);

matrix mul_matrices(matrix m1, matrix m2);

void get_square_of_matrix_if_symmetric(matrix* m);

#endif //LAB_16_ALGORITHMS_H
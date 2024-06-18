#include <stdio.h>
#include <assert.h>

#include "data_structures/matrix/matrix.h"
#include "algorithms/algorithms.h"



void test_swap_min_max_rows_1_standard_swap() {
    matrix m = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = create_matrix_from_array((int[]) {7, 8, 9,
                                                     4, 5, 6,
                                                     1, 2, 3},3, 3);

    swap_min_max_rows(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}


void test_swap_min_max_rows_2_min_and_max_element_equal() {
    matrix m = create_matrix_from_array((int[]) {1, 1, 1,
                                                 1, 1, 1,
                                                 1, 1, 1}, 3, 3);

    matrix check = create_matrix_from_array((int[]) {1, 1, 1,
                                                     1, 1, 1,
                                                     1, 1, 1},3, 3);

    swap_min_max_rows(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}


void test_swap_min_max_rows_3_min_and_max_element_in_one_row() {
    matrix m = create_matrix_from_array((int[]) {1, 1, 9,
                                                 1, 1, 1,
                                                 1, 1, 1}, 3, 3);

    matrix check = create_matrix_from_array((int[]) {1, 1, 9,
                                                     1, 1, 1,
                                                     1, 1, 1},3, 3);

    swap_min_max_rows(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}


void test_swap_min_max_rows() {
    test_swap_min_max_rows_1_standard_swap();
    test_swap_min_max_rows_2_min_and_max_element_equal();
    test_swap_min_max_rows_3_min_and_max_element_in_one_row();
}


int main() {
    test_swap_min_max_rows();


    return 0;
}
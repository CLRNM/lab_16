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


// 3
int get_min_(const int a[],const int n) {
    int min = a[0];


    for (size_t i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}


void sort_cols_by_min_element(matrix* m) {
    selection_sort_cols_matrix_by_col_criteria(m, get_min_);
}


// 4
static int get_sum_mul_array_(const int a[], const int b[], const int n) {
    int res = 0;

    for (int i = 0; i < n; i++)
        res += a[i] * b[i];

    return res;
}


static int* get_column(matrix* m, int j) {
    int* res = (int*) malloc(sizeof(int) * m->n_cols);

    for (int i = 0; i < m->n_rows; i++)
        res[i] = m->values[i][j];

    return res;
}


matrix mul_matrices(matrix m1, matrix m2) {
    if (m1.n_cols != m2.n_rows) {
        fprintf(stderr, "Different dimensions of the matrices");
        exit(1);
    }

    matrix res = get_mem_matrix(m1.n_rows, m2.n_rows);
    for (int i = 0; i < m1.n_rows; i++) {
        for (int j = 0; j < m2.n_rows; j++) {
            int* j_cols = get_column(&m2, j);
            int value = get_sum_mul_array_(m1.values[i], j_cols, m1.n_cols);
            res.values[i][j] = value;
        }
    }

    return res;
}


void get_square_of_matrix_if_symmetric(matrix* m) {
    if (!is_symmetric_matrix(m))
        return;

    matrix res = mul_matrices(*m, *m);

    free_mem_matrix(m);

    m->values = res.values;
    m->n_rows = res.n_rows;
    m->n_cols = res.n_cols;
}
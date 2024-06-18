//
// Created by User.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
            free(j_cols);
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


// 5
bool is_unique(long long int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;

    return true;
}


long long int get_sum(int a[], int n) {
    long long int res = 0;

    for (int i = 0; i < n; i++)
        res += a[i];

    return res;
}


void transpose_if_matrix_has_not_equal_sum_of_rows(matrix* m) {
    long long int sum[m->n_rows];

    for (int i = 0; i < m->n_rows; i++)
        sum[i] = get_sum(m->values[i], m->n_cols);

    if (is_unique(sum, m->n_rows))
        transpose_square_matrix(m);
}


// 6
bool is_mutually_inverse_matrices(matrix m1, matrix m2) {
    matrix multi = mul_matrices(m1, m2);

    bool is_e_matrix = is_E_matrix(&multi);

    free_mem_matrix(&multi);

    return is_e_matrix;
}


// 7


// 8
bool value_in_area(position max, int i, int j) {
    position new_position = {i - max.row_index, j - max.col_index};

    return (new_position.row_index <= new_position.col_index) && (new_position.row_index <= -new_position.col_index);
}


int get_min_in_area(matrix m) {
    position max = get_max_value_pos(m);

    int min = (int) 1e18;

    for (int i = 0; i <= max.row_index; i++)
        for (int j = 0; j < m.n_cols; j++)
            if (value_in_area(max, i, j) && m.values[i][j] < min)
                min = m.values[i][j];

    return min;
}


// 9
float get_distance(int a[], int n) {
    long long int square_sum = 0;

    for (int i = 0; i < n; i++)
        square_sum += a[i] * a[i];

    return sqrt(square_sum);
}


void insertion_sort_rows_matrix_by_row_criteria_F(matrix* m, float (*criteria)(int*, int)) {
    float res_criteria[m->n_rows];

    for (size_t i = 0; i < m->n_rows; i++)
        res_criteria[i] = criteria(m->values[i], m->n_cols);

    int i, j;
    float key;
    int* address_key;
    for (i = 1; i < m->n_rows; i++) {
        key = res_criteria[i];
        address_key = m->values[i];
        j = i - 1;

        while (j >= 0 && res_criteria[j] > key) {
            res_criteria[j + 1] = res_criteria[j];
            swap_rows(m, j + 1, j);

            j -= 1;
        }

        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}


void sort_by_distance(matrix* m) {
    insertion_sort_rows_matrix_by_row_criteria_F(m, get_distance);
}


// 10
int cmp_long_long(const void* pa, const void* pb) {
    return (int)(*(long long int*) pa - *(long long int*) pb);
}


int count_n_unique(long long int a[], int n) {
    int amount = 1;

    int i = 0;
    while (i < n - 1) {
        if (a[i] != a[i + 1])
            amount++;

        i++;
    }

    return amount;
}


int count_eq_classes_by_rows_sum(matrix m) {
    long long int values[m.n_rows];

    for (int i = 0; i < m.n_rows; i++)
        values[i] = get_sum(m.values[i], m.n_cols);

    qsort(values, m.n_rows, sizeof(long long int), cmp_long_long);


    for (size_t i = 0; i < m.n_rows; i++)
        printf("%lld ", values[i]);
    printf("\n");

    int result = count_n_unique(values, m.n_rows);

    return result;
}


// 11
int get_n_special_element(matrix m) {
    int amount = 0;

    for (int i = 0; i < m.n_cols; i++) {
        int sum = m.values[0][i];
        int max_values = m.values[0][i];

        for (int j = 1; j < m.n_rows; j++) {
            sum += m.values[j][i];

            if (m.values[j][i] > max_values)
                max_values = m.values[j][i];
        }

        if (max_values > (sum - max_values))
            amount++;
    }

    return amount;
}


// 12
position get_left_min(matrix m) {
    transpose_square_matrix(&m);

    position min = get_min_value_pos(m);

    return min;
}


void swap_penultimate_row(matrix* m, int n) {
    if (m->n_rows < 2)
        return;

    int* temp = (int*) malloc(sizeof(int) * m->n_rows);
    for (int i = 0; i < m->n_rows; i++)
        temp[i] = m->values[i][n];

    for (int i = 0; i < m->n_cols; i++)
        m->values[m->n_rows - 2][i] = temp[i];

    free(temp);
}
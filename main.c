#include <stdio.h>

#include "data_structures/matrix/matrix.h"
#include "algorithms/algorithms.h"


int main() {
    matrix m1 = create_matrix_from_array((int[]) {3, -5,
                                                  1, -2}, 2, 2);


    matrix m2 = create_matrix_from_array((int[]) {2, -5,
                                                  1, -3}, 2, 2);

    matrix res = mul_matrices(m1, m2);

    output_matrix(&res);

    printf("%d", is_mutually_inverse_matrices(m1, m2));

    return 0;
}
#include <stdio.h>

#include "data_structures/matrix/matrix.h"
#include "algorithms/algorithms.h"


int main() {
    matrix a = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 1}, 3, 3);

    position min_left = get_min_value_pos(a);

    swap_penultimate_row(&a, min_left.col_index);

    output_matrix(&a);

    return 0;
}
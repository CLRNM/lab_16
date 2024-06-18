#include <stdio.h>

#include "data_structures/matrix/matrix.h"
#include "algorithms/algorithms.h"


int main() {
    matrix a = create_matrix_from_array((int[]) {7, 1,
                                                 2, 7,
                                                 5, 4,
                                                 4, 3,
                                                 1, 6,
                                                 8, 0}, 6, 2);

    int v = count_eq_classes_by_rows_sum(a);

    printf("%d", v);

    return 0;
}
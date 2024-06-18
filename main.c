#include <stdio.h>

#include "data_structures/matrix/matrix.h"
#include "algorithms/algorithms.h"


int main() {
    matrix a = create_matrix_from_array((int[]) {3, 5, 5, 4,
                                                 2, 3, 6, 7,
                                                 12, 2, 1, 2}, 3, 4);

    int v = get_n_special_element(a);

    printf("%d", v);

    return 0;
}
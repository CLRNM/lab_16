#include <stdio.h>

#include "data_structures/matrix/matrix.h"
#include "algorithms/algorithms.h"


int main() {
    matrix a = create_matrix_from_array((int[]) {2, 3, 5, 5, 4,
                                                 6, 2, 3, 8, 12,
                                                 12, 12, 2, 1, 2}, 3, 5);



    printf("%d", get_n_special_element_2(a));

    return 0;
}
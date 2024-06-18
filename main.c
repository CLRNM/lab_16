#include <stdio.h>

#include "data_structures/matrix/matrix.h"
#include "algorithms/algorithms.h"


int main() {
    matrix m1 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  2, 5, 6,
                                                  3, 6, 9}, 3, 3);


    get_square_of_matrix_if_symmetric(&m1);

    output_matrix(&m1);

    return 0;
}
#include <stdio.h>

#include "data_structures/matrix/matrix.h"


int main() {
    matrix m = create_matrix_from_array((int[]) {1, 2, 3 ,4}, 2, 2);

    output_matrix(&m);

    return 0;
}
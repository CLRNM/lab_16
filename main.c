#include <stdio.h>

#include "data_structures/matrix/matrix.h"
#include "algorithms/algorithms.h"


int main() {
    matrix a = create_matrix_from_array((int[]) {3, 2, 5, 4,
                                                 1, 3, 6, 3,
                                                 3, 2, 1, 2}, 3, 4);



    long long int s = find_sum_of_maxes_of_pseudo_diagonal(a);

    printf("%lld", s);

    return 0;
}
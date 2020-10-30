# -*- coding: utf-8 -*-
"""
@author: Nellman1508
"""

import numpy as np


def merge_sort(x):
    """Sort list of integers with mergesort.

    Input a list of integers an returns the sorted list.
    When using large lists, beware of Pythons limit for recursion depth.
    """
    merged_numbers = []
    if len(x) <= 1:  # base case of the recursion
        return x

    half_length = int((len(x)/2))
    first_half = merge_sort(x[:half_length])
    second_half = merge_sort(x[half_length:])

    i = 0
    j = 0
    while(i < len(first_half) and j < len(second_half)):
        if first_half[i] < second_half[j]:
            merged_numbers.append(first_half[i])
            i += 1
        else:
            merged_numbers.append(second_half[j])
            j += 1
    merged_numbers += first_half[i:]
    merged_numbers += second_half[j:]
    return(merged_numbers)


if __name__ == "__main__":

    rand_numbers = list(np.random.randint(0, 100, size=20))
    print("The following list will be sorted:\n", rand_numbers)
    print(merge_sort(rand_numbers))

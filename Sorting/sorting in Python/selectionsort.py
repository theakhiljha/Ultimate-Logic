# -*- coding: utf-8 -*-
"""
@author: Nellman1508
"""

import numpy as np


def selection_sort(x):
    """Implementation of selection sort.

    Takes integer list as input,
    returns sorted list.
    """
    print("Starting selection sort on list:\n", x)
    iteration = 0
    for i in range(0, (len(x)-1)):
        iteration += 1
        print("Interation: ", iteration)
        current_value = x[i]
        for j in range(i, (len(x)-1)):
            if x[j] < current_value:
                current_value = x[j]
        x.remove(current_value)
        x.insert(i, current_value)
        print("Next smallest element: ", current_value)
    print("Sorted list:\n", x)
    return x


if __name__ == "__main__":

    rand_numbers = list(np.random.randint(0, 100, size=20))
    selection_sort(rand_numbers)

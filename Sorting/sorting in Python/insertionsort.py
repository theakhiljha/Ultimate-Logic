# -*- coding: utf-8 -*-
"""
@author: Nellman1508
"""

import numpy as np


def insertion_sort(x):
    """Implementation of Selection sort.

    Takes integer list as input,
    returns sorted list.
    """
    print("Starting insertion sort on list:\n", x)
    iteration = 0

    for i in range(1, (len(x))):
        iteration += 1
        print("Selection sort is in interation: ", iteration)

        current_value = x[i]
        j = i - 1

        while(j >= 0 and current_value < x[j]):
            j -= 1

        x.remove(current_value)
        print("put Number ", current_value, "at position ", (j+1))
        x.insert((j+1), current_value)

    print("Sorted list is:\n", x)
    return(x)


if __name__ == "__main__":

    rand_numbers = list(np.random.randint(0, 100, size=20))
    insertion_sort(rand_numbers)

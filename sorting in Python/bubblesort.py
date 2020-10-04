# -*- coding: utf-8 -*-
"""
@author: Nellman1508
"""

import numpy as np


def bubble_sort(x):
    """Implementation of Bubble sort.

    Takes integer list as input,
    returns sorted list."""
    print("Starting Bubble sort on following list:\n", x)
    loop = 0
    unsorted = True
    while(unsorted):
        loop += 1
        print("Bubble sort is in iteration: ", loop)
        changes = 0
        for i in range(0, (len(x)-1)):
            if x[i] > x[i+1]:
                print("Bubble sort is changing position of: ", x[i], "and",
                      x[i+1])
                j = x[i]
                x[i] = x[i+1]
                x[i+1] = j
                changes += 1
        if changes == 0:
            unsorted = False
    print("Bubble sort is finished. Sorted list is: \n", x)
    return x


if __name__ == "__main__":

    rand_numbers = list(np.random.randint(0, 100, size=20))
    bubble_sort(rand_numbers)

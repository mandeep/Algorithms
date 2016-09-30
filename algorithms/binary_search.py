def binary_search(sorted_list, value):
    """Given a sorted list and a value, returns the value's index.

    Positional arguments:
    sorted_list -- a list sorted from low to high, e.g. [1, 3, 5, 9].
    value -- a float, integer, or string to be found in the sorted list

    Analysis:
    The first variable is set to the sorted list's first index, while the
    last variable is set to the sorted list's last index. The middle variable
    is the sorted list's middle index. We can determine which part of the
    sorted list the value argument resides by comparing it to the element at
    the middle of the sorted list. If the value argument is less than the
    middle element, the last variable is assigned the middle value's index
    minus 1 since the middle element does not equal the value argument. If the
    value argument is greater than the element at the middle of the sorted
    list, the first variable is assigned the index of the middle element plus 1
    since the middle element does not equal the value argument. The first or
    last variable continues to change until the value argument equals the
    middle element. If the value argument is found, its index is returned.
    Otherwise, the function will return None.

    Reference: https://en.wikipedia.org/wiki/Binary_search_algorithm
    """
    first = 0
    last = len(sorted_list) - 1
    while first <= last:
        middle = (last + first) // 2
        if value < sorted_list[middle]:
            last = middle - 1
        elif value > sorted_list[middle]:
            first = middle + 1
        else:
            return middle
    return None

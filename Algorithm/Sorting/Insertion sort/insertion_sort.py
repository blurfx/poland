from typing import List


def insertion_sort(array: List, *, is_increasing: bool = True) -> None:

    for index in range(1, len(array)):
        cur = array[index]
        pos = index

        while pos > 0 and ((is_increasing and array[pos - 1] > cur) or (not is_increasing and array[pos - 1] < cur)):
            array[pos] = array[pos - 1]
            pos = pos - 1

        array[pos] = cur


if __name__ == '__main__':
    from random import randint
    arr = [randint(0, 100) for _ in range(20)]
    print(f'Original Array : {", ".join(arr)}')
    insertion_sort(arr)
    print(f'Sorted Array : {", ".join(arr)}')

import sys

arr: list[int] = []

def create_arr(n: int) -> list[int]:
    for i in range(n):
        arr.append(i)
    return arr

create_arr(10)

def display(arr: list[int]):
    for i in range(len(arr)):
        print(arr[i], end="")
    print()

def find_sum(arr: list[int], n: int) -> int:
    sum: int = 0

    for i in range(n):
        sum += arr[i]

    return sum

print(f"sum:{find_sum(arr,len(arr))}")

def find_largest_smallest(arr: list[int], n: int) -> (int, int):
    smallest: int = sys.maxsize
    largest: int = -sys.maxsize - 1

    for i in range(n):

        if arr[i] > largest:
            largest = arr[i]

        if arr[i] < smallest:
            smallest = arr[i]

    return largest, smallest

def reverse_arr(arr: list[int], n: int):
    i: int = 0
    j: int = len(arr) - 1

    while i < j:
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1

reverse_arr(arr, len(arr))
display(arr)
# Implementation of linear search in Python3

def linear_search(arr, target):
    i=0
    n = len(arr)
    while i<n:
        if target == arr[i]:
            return i
        i+=1
    if i==n:
        return -1
    
if __name__ == "__main__":
    print("Enter the array elements :")
    arr = [int(x) for x in input().split(" ")] # Takes Input from the user
    target = int(input("Enter target element: "))
    index = linear_search(arr, target)
    if index == -1:
        print(f"{target} not found.")
    else:
        print("{} found at index {}".format(target, index))

# Implementation of counting sort in Python3

def countingSort(array, length):
    """
    Counting sort algorithm
    Input : Array and size of the array
    Output : Returns the sorted Array
    """
    temp = [0] * length                 # Creates a temporary array
    for i in range(0, length - 1)   :
        for j in range(i + 1, length):
            if(array[i] < array[j]):    # If the element is smaller than the next element
                temp[j] += 1
            else:                       # If the element is greater than the next element 
                temp[i] += 1
    countSortArray = [0] * length       # Creates a new array
    for k in range(0, length):
        countSortArray[temp[k]] = array[k]
    return countSortArray
    
if __name__ == "__main__":
    print("Enter the array elements :")
    arrayToSort = [int(x) for x in input().split(" ")] # Takes Input from the user
    print(f"Sorted Array : {countingSort(arrayToSort, len(arrayToSort))}")

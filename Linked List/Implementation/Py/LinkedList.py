def linearsearch(l, num):
    for i in l:
        if num == i:
            return True
    return False


l = list(map(int, input("Enter the list: ").split()))
n = int(input("Entered the number to be searched: "))

if linearsearch(l, n):
    print("Number found")
else:
    print("Number not found")
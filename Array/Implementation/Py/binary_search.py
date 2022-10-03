
# Binary search algorithms are also known as half interval search. They return the position of a target value in a sorted list.
# These algorithms use the “divide and conquer” technique to find the value's position.

def binary_search(list_to_search, first_pos, last_pos, to_search):
    if last_pos >= first_pos:
       
        mid_index = (first_pos + last_pos) // 2
        mid_element = list_to_search[mid_index]
       
 
        if mid_element == to_search:
            return f"{mid_element} occurs in position {mid_index}"
 
        elif mid_element > to_search:
            new_position = mid_index - 1
            # new last index becomes the new last postion  position
            return binary_search(list_to_search, first_pos, new_position, to_search)
 
        elif mid_element < to_search:
            new_position = mid_index + 1
             # new first index becomes the new  first position
            return binary_search(list_to_search, new_position, last_pos, to_search)
 
    else:
        #return a statement if not found in the gievn item not found in the list
        return " Does not appear in the list"


# sample code to test the function 
list_container = [ 1, 9, 11, 21, 34, 54, 67, 90 ]
search = 34
first = 0
last= len(list_container) - 1
 
print(binary_search(list_container,first,last,search))

// Binary Search is a searching algorithm which reduces time complexity of searching in an Array. (Note: Array must be sorted)
// T.C -  O(log n).
// S.C - O(1)

import java.util.*;

public class Main
{
    private static int binarySearch(int[] arr, int target){
        // sort the given array
        Arrays.sort(arr);            
        
        int start = 0;
        int end = arr.length - 1;
        
        while(start < end){
            int mid = start + (end - start)/2;
            
            if(arr[mid] == target){
                return mid;
            }else if(arr[mid] > target){
                end = mid;
            }else{
                start = mid;
            }
        }
        
        return start;
    }
    
	public static void main(String[] args) {
	    int[] arr = {2, -1, 4, 5, 3, 7, 8};
	    int target = 5;
	    
	    int ansIndex = binarySearch(arr, target);
		System.out.println(ansIndex);
	}
}

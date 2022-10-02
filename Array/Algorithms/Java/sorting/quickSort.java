// Optimized Bubble sort in Java

import java.util.Arrays;

class Main {

  // perform the bubble sort
  private static void quickSort(int[] array, int start, int end) {
    if(start < end) {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot-1);
        quickSort(array, pivot+1, end);
    }
  }

  private static int partition(int[] array, int start, int end) {
    int pivot = end;
    int i = start - 1;
    for(int j = start; j <= end; j++) {
        if(array[j] <= array[pivot]) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    return i;
  } 

  public static void main(String args[]) {
      
    int[] data = { 45, -3, 27, 0, 2, -8 };
    
    // call method using the class name
    Main.quickSort(data, 0, data.length-1);
    
    System.out.println("Sorted Array in Ascending Order:");
    System.out.println(Arrays.toString(data));
  }
}

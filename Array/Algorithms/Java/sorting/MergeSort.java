class Solution {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        
        mergesort(nums,0,n-1);
        
        return nums;
    }
    
   public void mergesort(int nums[],int s, int e) {
        if(s>=e)
            return;
        
        int mid = (s+e)/2;

        
        mergesort(nums, s, mid);

        
        mergesort(nums, mid+1, e);

        
        merge(nums, s, e);
    }
    public void merge(int nums[], int s, int e) {
        int mid = (s+e)/2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        int ar1[] = new int[len1];
        int ar2[] = new int[len2];

        
        int k = s;
        for (int i = 0; i < len1; i++) {
            ar1[i] = nums[k++];
        }

        
        k = mid+1;
        for (int i = 0; i < len2; i++) {
            ar2[i] = nums[k++];
        }

        int ind1 = 0, ind2=0;
        k=s;
        while (ind1<len1 && ind2<len2) {
            if(ar1[ind1]<ar2[ind2])
                nums[k++] = ar1[ind1++];
            else
                nums[k++] = ar2[ind2++];
        }
        while (ind1<len1) {
            nums[k++] = ar1[ind1++];
        }
        while (ind2<len2) {
            nums[k++] = ar2[ind2++];
        }
    }
}
function countingSort(arr, min, max) {
    let j = 0;
    let supplementary = [];
    
    for (let i = min; i <= max; i++) {
        supplementary[i] = 0;
    }
    
    for (let i=0; i < arr.length; i++) {
        supplementary[arr[i]] += 1;
    }
       
    for (let i = min; i <= max; i++) {
        while (supplementary[i] > 0) {
            arr[j++] = i;
            supplementary[i] -= 1;
        }
    }
    return arr;
}
let sorted_array = countingSort([2, 3, 8, 7, 1, 2, 0, 10, 7, 3, 9, 8, 2, 1, 12, 2, -1, 6, 9, 2], -1, 12);
console.log(sorted_array);
const linear_search = (ar = [], key) => {
    for (let i = 0; i < ar.length; i++) {
        if (ar[i] === key) return i;
    }
    return -1;
}
const ar = [1, 9, 23, 45, 6];

console.log(linear_search(ar, 45));
console.log(linear_search(ar, 465));
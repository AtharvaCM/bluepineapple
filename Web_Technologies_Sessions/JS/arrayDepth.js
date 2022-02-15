// Given an array, write a function to calculate it's depth. Assume that a normal array has a depth of 1.
// example:
//     depth([1, 2, 3, 4]) ➞ 1
//     depth([1, [2, 3, 4]]) ➞ 2

const array1 = [1, 2, 3, 4];
const array2 = [1, [2, 3, 4]];
const array3 = [1, [2, [3, 4]]];
const array4 = [1, [2, [3, [4]]]];

function calcDepthOfArray(value) {
  if (Array.isArray(value)) {
    return 1 + Math.max(...value.map(calcDepthOfArray));
  }
  return 0;
}

console.log(`Depth of array [1, 2, 3, 4] -> ${calcDepthOfArray(array1)}`);
console.log(`Depth of array [1, [2, 3, 4]] -> ${calcDepthOfArray(array2)}`);
console.log(`Depth of array [1, [2, [3, 4]]] -> ${calcDepthOfArray(array3)}`);
console.log(`Depth of array [1, [2, [3, [4]]]] -> ${calcDepthOfArray(array4)}`);

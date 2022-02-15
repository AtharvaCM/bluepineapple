// Create a function that returns the total number of boomerangs in an array.

// input: [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]
// output: 3 boomerangs in this sequence:  [3, 7, 3], [1, 5, 1], [2, -2, 2]

function isBoomerang(arr) {
  if (arr.length != 3) {
    console.log("invalid array length passed to isBoomerang function");
    return;
  }
  // console.log(arr);
  return arr[0] == arr[2] ? true : false;
}

const inputArray = [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2];
let boomerangCounter = 0;
let resultString = "";

for (i = 0; i < inputArray.length - 2; i++) {
  // console.log(arr.slice(i, i + 3));
  let subArray = inputArray.slice(i, i + 3);
  if (isBoomerang(subArray)) {
    boomerangCounter++;
    resultString += `[${subArray.toString()}], `;
  }
}

console.log(`${boomerangCounter} boomerangs in this sequence: ${resultString}`);

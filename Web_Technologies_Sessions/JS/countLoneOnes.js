// Create a function which counts how many lone 1s appear in a given number.
// Lone means the number doesn't appear twice or more in a row.
// example: countLoneOnes(101) ➞ 2, countLoneOnes(1191) ➞ 1

function countLoneOnes(number) {
  let loneOneCounter = 0;
  let numString = number.toString();

  for (let i = 0; i < numString.length; i++) {
    if (
      numString.charAt(i) == 1 &&
      !(numString.charAt(i + 1) == 1) &&
      !(numString.charAt(i - 1) == 1)
    ) {
      loneOneCounter++;
    }
  }

  return loneOneCounter;
}

console.log(`countLoneOnes(101) -> ${countLoneOnes(101)}`);
console.log(`countLoneOnes(1191) -> ${countLoneOnes(1191)}`);
console.log(`countLoneOnes(14531101) -> ${countLoneOnes(14531101)}`);

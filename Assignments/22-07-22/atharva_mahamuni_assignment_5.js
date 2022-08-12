// arr = [rand nums], total count
// first occurence find a pair of consecutive and rand nums that array

const _l = (msg) => console.log(msg);

// const numbers = Array.from({ length: 40 }, () =>
//   Math.floor(Math.random() * 40)
// );

const numbers = [1, 2, 3, 5, 6, 7, 8, 9];

const key = 11;

// Map  for numbers and their frequency in the array
const numberMap = new Map();

_l(numbers);

const checkSum = (a, b) => {
  return a + b == key;
};

const findConsecutivePair = () => {
  for (let i = 0; i < numbers.length - 1; i++) {
    if (checkSum(i, i + 1)) {
      _l(i + " + " + (i + 1));
      break;
    }
  }
};

const findRandomPairNSqaure = () => {
  for (let i = 0; i < numbers.length; i++) {
    if (checkSum(i, i + 1)) {
      _l(i + " + " + (i + 1));
      break;
    }
  }
};

// Put Numbers from array into map
const setNumberMap = () => {
  numbers.forEach((num) => {
    const numValue = numberMap.get(num) || 0;
    numberMap.set(num, Number(numValue) + Number(1));
  });
};

const findRandomPair = () => {
  setNumberMap();

  // Take ceil of key/2
  const ceil = Math.ceil(key / 2);

  let sum = 0;

  // Iterate through the map keys in the reverse order from the ceil key and check for sum
  for (let i = ceil; i > 0; i--) {
    numberMap.get(ceil);
  }
};

const countPairs = (_arr, x) => {
  if (!x) x = 0;

  let pairs = 0;
  let i = 0;
  let k = _arr.length - 1;

  // edge case
  if (k + 1 < 2) return pairs;

  let halfX = x / 2;

  while (i < k) {
    let curK = _arr[k];
    let curI = _arr[i];
    let pairsThisLoop = 0;

    if (curK + curI == x) {
      // midpoint and equal find combinations
      if (curK == curI) {
        let comb = 1;

        while (--k >= i) pairs += comb++;
        break;
      }
      // count pair and k duplicates
      pairsThisLoop++;
      while (_arr[--k] == curK) pairsThisLoop++;

      // add k side pairs to running total for every i side pair found
      pairs += pairsThisLoop;
      while (_arr[++i == curI]) pairs += pairsThisLoop;
    } else {
      // if we are at a midpoint
      if (curK == curI) break;

      let distK = Math.abs(halfX - curK);
      let distI = Math.abs(halfX - curI);

      if (distI > distK) while (_arr[++i] == curI);
      else while (_arr[--k] == curK);
    }
  }

  return pairs;
};

// findConsecutivePair();

_l(countPairs(numbers, 10));

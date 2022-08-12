const _l = (msg) => console.log(msg);

const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14];

const isPrime = (num) => {
  for (let i = 2, s = Math.sqrt(num); i <= s; i++)
    if (num % i === 0) return false;
  return num > 1;
};

const getEven = function (numbers) {
  _l(numbers.filter((num) => num % 2 == 0));
};

const getOdd = function (numbers) {
  _l(numbers.filter((num) => num % 2 != 0));
};

const getPrimes = (numbers) => {
  _l(numbers.filter(isPrime));
};

const functions = [getEven, getOdd, getPrimes, "1"];

functions.map((func) => {
  switch (func) {
    case getEven:
      getEven(numbers);
      break;

    case getOdd:
      getOdd(numbers);
      break;

    case getPrimes:
      getPrimes(numbers);
      break;

    default:
      (() => {
        _l(numbers);
      })();
      break;
  }
});

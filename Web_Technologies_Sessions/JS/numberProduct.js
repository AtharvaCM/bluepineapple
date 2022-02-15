// Create a function that takes one, two or more numbers as arguments and adds them together to
// get a new number. The function then repeatedly multiplies the digits of the new number by each
// other, yielding a new number, until the product is only 1 digit long. Return the final product.

function addDigits(numString) {
  let sum = 0;
  for (let i = 0; i < numString.length; i++) {
    sum += +numString.charAt(i);
  }

  console.log(`Sum of digits: ${sum}`);
  return sum;
}

// multiply until the result is 1 digit long
function getProduct(number) {
  let numString = number.toString();
  if (numString.length == 1) {
    return +numString;
  }

  let result = 1;
  for (let i = 0; i < numString.length; i++) {
    result *= +numString.charAt(i);
  }

  //   console.log(result);
  return getProduct(result);
}

function getReducedNumber(number) {
  let numString = number.toString();
  console.log(`Reducing the number ${numString}`);

  let sum = addDigits(numString);

  return getProduct(sum);
}

console.log(`Reduced number is ${getReducedNumber(19934)}`);

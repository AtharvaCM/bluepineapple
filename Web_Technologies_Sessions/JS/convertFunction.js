function convertFunction(func) {
  stringRep = func.toString();
  console.log(stringRep);

  if (stringRep.includes("=>")) {
    console.log("its an arrow function");

    if (stringRep.includes("{")) {
      let newString = stringRep
        .replace("(", "function func (")
        .replace("=> ", "");
      return newString;
    } else {
      let newString = stringRep
        .replace("(", "function func (")
        .replace("=> ", "{ \n  return ")
        .concat("\n}");
      return newString;
    }
  } else {
    console.log("its a regular function");

    let newString = stringRep
      .replace("function", "")
      .replace("(", " = (")
      .replace(")", ") =>");
    return newString;
  }
}

function sum(a, b) {
  return a + b;
}

const mul = (a, b) => {
  return a * b;
};

const div = (a, b) => a / b;

// convertFunction(sum);
console.log(convertFunction(sum));
console.log(convertFunction(mul));
console.log(convertFunction(div));

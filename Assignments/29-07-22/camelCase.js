// A function which converts a sentense into a camelCase word

const input = "Hi-my-name-is-slim-Shady";

// accepts a string sentense and a optional delimiter and returns a camelCase word
const convertToCamelCase = (sentense, delimeter = " ") => {
  // emtpy check
  if (!sentense) {
    return null;
  }

  const words = sentense.split(delimeter);
  let camelCaseWord = "";

  // first words is always lowercased
  words[0] = words[0].toLowerCase();
  camelCaseWord = camelCaseWord.concat(words[0]);

  // capitalize only the first letter for rest of the words
  for (let index = 1; index < words.length; index++) {
    let uppercased = words[index][0].toUpperCase();
    let lowercased = words[index].substr(1).toLowerCase();

    // concat all the words into a single string
    camelCaseWord = camelCaseWord.concat(uppercased, lowercased);
  }

  return camelCaseWord;
};

console.log(convertToCamelCase(input, "-"));

const jsonCollection = require("./data/countryNamesWithCodes.json");
const jsonCodes = require("./data/countryCodes.json");

const _l = (msg) => console.log(msg);

// const countryMap = new Map();

// map all the countries with their codes
// jsonCollection.collection.forEach((obj) => {
//   countryMap.has(obj.code) ? null : countryMap.set(obj.code, obj.name);
// });

// const getCountryNameFromCode = () => {
//   jsonCodes.codes.forEach((code) => {
//     _l(code + "-->" + countryMap.get(code));
//   });
// };

// getCountryNameFromCode();

jsonCollection.collection.forEach((obj) => {
  jsonCodes.codes.includes(obj.code) ? _l(obj.code + "-->" + obj.name) : null;
});

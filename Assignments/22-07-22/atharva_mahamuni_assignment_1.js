// input - list of objects with diff props
// expected output - array of collections

const _l = (msg) => console.log(msg);

const keyMap = new Map();

function logMapElements(value, key, map) {
  console.log(`m[${key}] = ${value}`);
}

const objectList = [
  {
    id: 1,
    name: "Atharva",
    city: "Pune",
  },
  {
    id: 2,
    name: "John",
  },
  {
    id: 3,
    city: "Pune",
    state: "Maharashtra",
  },
  {
    id: 4,
    name: "Bob",
  },
  {
    id: 5,
    name: "Alice",
    city: "NY",
  },
];

_l(objectList);

for (obj of objectList) {
  let key = Object.keys(obj).toString();

  if (keyMap.has(key)) {
    // if map has key then add the obj index in the array
    const existingElements = keyMap.get(key);
    existingElements.push(objectList.indexOf(obj));
    keyMap.set(key, existingElements);
  } else {
    // key not present then add the key and obj index
    keyMap.set(key, [objectList.indexOf(obj)]);
  }
}

keyMap.forEach(logMapElements);

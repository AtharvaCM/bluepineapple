const fib = require("./fibonacciOnDemand");

const _l = (msg) => console.log(msg);

const generator = fib.generator;

_l(`To skip initial call - ${generator.next().value}`);

// _l(generator.next().value);

const callAPI = (id) => {
  const url = `https://jsonplaceholder.typicode.com/users/${id}`;

  fetch(url)
    .then((res) => res.json())
    .then((data) => _l(data))
    .catch((err) => _l(err));
};

callAPI(generator.next().value);
callAPI(generator.next().value);
callAPI(generator.next().value);

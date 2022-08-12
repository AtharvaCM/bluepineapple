const _l = (msg) => console.log(msg);

const numbers = [1, 4, 2, 56, 7, 3, 56, 9];

const even = [];
const odd = [];

numbers.map((num) => {
	if (num % 2 == 0) {
		even.push(num);
	} else {
		odd.push(num);
	}
});


_l('Original  array ' + numbers);
_l('Even ' + even);
_l('Odd ' + odd);
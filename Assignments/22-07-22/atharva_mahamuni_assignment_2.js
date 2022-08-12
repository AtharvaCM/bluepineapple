const _l = (msg) => console.log(msg)

function* fibOnDemand() {
	let i = 0;
	let j = 1;
	let num = 0;

	yield 0;
	yield 1;

	while (true) {
		num = i + j;
		yield num;
		i = j;
		j = num;
	}
}

const generator = fibOnDemand();

// _l(generator.next());

module.exports = { generator }
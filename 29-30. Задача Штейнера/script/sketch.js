class Point {
	constructor(x, y) {
		this.x = x;
		this.y = y;
	}
}

let dots = [];
let solution;

function drawField() {
	let w = width / 60;
	let c = color(0, 0, 0, 15);
	strokeWeight(1);
	stroke(0);

	stroke(c);

	for (let y = 0; y < width; y += w) {
		line(0, y, width, y);
	}

	for (let x = 0; x < width; x += w) {
		line(x, 0, x, height);
	}
}

function solutionForThreePoints() {
	if (solution) {
		dots.forEach((v, i) => {
			strokeWeight(2);
			stroke(235, 81, 96, 60);

			line(v.x, v.y, solution.x, solution.y);
			stroke(0);
			strokeWeight(0);
			text(`P${i + 1}`, v.x + 5, v.y + 5);
		});

		strokeWeight(7);
		stroke("black");
		dots.forEach((v, i) => {
			point(v.x, v.y);
		});

		strokeWeight(9);
		stroke("red");
		point(solution.x, solution.y);

		if (solution.ok) {
			strokeWeight(0);
			text(`O`, solution.x + 5, solution.y + 5);
		}
	} else {
		strokeWeight(7);
		stroke("black");
		dots.forEach((v, i) => {
			strokeWeight(7);
			point(v.x, v.y);
			stroke(0);
			strokeWeight(0);
			text(`P${i + 1}`, v.x + 5, v.y + 5);
		});
	}
}

function setup() {
	createCanvas(windowWidth, windowHeight);
	frameRate(10);
}

function draw() {
	background(255);
	drawField();
	textSize(15);

	button = createButton("Очистить поле");
	button.position(10, 10);
	button.mousePressed(clearField);

	solutionForThreePoints();
}

function clearField() {
	dots = [];
	solution = null;

	clear();
}

function mouseClicked() {
	if (mouseX < 200 && mouseY < 75) {
		return;
	}

	if (dots.length >= 3) {
		dots.shift();
	}

	dots.push(new Point(mouseX, mouseY));

	if (dots.length < 3) {
		return;
	}
	solution = SolveForThree(
		Array(3)
			.fill()
			.map((el, i) => dots[i].x),
		Array(3)
			.fill()
			.map((el, i) => dots[i].y)
	);
}

function windowResized() {
	resizeCanvas(windowWidth, windowHeight);
}

function SolveForThree(x, y) {
	const lim = Math.PI * 2 / 3;

	let angles = [
		Math.abs(GetAngle({ x: x[0], y: y[0] }, { x: x[1], y: y[1] }, { x: x[2], y: y[2] })),
		Math.abs(GetAngle({ x: x[1], y: y[1] }, { x: x[2], y: y[2] }, { x: x[0], y: y[0] })),
		Math.abs(GetAngle({ x: x[2], y: y[2] }, { x: x[1], y: y[1] }, { x: x[0], y: y[0] })),
	];

	if (angles.filter(x => x >= lim).length > 0) {
		let
			mx = max(angles),
			index = angles.indexOf(mx);
		return { x: x[index], y: y[index] };
	} else {
		let
			r12 = Math.sqrt((x[0] - x[1]) ** 2 + (y[0] - y[1]) ** 2),
			r13 = Math.sqrt((x[0] - x[2]) ** 2 + (y[0] - y[2]) ** 2),
			r23 = Math.sqrt((x[1] - x[2]) ** 2 + (y[1] - y[2]) ** 2),
			s = x[0] * y[1] + x[1] * y[2] + x[2] * y[0] - x[0] * y[2] - x[2] * y[1] - x[1] * y[0],
			k1 = (Math.sqrt(3) / 2) * (r12 ** 2 + r13 ** 2 - r23 ** 2) + Math.abs(s),
			k2 = (Math.sqrt(3) / 2) * (r23 ** 2 + r12 ** 2 - r13 ** 2) + Math.abs(s),
			k3 = (Math.sqrt(3) / 2) * (r13 ** 2 + r23 ** 2 - r12 ** 2) + Math.abs(s),
			d = (1 / Math.sqrt(3)) * (k1 + k2 + k3),
			Px = ((k1 * k2 * k3) / (2 * Math.sqrt(3) * Math.abs(s) * d)) * (x[0] / k1 + x[1] / k2 + x[2] / k3),
			Py = ((k1 * k2 * k3) / (2 * Math.sqrt(3) * Math.abs(s) * d)) * (y[0] / k1 + y[1] / k2 + y[2] / k3);

		return new Point(Px, Py);
	}
}

function GetAngle(mainPoint, firstPoint, secondPoint) {
	let
		x1 = firstPoint.x - mainPoint.x,
		x2 = secondPoint.x - mainPoint.x,
		y1 = firstPoint.y - mainPoint.y,
		y2 = secondPoint.y - mainPoint.y,
		d1 = Math.sqrt(x1 ** 2 + y1 ** 2),
		d2 = Math.sqrt(x2 ** 2 + y2 ** 2);

	return Math.acos((x1 * x2 + y1 * y2) / (d1 * d2));
}
'use strict';

const fs = require("fs");

const data = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);

const T = data[0];
let idx = 1;
let out = [];

for (let i = 0; i < T; i++) {
  const n = data[idx++];

  if (n <= 5) {
    out.push("MIT time");
    continue;
  }

  let k = 2;
  let power = 25; // 5 square

  while (power < n) {
    power *= 5;
    k++;
  }

  out.push(`MIT^${k} time`);
}

console.log(out.join("\n"));

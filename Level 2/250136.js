// [PCCP 기출문제] 2번 / 석유 시추

const directions = [
  [0, 0],
  [0, 1],
  [1, 0],
  [0, -1],
  [-1, 0],
];

const drilling = (land, x, y) => {
  let ret = 0;

  for (let i = 0; i < directions.length; i++) {
    const [dx, dy] = directions[i];
    const nx = x + dx;
    const ny = y + dy;
    if (nx < 0 || nx >= land.length) continue;
    if (ny < 0 || ny >= land[0].length) continue;
    if (land[nx][ny] !== 1) continue;
    land[nx][ny] = -1;
    ret++;
    ret += drilling(land, nx, ny);
  }

  return ret;
};

function solution(land) {
  var answer = 0;

  const copied = land.map((row) => [...row]);

  for (let i = 0; i < land[0].length; i++) {
    let amount = 0;
    for (let j = 0; j < land.length; j++) {
      if (land[j][i] === 1) {
        amount += drilling(land, j, i);
      }
    }
    answer = Math.max(answer, amount);
    land = copied.map((row) => [...row]);
  }

  return answer;
}

solution([
  [0, 0, 0, 1, 1, 1, 0, 0],
  [0, 0, 0, 0, 1, 1, 0, 0],
  [1, 1, 0, 0, 0, 1, 1, 0],
  [1, 1, 1, 0, 0, 0, 0, 0],
  [1, 1, 1, 0, 0, 0, 1, 1],
]);

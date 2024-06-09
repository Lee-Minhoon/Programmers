// [3차] 압축

const initDict = () => {
  const dict = {};
  for (let i = 65; i <= 90; i++) {
    dict[String.fromCharCode(i)] = i - 64;
  }
  return dict;
};

function solution(msg) {
  const dict = initDict();
  const answer = [];

  let currentIdx = 0;

  for (let i = 0; i < msg.length; i++) {
    for (let j = i + 1; j < msg.length; j++) {
      const searchWord = msg.slice(i, j + 1);
      if (!dict[searchWord]) {
        dict[searchWord] = Object.keys(dict).length + 1;
        answer.push(dict[msg.slice(i, j)]);
        i = j - 1;
        currentIdx = j;
        break;
      }
    }
  }

  answer.push(dict[msg.slice(currentIdx)]);

  return answer;
}

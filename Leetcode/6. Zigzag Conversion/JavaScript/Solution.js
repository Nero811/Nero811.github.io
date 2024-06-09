var convert = function (s, numRows) {
  if (numRows === 1) {
    return s;
  }
  // 宣告一個2維陣列並初始化
  let array = new Array(numRows).fill("");
  let step = 1;
  // 宣告一個flag，當flag = true時，表示array方向向下，flag = false時，表示array方向向上
  let flag = true;
  for (let i = 0; i < s.length; i++) {
    array[step - 1] += s[i];
    // 表示到array長邊的底跟頂點，變更flag方向
    if (step === 1 || step === numRows) {
        flag = !flag;
    }
    if (flag) {
        step--;
    } else {
        step++;
    }
  }
  return array.join("");
};

let s = "PAYPALISHIRING";
let numRows = 3;
console.log(convert(s, numRows));

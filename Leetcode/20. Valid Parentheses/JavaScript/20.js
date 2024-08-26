var isValid = function (s) {
  let st = new Array();
  for (ch of s) {
    if (ch == ")" && !st.length == 0 && st[st.length - 1] == "(") {
      st.pop();
      continue;
    } else if (ch == "]" && !st.length == 0 && st[st.length - 1] == "[") {
      st.pop();
      continue;
    } else if (ch == "}" && !st.length == 0 && st[st.length - 1] == "{") {
      st.pop();
      continue;
    }
    st.push(ch);
  }
  if (!st.length == 0) {
    return false;
  }

  return true;
};

s = "([])";
console.log(isValid(s));

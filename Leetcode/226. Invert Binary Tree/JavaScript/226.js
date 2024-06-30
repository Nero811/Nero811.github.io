function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

var invertTree = function (root) {
  let nodeArr = [];
  if (root) {
    nodeArr.push(root);
  }
  while (nodeArr.length > 0) {
    // 更新每層node數
    let size = nodeArr.length;
    // 遍歷單層node
    for (let i = 0; i < size; i++) {
      let node = nodeArr.shift();
      let left = node.left;
      let right = node.right;
      // 因提議左右子樹相反，所以push array時要相反
      if (right) {
        nodeArr.push(node.right);
      }

      if (left) {
        nodeArr.push(node.left);
      }
      // 翻轉子結點
      node.right = left;
      node.left = right;
    }
  }
  return root;
};

let root = new TreeNode(4, new TreeNode(2), new TreeNode(7));
root.left.left = new TreeNode(1);
root.left.right = new TreeNode(3);
root.right.left = new TreeNode(6);
root.right.right = new TreeNode(9);
invertTree(root);
console.log(root);

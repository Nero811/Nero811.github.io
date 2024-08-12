function TreeNode(val, left, right) {
    this.val = val;
    this.left = left;
    this.right = right;
}

var levelOrder = function(root) {
    let que = [];
    if (root) {
        que.push(root);
    }
    
    let result = [];
    while (que.length > 0) {
        let size = que.length;
        let lt = [];
        for (let i = 0 ; i < size ; i++) {
            let node = que.shift();
            if (node) {
                lt.push(node.val);
            }
            if (node && node.left) {
                que.push(node.left);
            }
            if (node && node.right) {
                que.push(node.right);
            }
        }
        if (lt.length > 0) {
            result.push(lt);
        }
    }

    return result;
};

let root =  new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
console.log(levelOrder(root));
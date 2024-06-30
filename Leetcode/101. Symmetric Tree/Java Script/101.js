function TreeNode(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
}

var isSymmetric = function(root) {
    // 將左右子樹拆成兩個陣列分別記錄各個子結點
    let leftTree = [];
    let rightTree = [];
    if (root.left) {
        leftTree.push(root.left);
    }

    if (root.right) {
        rightTree.push(root.right);
    }
    
    if (leftTree.length != rightTree.length) {
        return false;
    }
    // 當左右子樹的長度相同時才繼續迴圈
    while (leftTree.length > 0 && rightTree.length > 0) {
        let leftSize = leftTree.length;
        let rightSize = rightTree.length;
        // 左右子樹長度不同表示非完全對稱
        if (leftSize != rightSize) {
            return false;
        }
        // 左右子樹值不同表示非完全對稱
        for (let i = 0 ; i < leftSize ; i++) {
            if (leftTree[i].val != rightTree[i].val) {
                return false;
            }
        }
        
        for (let i = 0 ; i < leftSize ; i++) {
            let leftNode = leftTree.shift();
            let rightNode = rightTree.shift();
            // 左右子樹分別遍歷各節點，這邊注意因為要取頭節點，所以左右子樹要從相反方向遍歷
            if (leftNode.left && rightNode.right) {
                leftTree.push(leftNode.left);
                rightTree.push(rightNode.right);
            } else if ((!leftNode.left && rightNode.right) || (leftNode.left && !rightNode.right)) { // 判斷左右子樹是否對稱
                return false;
            }
             // 左右子樹分別遍歷各節點，這邊注意因為要取頭節點，所以左右子樹要從相反方向遍歷
            if (leftNode.right && rightNode.left) {
                leftTree.push(leftNode.right);
                rightTree.push(rightNode.left);
            } else if ((!leftNode.right && rightNode.left) || (leftNode.right && !rightNode.left)) { // 判斷左右子樹是否對稱
                return false;
            }
        }
    }

    return true;
};


// let root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
let root = new TreeNode(1, new TreeNode(2, null, new TreeNode(3)), new TreeNode(2, null, new TreeNode(3)));

console.log(isSymmetric(root));

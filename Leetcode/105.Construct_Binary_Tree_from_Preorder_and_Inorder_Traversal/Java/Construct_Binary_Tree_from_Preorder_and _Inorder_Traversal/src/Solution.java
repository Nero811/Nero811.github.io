import java.util.HashMap;

/**
 * Author:Jack Yang
 * Date:2023/06/06
 * Description:
 */
public class Solution {
    private static HashMap<Integer,Integer> map;
    public static TreeNode travel(int inLeft, int inRight, int preLeft, int preRight, int[] inorder, int[] preorder){
        if(inLeft >= inRight || preLeft >= preRight){
            return null;
        }
        TreeNode root = new TreeNode(preorder[preLeft]);
        int rootIndex = map.get(root.val);
        int inleft = rootIndex - inLeft;
        root.left = travel(inLeft, rootIndex , preLeft+1, preLeft+inleft+1, inorder, preorder);
        root.right = travel(rootIndex + 1, inRight, preLeft+inleft+1, preRight, inorder, preorder);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        map = new HashMap<>();
        for(int i = 0; i < preorder.length ; i++){
            map.put(inorder[i],i);
        }
        return travel(0,inorder.length,0,preorder.length,inorder,preorder);
    }
}

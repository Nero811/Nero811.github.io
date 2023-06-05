import java.util.HashMap;

/**
 * Author:Jack Yang
 * Date:2023/06/05
 * Description:
 */
public class Solution {
    private HashMap<Integer,Integer> map;
    public TreeNode travel(int leftInorder, int righterInorder , int leftPostorder, int rightPostorder, int[] inorder, int[] postorder){
        if(leftInorder >= righterInorder || leftPostorder >= rightPostorder){
            return null;
        }
        int nodeVal = postorder[rightPostorder-1];
        TreeNode root = new TreeNode(nodeVal);
        int mid = map.get(nodeVal);
        int poEnd = mid - leftInorder;
        root.left = travel(leftInorder, mid, leftPostorder, leftPostorder + poEnd, inorder, postorder);
        root.right = travel(mid+1, righterInorder, leftPostorder + poEnd, rightPostorder-1, inorder, postorder);
        return root;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        map = new HashMap<>();
        for(int i = 0 ; i < inorder.length ; i++){
            map.put(inorder[i],i);
        }
        int size = postorder.length;
        TreeNode result = travel(0,size,0,size,inorder,postorder);
        return result;
    }
}

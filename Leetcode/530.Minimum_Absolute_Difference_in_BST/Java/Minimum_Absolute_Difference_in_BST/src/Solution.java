import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

/**
 * Author:Jack Yang
 * Date:2023/06/13
 * Description:
 */
public class Solution {
    protected ArrayList<Integer> lt;
    public void travel(TreeNode root){
        if (root == null){
            return;
        }
        travel(root.left);
        lt.add(root.val);
        travel(root.right);
        return;
    }
    public int getMinimumDifference(TreeNode root) {
        lt = new ArrayList<>();
        int min = Integer.MAX_VALUE;
        travel(root);
        for (int i = 1 ; i < lt.size() ; i++){
            min = Math.min((lt.get(i) - lt.get(i-1)),min);
        }
        return min;
    }
}

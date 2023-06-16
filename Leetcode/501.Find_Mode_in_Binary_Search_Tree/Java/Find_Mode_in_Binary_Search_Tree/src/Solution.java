import java.util.*;

/**
 * Author:Jack Yang
 * Date:2023/06/14
 * Description:Find Mode in Binary Search Tree
 */
public class Solution {
    public int[] findMode(TreeNode root) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        mp.put(root.val,0);
        int max = 0;
        while (!que.isEmpty()){
            int size = que.size();
            for (int i = 0 ; i < size ; i++) {
                TreeNode node = que.poll();
                if (mp.containsKey(node.val)) {
                    mp.put(node.val, mp.get(node.val) + 1);
                    max = Math.max(max,mp.get(node.val));
                } else {
                    mp.put(node.val, 1);
                    max = Math.max(max,mp.get(node.val));
                }
                if (node.left != null) que.add(node.left);
                if (node.right != null) que.add(node.right);
            }
        }
        int length = 0;
        for (Map.Entry<Integer,Integer> pair : mp.entrySet()){
            if (pair.getValue() == max){
                length++;
            }
        }
        int[] result = new int[length];
        int i = 0;
        for (Map.Entry<Integer,Integer> pair : mp.entrySet()){
            if (pair.getValue() == max){
                //    System.out.println(pair.getKey());
                result[i] = pair.getKey();
                i++;
            }
        }
        return result;
    }
}

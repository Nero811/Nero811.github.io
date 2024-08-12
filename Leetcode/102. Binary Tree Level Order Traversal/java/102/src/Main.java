import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

    public static List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> que = new LinkedList<>();
        if (root != null) {
            que.add(root);
        }
        List<List<Integer>> result = new LinkedList<>();
        while (!que.isEmpty()) {
            int size = que.size();
            List<Integer> list = new LinkedList<>();
            for (int i = 0 ; i < size ; i++) {
                TreeNode node = que.poll();
                if (node != null) {
                    list.add(node.val);
                }
                if (node != null && node.left != null) {
                    que.add(node.left);
                }

                if (node != null && node.right != null) {
                    que.add(node.right);
                }
            }
            if (!list.isEmpty()) {
                result.add(list);
            }
        }

        return result;
    }

    public static void main(String[] args) {
       TreeNode root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
       System.out.println(levelOrder(root));
    }
}
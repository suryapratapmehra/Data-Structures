/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levelOrderList = new ArrayList<>();
        if(root == null) {
            return levelOrderList;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null);
        List<Integer> level = new ArrayList<>();
        int nullCount = 0;
        
        while(!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if(node == null) {
                nullCount++;
                if(nullCount == 2) {
                    break;
                }
                levelOrderList.add(level);
                level = new ArrayList<>();
                queue.add(null);
                continue;
            }
            nullCount = 0;
            level.add(node.val);
            if(node.left != null) {
                queue.add(node.left);
            }
            if(node.right != null) {
                queue.add(node.right);
            }
            
        }
        return levelOrderList;
    }
    
}

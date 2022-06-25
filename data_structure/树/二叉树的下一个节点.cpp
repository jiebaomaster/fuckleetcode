/**
 * https://mp.weixin.qq.com/s/yewlHvHSilMsrUMFIO8WAA
 * https://www.nowcoder.com/questionTerminal/9023a0c988684a53960365b889ceaf5e
 * 节点中序遍历的下一个节点有以下可能：
 *  若x有右子树。则x的下一个节点为x右子树最左侧节点。
 *  若x没有右子树，又分为2种情况。
 *    若x是父节点的左孩子。则x的父节点就是x的下一个节点。
 *    若x是父节点的右孩子。则沿着父节点向上，直到找到一个节点的父节点的左孩子是该节点，
 *    则该节点的父节点就是x的下一个节点。
 */
class Solution {
 public:
  TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if (!pNode) return nullptr;
    if (pNode->right) {  // 有右孩子，返回右孩子的最左边
      pNode = pNode->right;
      while (pNode->left) {
        pNode = pNode->left;
      }
      return pNode;
    }
    if (!pNode->next) return nullptr;
    if (pNode == pNode->next->left) {  // p 是父节点的左孩子
      return pNode->next;
    } else { // p 是父节点的右孩子
      while (pNode->next && pNode == pNode->next->right) {
        pNode = pNode->next;
      }
      return pNode->next;
    }
  }
};
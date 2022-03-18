/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string res;  // 结果字符串，模仿letcode的序列化格式
    if (!root) return res;

    queue<TreeNode*> q;
    q.push(root);
    res = to_string(root->val) + ",";
    while (!q.empty()) {
      for (int i = q.size(); i > 0; i--) {
        auto n = q.front();
        q.pop();

        if (n->left) {
          res += to_string(n->left->val);
          q.push(n->left);
        } else
          res += "null";

        res += ",";

        if (n->right) {
          res += to_string(n->right->val);
          q.push(n->right);
        } else
          res += "null";

        res += ",";
      }
    }
    res.resize(res.size() - 1);  // 去掉最后的逗号
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.size() == 0) return nullptr;
    queue<TreeNode*> q;
    int i = 0;
    auto root = nextNode(data, &i);
    q.push(root);
    while (!q.empty() && i < data.size()) {
      for (int j = q.size(); j > 0; j--) {
        auto n = q.front();
        q.pop();

        i++;
        n->left = nextNode(data, &i);
        if (n->left) q.push(n->left);

        // 最后一个结点可能只有左子树，防止建立右子树时越界访问
        if (i >= data.size()) break;

        i++;
        n->right = nextNode(data, &i);
        if (n->right) q.push(n->right);
      }
    }
    return root;
  }

  // 从字符串中新建下一个结点
  // 当前 i 指向数字的第一个字符，最后 i 指向下一个逗号
  TreeNode* nextNode(string& data, int* i) {
    TreeNode* n = nullptr;
    if (data[*i] == 'n') { // 有可能是 null
      (*i) = *i + 4;
    } else {
      int f = 1;
      if (data[*i] == '-') { // 负数最后要乘 -1
        f = -1;
        (*i)++;
      }
      int tmp = 0;
      while (data[*i] != ',') { // 构建数字
        tmp = tmp * 10 + (data[*i] - '0');
        (*i)++;
      }
      n = new TreeNode(tmp * f);
    }
    return n;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
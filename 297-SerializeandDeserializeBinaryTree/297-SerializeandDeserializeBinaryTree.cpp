// Last updated: 2/14/2026, 4:10:18 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12
13      string serialize(TreeNode* root) {
14        string result;
15        dfs(root, result);
16        return result;
17    }
18
19    void dfs(TreeNode* node, string& result) {
20        if (!node) {
21            result += "n,";
22            return;
23        }
24        result += to_string(node->val) + ",";
25        dfs(node->left, result);
26        dfs(node->right, result);
27    }
28
29
30    // Decodes your encoded data to tree.
31    TreeNode* deserialize(string data) {
32        int index = 0;
33        return dfsDeserialize(data, index);
34    }
35
36    TreeNode* dfsDeserialize(const string& data, int& index) {
37        // If we hit null marker
38        if (data[index] == 'n') {
39            index += 2; // skip "n,"
40            return nullptr;
41        }
42
43        // Read integer value
44        int sign = 1;
45        if (data[index] == '-') {
46            sign = -1;
47            index++;
48        }
49
50        int num = 0;
51        while (data[index] != ',') {
52            num = num * 10 + (data[index] - '0');
53            index++;
54        }
55        index++; // skip comma
56
57        TreeNode* node = new TreeNode(sign * num);
58        node->left = dfsDeserialize(data, index);
59        node->right = dfsDeserialize(data, index);
60        return node;
61    }
62};
63
64// Your Codec object will be instantiated and called as such:
65// Codec ser, deser;
66// TreeNode* ans = deser.deserialize(ser.serialize(root));
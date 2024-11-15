typedef long long ll;

void dfs(struct TreeNode* root, ll val, ll* ans) {
    if (!root) return;

    val = val * 10 + root->val;

    if (!root->left && !root->right) {
        *ans += val;
        return;
    }

    dfs(root->left, val, ans);
    dfs(root->right, val, ans);
}

int sumNumbers(struct TreeNode* root) {
    if (!root) return 0;

    ll ans = 0;
    dfs(root, 0, &ans);

    return (int)ans;
}
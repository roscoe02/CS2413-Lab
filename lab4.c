// 101. Symmetric Tree
typedef struct TreeNode NODE;

bool isMirror(NODE* node1, NODE* node2) {
    if (!node1 && !node2)
        return true;
    if (!node1 || !node2)
        return false;
    if (node1->val != node2->val)
        return false;
    return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}

// 200. Number of Islands
void dfs(char** grid, int i, int j, int rows, int* cols) {
    if (i < 0 || j < 0 || i >= rows || j >= cols[i] || grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        dfs(grid, i + di[k], j + dj[k], rows, cols);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (!grid || gridSize == 0)
        return 0;

    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j, gridSize, gridColSize);
                count++;
            }
        }
    }

    return count;
}

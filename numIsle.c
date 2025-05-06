void depthfirst(char** grid, int gridSize, int* gridColSize, int r, int c) {
    if (r < 0 || c < 0 || r >= gridSize || c >= gridColSize[r] ||
        grid[r][c] == '0') {
        return;
    }
    grid[r][c] = '0';
    depthfirst(grid, gridSize, gridColSize, r - 1, c);
    depthfirst(grid, gridSize, gridColSize, r + 1, c);
    depthfirst(grid, gridSize, gridColSize, r, c - 1);
    depthfirst(grid, gridSize, gridColSize, r, c + 1);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0)
        return 0;
    int count = 0;
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridColSize[r]; c++) {
            if (grid[r][c] == '1') {
                count++;
                depthfirst(grid, gridSize, gridColSize, r, c);
            }
        }
    }
    return count;
}

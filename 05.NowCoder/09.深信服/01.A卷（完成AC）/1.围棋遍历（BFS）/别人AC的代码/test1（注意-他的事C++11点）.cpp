#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
 
enum color {
    NONE, WHITE, BLACK,         //棋子颜色，NONE表示未落子
};
struct weiqi {
    enum color board[19][19];   //棋盘上每个位置的落子
};
 
int calc(struct weiqi *wq, int x, int y)
{
    //TODO:
    int row = y, col = x;
    enum color co = wq->board[row][col];
    if(co == NONE){
        return 0;
    }
    vector<vector<int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<vector<int> > q;
    q.push(vector<int>{row, col});
    int cnt = 1;
    wq->board[row][col] = NONE;
    while(!q.empty()){
        auto n = q.front();
        q.pop();
        for(auto d : dirs){
            int r = n[0] + d[0], c = n[1] + d[1];
            if(r < 0 || r >= 19 || c < 0 || c >= 19 || wq->board[r][c] != co){
                continue;
            }
            q.push(vector<int>{r, c});
            cnt++;
            wq->board[r][c] = NONE;
        }
    }
    return cnt;
}
int input(struct weiqi *wq, int *x, int *y)
{
    int row, col;
    int ret;
    char buf[80];
     
    for (row = 0; row < 19; ++row) {
        if (fgets(buf, sizeof(buf), stdin) == NULL)
            return -1;
        if (strlen(buf) < 19)
            return -1;
        for (col = 0; col < 19; ++col) {
            switch (buf[col]) {
            case '0':
                wq->board[row][col] = NONE;
                break;
            case '1':
                wq->board[row][col] = WHITE;
                break;
            case '2':
                wq->board[row][col] = BLACK;
                break;
            default:
                return -1;
            }
        }
    }
    ret = fscanf(stdin, "%d,%d\n", x, y);
    if (ret != 2)
        return -1;
    for (row = 0 ; row < 19; ++row) {
        for (col = 0; col < 19; ++col) {
            fprintf(stderr, "%d ", wq->board[row][col]);
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "x = %d, y = %d\n", *x, *y);
    return 0;
}
 
int main()
{
    struct weiqi wq;
    int x = 0, y = 0;
    int cnt;
 
    memset(&wq, 0, sizeof(wq));
    if (input(&wq, &x, &y) < 0) {
        fprintf(stderr, "error!\n");
        return 1;
    }
    cnt = calc(&wq, x, y);
 
    printf("%d\n", cnt);
    return 0;
}

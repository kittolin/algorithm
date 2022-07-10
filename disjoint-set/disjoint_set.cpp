
using namespace std;

const int MAXN = 100 + 10;

int father[MAXN];       // 记录每个节点的父节点，只有树根的父节点等于自己
int height[MAXN];       // 记录每个节点的高度

void Initial(int n) {
    for (int i = 0; i < n; i++) {
        // 一开始每个节点都是一个单独的集合
        father[i] = i;
        height[i] = 0;
    }
}

// 使用递归更容易实现路径压缩
int Find(int x) {
    if (x == father[x]) {
        return x;
    }
    father[x] = Find(father[x]);
    return father[x];
    // while (x != father[x]) {
    //     x = father[x];
    // }
    // return x;
}

// 非递归实现查询
int FindCircularly(int x) {
    int root = x;
    // 循环向上找到根结点
    while (root != father[root]) {
        root == father[root];
    }

    // 路径压缩
    while (x != root) {
        int tmp = father[x];    // 暂存 x 的父节点，避免丢失
        father[x] = root;       // x 直接挂到根节点下面
        x = tmp;
    }
    return root;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    // x，y 属于同一个集合，不用合并
    if (x == y) {
        return;
    }

    if (height[x] > height[y]) {
        father[y] = x;
    } else if (height[x] < height[y]) {
        father[x] = y;
    } else {
        father[y] = x;
        height[x] ++;
    }
}

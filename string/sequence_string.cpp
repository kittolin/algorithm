#define MAXLEN 255

typedef struct {
    char chs[MAXLEN];   // 位序从 1 开始
    int length;
} SString;

int next[MAXLEN];   // 若模式串的第 j 个字符失配，从模式串的第 next[j] 个字符继续匹配
int nextval[MAXLEN];

// 用 Sub 返回主串 S 的第 pos 个字符起长度为 len 的子串
bool SubString(SString &sub, SString s, int pos, int len) {
    if (pos + len - 1 > s.length) {     // 子串范围越界
        return false;
    }
    for (int i = pos; i < pos + len; i++) {
        sub.chs[i - pos + 1] = s.chs[i];
    }
    sub.length = len;
    return true;
}

// 比较。若 S > T，返回值 > 0；若 S = T，返回值 = 0；S < T，返回值 < 0
int StrCompare(SString s, SString t) {
    for (int i = 1; i <= s.length && i <= t.length; i++) {
        if (s.chs[i] != t.chs[i]) {
            return s.chs[i] - t.chs[i];
        }
    }
    return s.length - t.length; // 若扫描过的所有字符都相同，则长度长的串更大
}

// 朴素模式匹配算法
int Index(SString s, SString t) {
    int i = 1, j = 1;
    while (i <= s.length && j <= t.length) {
        if (s.chs[i] == t.chs[j]) {
            i ++;
            j ++;
        } else {    // 失配，指针后退重新匹配下一个子串
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > t.length) {
        return i - t.length;
    } else {
        return 0;   // 找不到对应的子串
    }
}

// KMP 算法，求 next 数组 O(m)，模式匹配 O(n)，故最坏时间复杂度 O(m + n)
int Index_KMP(SString s, SString t) {
    int i = 1, j = 1;
    while (i <= s.length && j <= t.length) {
        if (j == 0 || s.chs[i] == t.chs[j]) {
            i ++;
            j ++;
        } else {
            j = next[j];    // 主串指针不回溯
        }
    }

    if (j > t.length) {
        return i - t.length;
    } else {
        return 0;   // 找不到对应的子串
    }
}

// 由 next 数组推出 nextval 数组 
void NextToNextVal(SString t) {
    nextval[1] = 0;
    for (int j = 2; j <= t.length; j++) {
        if (t.chs[next[j]] == t.chs[j]) {
            nextval[j] = nextval[next[j]];
        } else {
            nextval[j] = next[j];
        }
    }
}

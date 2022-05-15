/*
* 名称：Biorhythms
* 来源：北京大学复试上机题
* 链接：http://985.so/xc4x
* 难度：中等
* 分析：给出三个周期的高峰，求另一个给定日期到这三个周期最近的同一天高峰的差值
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int PHY_PERIODS = 23;
const int EMO_PERIODS = 28;
const int INTEL_PERIODS = 33;

bool SameDate(int phy, int emo, int intel) {
    return phy == emo && emo == intel;
}

int NextTriplePeak(int phy, int emo, int intel, int date) {
    while (1) {
        // 有可能其中一个日期已经是最近的同一天高峰
        // 故最大值日期不动，非最大值日期移动一个周期，循环进行，直至这三个日期相同
        while (!SameDate(phy, emo, intel)) {
            int maximum = max(max(phy, emo), intel);
            if (phy < maximum) {
                phy += PHY_PERIODS;
            }
            if (emo < maximum) {
                emo += EMO_PERIODS;
            }
            if (intel < maximum) {
                intel += INTEL_PERIODS;
            }
        }

        if (phy > date) {
            return phy - date;
        } else {
            phy += PHY_PERIODS;
            emo += EMO_PERIODS;
            intel += INTEL_PERIODS;
        }
    }
}

int main() {
    int phy, emo, intel, date;
    while (scanf("%d %d %d %d", &phy, &emo, &intel, &date) != EOF) {
        printf("Case: the next triple peak occurs in %d days.\n", NextTriplePeak(phy, emo, intel, date));
    }
    return 0;
}

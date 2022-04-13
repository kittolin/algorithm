/*
* 名称：猫狗收容所
* 来源：程序员面试金典
* 链接：https://leetcode-cn.com/problems/animal-shelter-lcci/
* 难度：简单
*/

class AnimalShelf {
private:
    queue<int> dogs, cats;

public:
    AnimalShelf() {}

    void enqueue(vector<int> animal) {
        if (animal[1]) {
            dogs.push(animal[0]);
        } else {
            cats.push(animal[0]);
        }
    }

    vector<int> dequeueDog() {
        vector<int> v;
        if (dogs.empty()) {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }

        v.push_back(dogs.front());
        v.push_back(1);
        dogs.pop();
        return v;
    }

    vector<int> dequeueCat() {
        vector<int> v;
        if (cats.empty()) {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }

        v.push_back(cats.front());
        v.push_back(0);
        cats.pop();
        return v;
    }

    vector<int> dequeueAny() {
        vector<int> v;
        if (!dogs.empty() && !cats.empty()) {
            if (dogs.front() < cats.front()) {
                v = dequeueDog();
            } else {
                v = dequeueCat();
            }
            return v;
        }
        if (!dogs.empty()) {
            return dequeueDog();
        }
        if (!cats.empty()) {
            return dequeueCat();
        }

        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
};

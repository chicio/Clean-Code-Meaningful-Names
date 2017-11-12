#include <vector>

struct pt {
    float x;
    float y;
    float z;
};

struct mt {
public:
    float m[4][4];
};

class Obj {
public:
    bool act;
    mt matr;
    std::vector<pt> ms;
};

class GameManager {
public:
    
    GameManager(std::vector<Obj> anObjList){
        objList = anObjList;
    }
    
    std::vector<Obj> get() {
        std::vector<Obj> newObjList;
        for (auto currObj : newObjList) {
            if (currObj.act && currObj.ms.size() > 0) {
                newObjList.push_back(currObj);
            }
        }
        return newObjList;
    }
    
private:
    
    std::vector<Obj> objList;
};

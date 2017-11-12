#include <vector>

struct Point {
    float x;
    float y;
    float z;
};

struct Matrix {
public:
    float values[4][4];
};

class GameObject {
public:
    bool isActive;
    Matrix transformation;
    std::vector<Point> mesh;
};

class Scene {
public:
    
    Scene(std::vector<GameObject> newGameObjects){
        gameObjects = newGameObjects;
    }
    
    std::vector<GameObject> getValidGameObjects() {
        std::vector<GameObject> activeGameObjects;
        for (auto gameObject : gameObjects) {
            if (isValid(gameObject)) {
                activeGameObjects.push_back(gameObject);
            }
        }
        return activeGameObjects;
    }
    
private:
    
    std::vector<GameObject> gameObjects;
    
    bool isValid(GameObject gameObject) {
        return gameObject.isActive && isValid(gameObject.mesh);
    }
    
    bool isValid(std::vector<Point> mesh) {
        return mesh.size() > 0;
    }
};

#ifndef BULLET_H
#define BULLET_H

#include <SDL.h>
#include <vector>
#include "constants.h"
class Enemy;

class Bullet {
public:
    Bullet(int x, int y, int speedX, int speedY);
    void Update(std::vector<Enemy*>& enemies);
    void Render(SDL_Renderer* renderer, SDL_Rect camera);
    bool IsActive() const { return active; }
    void SetActive(bool isActive) { active = isActive; }

    int GetX() const { return x; }
    int GetY() const { return y; }

    SDL_Rect GetRect() const;
    void Deactivate();

private:
    int x, y;
    int speedX, speedY;
    bool active;
    bool CheckCollision(Enemy* enemy);
};

#endif

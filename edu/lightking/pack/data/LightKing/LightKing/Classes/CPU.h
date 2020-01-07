//
//  Model.h
//  LightKing
//
//  Created by TasukuTakahashi on 2013/08/31.
//
//

#ifndef __LightKing__CPU__
#define __LightKing__CPU__

#include "cocos2d.h"
#include "string.h"
#include "Player.h"

class CPU : public cocos2d::CCSprite
{
private:
    bool isJump;
    bool isRightHand;
    bool isRightDirection;
    cocos2d::CCLayerColor* parentLayer;
    Player* player;
    cocos2d::CCRect aRect;
    
public:
    static CPU* create(const char *aFileName, cocos2d::CCLayerColor* aBigLayer, Player* aPlayer);
    virtual bool init();
    cocos2d::CCAnimate* getActionAnimation(char aFileName[], int firstFrame, int lastFrame, int loops, float speed);
    cocos2d::CCRect getRect();
    void moveTo();
    void jump();
    void selectTool();
    void attack();
    cocos2d::CCSprite* getCPU();
};

#endif /* defined(__LightKing__CPU__) */

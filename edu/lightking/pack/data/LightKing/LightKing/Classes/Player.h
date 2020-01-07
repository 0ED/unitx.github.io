//
//  Model.h
//  LightKing
//
//  Created by TasukuTakahashi on 2013/08/31.
//
//

#ifndef __LightKing__Player__
#define __LightKing__Player__

#include "cocos2d.h"
#include "string.h"

class Player : public cocos2d::CCSprite
{
private:
    bool isJump;
    bool isRightHand;
    bool isRightDirection;
    cocos2d::CCLayerColor* parentLayer;
    cocos2d::CCRect aRect;
    
    
public:
    static Player* create(const char *aFileName, cocos2d::CCLayerColor* aBigLayer);
    virtual bool init();
    cocos2d::CCAnimate* getActionAnimation(char aFileName[], int firstFrame, int lastFrame, int loops, float speed);
    cocos2d::CCRect getRect();
    void moveToRight();
    void moveToLeft();
    void jump();
    void selectTool();
    void attack();
    cocos2d::CCSprite* getPlayer();
};

#endif /* defined(__LightKing__Player__) */

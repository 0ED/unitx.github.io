//
//  MainButton.h
//  LightKing
//
//  Created by TasukuTakahashi on 2013/09/08.
//
//

#ifndef __LightKing__MainButton__
#define __LightKing__MainButton__

#include "cocos2d.h"
#include "TapSprite.h"
#include "Player.h"
#include "CPU.h"
#include "cocos-ext.h"
using namespace cocos2d::extension;

class MainButton : public TapSprite
{
private:
    Player* player;
    CPU* enemy;
    CCScrollView* scrollView;
    cocos2d::CCSize windowSize;
    static const int CROSS_TOP = 5;
    static const int CROSS_RIGHT = 6;
    static const int CROSS_BOTTOM = 7;
    static const int CROSS_LEFT = 8;
    static const int ATTACK = 1;

    
public:
    static MainButton* create(const char *aFileName, cocos2d::CCPoint aPoint, int aMainButtonNumber, Player* aPlayer, CPU* anEnemy, CCScrollView *aScrollView);
    virtual bool ccTouchBegan(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
};

#endif /* defined(__LightKing__MainButton__) */

//
//  TapSprite.h
//  LightKing
//
//  Created by TasukuTakahashi on 2013/09/06.
//
//

#ifndef __LightKing__TapSprite__
#define __LightKing__TapSprite__

#include "cocos2d.h"

class TapSprite : public cocos2d::CCSprite, public cocos2d::CCTouchDelegate
{
public:
    static TapSprite* create(const char *aFileName);
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
};


#endif /* defined(__LightKing__TapSprite__) */

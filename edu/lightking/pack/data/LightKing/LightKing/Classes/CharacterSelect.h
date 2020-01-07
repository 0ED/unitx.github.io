//
//  CrossKey.h
//  LightKing
//
//  Created by TasukuTakahashi on 2013/09/08.
//
//

#ifndef __LightKing__CrossKey__
#define __LightKing__CrossKey__

//#include "cocos2d.h"
#include "TapSprite.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


class CharacterSelect : public TapSprite
{
public:
    static CharacterSelect* create(const char *aFileName);
    virtual bool ccTouchBegan(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent);
};

#endif /* defined(__LightKing__CrossKey__) */

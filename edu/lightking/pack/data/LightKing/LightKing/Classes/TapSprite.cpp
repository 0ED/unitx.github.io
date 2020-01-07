//
//  TapSprite.cpp
//  LightKing
//
//  Created by TasukuTakahashi on 2013/09/06.
//
//

#include "TapSprite.h"
USING_NS_CC;


TapSprite* TapSprite::create(const char *aFileName)
{
    TapSprite *aTapSprite = new TapSprite();
    if (aTapSprite && aTapSprite->initWithFile(aFileName))
    {
        aTapSprite->autorelease();
        return aTapSprite;
    }
    CC_SAFE_DELETE(aTapSprite);
    return NULL;
}

void TapSprite::onEnter()
{
    CCSprite::onEnter();
    CCTouchDispatcher* aDispatchear = CCDirector::sharedDirector()->getTouchDispatcher();
    aDispatchear->addTargetedDelegate(this, 0, true);
}

void TapSprite::onExit()
{
    CCSprite::onExit();
    CCTouchDispatcher* aDispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
    aDispatcher->removeDelegate(this);
}

bool TapSprite::ccTouchBegan(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
    CCPoint aPoint = aTouch->getLocation();
    CCSize aSize = this->getTexture()->getContentSize();
    CCRect aRect = CCRectMake(this->getPositionX() - aSize.width/2,
                              this->getPositionY() - aSize.height/2,
                              aSize.width, aSize.height );
    return aRect.containsPoint(aPoint);
}

void TapSprite::ccTouchMoved(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
    CCPoint aPoint = aTouch->getLocation();
    this->setPosition(aPoint);
}

void TapSprite::ccTouchEnded(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
}

void TapSprite::ccTouchCancelled(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
}

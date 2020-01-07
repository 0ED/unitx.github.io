//
//  CrossKey.cpp
//  LightKing
//
//  Created by TasukuTakahashi on 2013/09/08.
//
//

#include "CharacterSelect.h"

CharacterSelect* CharacterSelect::create(const char *aFileName)
{
    CharacterSelect *aCharacterSelect = new CharacterSelect();
    if (aCharacterSelect && aCharacterSelect->initWithFile(aFileName))
    {
        aCharacterSelect->autorelease();
        return aCharacterSelect;
    }
    CC_SAFE_DELETE(aCharacterSelect);
    return NULL;
}

bool CharacterSelect::ccTouchBegan(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
    if (!TapSprite::ccTouchBegan(aTouch, anEvent)){ return false; }

    cocos2d::CCScene *aScene = HelloWorld::scene();
    cocos2d::CCDirector::sharedDirector()->replaceScene(aScene);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Derezzed.wav", true);
    
    return true;
}



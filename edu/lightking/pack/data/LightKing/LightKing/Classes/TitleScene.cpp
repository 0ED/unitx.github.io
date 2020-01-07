//
//  TitleScene.cpp
//  LightKing
//
//  Created by TasukuTakahashi on 2013/09/09.
//
//

#include "TitleScene.h"
USING_NS_CC;

CCScene* TitleScene::scene()
{
    CCScene *aScene = CCScene::create();
    TitleScene *aLayer = TitleScene::create();
    aScene->addChild(aLayer);
    return aScene;
}


bool TitleScene::init()
{    
    if ( !CCLayerGradient::initWithColor(ccc4(30,30,255,0),ccc4(255,255,255,120),ccp(0.0f, 1.0f)) ) { return false; }
    
    CCMenuItemImage *aLeftButton = CCMenuItemImage::create("titleLeft.png", "titleLeftWhite.png", this, menu_selector(TitleScene::changeCharacterLeft) );
    CCMenuItemImage *aRightButton = CCMenuItemImage::create("titleRight.png", "titleRightWhite.png",this, menu_selector(TitleScene::changeCharacterRight) );
    
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
    aLeftButton->setPosition(ccp(0+50, windowSize.height/2));
    aRightButton->setPosition(ccp(windowSize.width-50, windowSize.height/2));
    CCMenu* aMenu = CCMenu::create(aLeftButton,aRightButton,NULL);
    aMenu->setPosition( CCPointZero );
    this->addChild(aMenu);
    this->convertChild(characterName[0]);
    
    CCDirector::sharedDirector()->setDisplayStats(false);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Recognizer.wav", true);
    return true;
}


void TitleScene::changeCharacterRight()
{
    if (nowCharacterNumber >= 2) { nowCharacterNumber = 0; }
    else { nowCharacterNumber++; }
    this->convertChild(characterName[nowCharacterNumber]);
    this->animate(characterName[nowCharacterNumber]);
}

void TitleScene::changeCharacterLeft()
{
    if (nowCharacterNumber <= 0) { nowCharacterNumber = 2; }
    else { nowCharacterNumber--; }
    this->convertChild(characterName[nowCharacterNumber]);
    this->animate(characterName[nowCharacterNumber]);
}

void TitleScene::convertChild(char aCharacterName[])
{
    if (characterName != NULL && characterName != NULL)
    {
        this->removeChild(character, true);
        this->removeChild(characterLabel, true);
    }
    
    char fileName[100] = {0};
    sprintf(fileName,"%s0001.png",aCharacterName);
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
    characterLabel =CCLabelTTF::create(aCharacterName,"arial",34);
    characterLabel->setColor(ccWHITE);
    characterLabel->setPosition( ccp(windowSize.width/2, (windowSize.height*1)/6) );
    this->addChild(characterLabel);
    
    character = CharacterSelect::create(fileName);
    character->setPosition( ccp(windowSize.width/2, (windowSize.height*3)/5) );
    this->addChild(character);
}

void TitleScene::animate(char aCharacterName[])
{
    CCAnimation* animation = CCAnimation::create();
    for (int index = 1; index <= 12; index++)
    {
        char names[100] = {0};
        sprintf(names, "%s%04d.png", aCharacterName, index);
        animation->addSpriteFrameWithFileName(names);
    }
    animation->setDelayPerUnit(0.20f / 3.0f);
    animation->setRestoreOriginalFrame(true);
    animation->setLoops(1);
    CCAnimate* animatedAction = CCAnimate::create(animation);
    
    character->runAction(animatedAction);
}


void TitleScene::menuChangeScene(CCObject *pSender) {}



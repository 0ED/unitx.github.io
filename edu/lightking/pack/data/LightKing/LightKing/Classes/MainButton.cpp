//
//  MainButton.cpp
//  LightKing
//
//  Created by TasukuTakahashi on 2013/09/08.
//
//

#include "MainButton.h"
MainButton* MainButton::create(const char *aFileName, cocos2d::CCPoint aPoint, int aMainButtonNumber, Player* aPlayer, CPU* anEnemy, CCScrollView *aScrollView)
{
    MainButton *aMainButton = new MainButton();
    if (aMainButton && aMainButton->initWithFile(aFileName))
    {
        aMainButton->autorelease();
        aMainButton->player = aPlayer;
        aMainButton->enemy = anEnemy;
        aMainButton->windowSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
        aMainButton->scrollView = aScrollView;
        aMainButton->setTag(aMainButtonNumber);
        aMainButton->setPosition(aPoint);
        return aMainButton;
    }
    CC_SAFE_DELETE(aMainButton);
    return NULL;
}

bool MainButton::ccTouchBegan(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
    if (!TapSprite::ccTouchBegan(aTouch, anEvent)){ return false; }
    
    if (this->getTag() == CROSS_TOP)
    {
        player->jump();
    }
    else if (this->getTag() == CROSS_RIGHT)
    {
        player->moveToRight();
    }
    else if (this->getTag() == CROSS_BOTTOM)
    {
        player->selectTool();
    }    else if (this->getTag() == CROSS_LEFT) {
        player->moveToLeft();
    } 
    else if (this->getTag() == ATTACK) {
        player->attack();
        if (player->getRect().intersectsRect(enemy->getRect()) )
        {
            CCLOG("アタックチャンス");
        }
    }
    return true;
}

void MainButton::ccTouchMoved(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
}

void MainButton::ccTouchEnded(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
    player->stopAllActions();

    float x = player->getPositionX() + (enemy->getPositionX() - player->getPositionX()) / 2;
    float y = player->getPositionY() + (enemy->getPositionY() - player->getPositionY()) / 2;    
    scrollView->setContentOffset(ccp(windowSize.width/2-x, windowSize.height/2-y-30),true);
}

void MainButton::ccTouchCancelled(cocos2d::CCTouch *aTouch, cocos2d::CCEvent *anEvent)
{
}



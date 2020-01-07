#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

bool HelloWorld::init()
{
    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 40)) ) { return false; }
    CCLayerColor *bigLayer = CCLayerColor::create();
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
    
    //ステージ    
    CCSprite *aBackground = CCSprite::create("Tron.png");
    aBackground->setScale(0.60);
    aBackground->setPosition(ccp(windowSize.width/2, windowSize.height/2));
    bigLayer->addChild(aBackground,1);
        
    //自分
    player = Player::create("LightFoxRunToRight0001.png", bigLayer);
    player->setPosition(ccp(CHARACTER_X, GROUND_LINE_HEIGHT));
    player->setScale(0.5);
    bigLayer->addChild(player,2);
    
    //相手
    enemy = CPU::create("LightFoxRunToLeft0001.png", bigLayer, player);
    enemy->setPosition(ccp(windowSize.width - CHARACTER_X, GROUND_LINE_HEIGHT ));
    enemy->setScale(0.5);
    bigLayer->addChild(enemy,1);
    
    this->schedule(schedule_selector(HelloWorld::update), 1.8);
    
    //スクロール
    CCScrollView *aScrollView = CCScrollView::create(windowSize);
    aScrollView->setContainer(bigLayer);
    this->addChild(aScrollView,0);
    float x = player->getPositionX() + (enemy->getPositionX() - player->getPositionX()) / 2;
    float y = player->getPositionY() + (enemy->getPositionY() - player->getPositionY()) / 2;
    aScrollView->setContentOffset(ccp(windowSize.width/2-x, windowSize.height/2-y-30),false);
    
    setButton(aScrollView);
    setBar();
    bigLayer->setTouchMode(kCCTouchesAllAtOnce);
    bigLayer->setTouchEnabled(true);
    CCDirector::sharedDirector()->setDisplayStats(false);
    
    return true;
}

void HelloWorld::update()
{
    enemy->moveTo();
}


void HelloWorld::setBar()
{
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
    CCSprite *aBar = CCSprite::create("bar_main.png");
    aBar->setPosition(ccp(windowSize.width/2, windowSize.height - aBar->getContentSize().height/2 - 3) );
    this->addChild(aBar,1);
    
    CCSprite *aBarGauge = CCSprite::create("bar_gauge_main.png");
    aBarGauge->setPosition(ccp(windowSize.width/2, windowSize.height - aBar->getContentSize().height/2 - 3) );
    this->addChild(aBarGauge,0);
    
    aBarGauge->setVertexRect(CCRectMake(aBarGauge->getPositionX(), aBarGauge->getPositionY(), aBarGauge->getContentSize().width, aBarGauge->getContentSize().height) );
}


void HelloWorld::setButton(CCScrollView *aScrollView)
{
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
    
    MainButton *aTopButton = MainButton::create("top.png", ccp(CURSOR_LOCATION_X, CURSOR_LOCATION_Y + CURSOR_MARGIN), 5, player, enemy, aScrollView);
    MainButton *aRightButton = MainButton::create("right.png",ccp(CURSOR_LOCATION_X + CURSOR_MARGIN,CURSOR_LOCATION_Y), 6, player, enemy, aScrollView);
    MainButton *aBottomButton = MainButton::create("bottom.png",ccp(CURSOR_LOCATION_X,CURSOR_LOCATION_Y - CURSOR_MARGIN), 7, player, enemy, aScrollView);
    MainButton *aLeftButton = MainButton::create("left.png",ccp(CURSOR_LOCATION_X - CURSOR_MARGIN,CURSOR_LOCATION_Y), 8, player, enemy, aScrollView);
    MainButton *anAttackButton = MainButton::create("attackButton.png",ccp(windowSize.width- CURSOR_LOCATION_X, CURSOR_LOCATION_Y), 1, player, enemy, aScrollView);

    this->addChild(aTopButton,1);
    this->addChild(aRightButton,1);
    this->addChild(aBottomButton,1);
    this->addChild(aLeftButton,1);
    this->addChild(anAttackButton ,1);
}






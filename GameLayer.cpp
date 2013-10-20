/*

Background music:
Blipotron by Kevin MacLeod (incompetech.com)

*/


#include "GameLayer.h"

GameLayer::~GameLayer () {
	CC_SAFE_RELEASE(_gameBatchNode);
    
}

CCScene* GameLayer::scene() {
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init() {
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() ) {
        return false;
    }
    
    //get screen size
	_screenSize = CCDirector::sharedDirector()->getWinSize();

	//create game screen
	createGameScreen();

	//listen for touches
    this->setTouchEnabled(true);
    
    //create main loop
    this->schedule(schedule_selector(GameLayer::update));
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3", true);
    return true;
}


void GameLayer::update (float dt) {

}

void GameLayer::ccTouchesBegan(CCSet* pTouches, CCEvent* event) {
    
}


void GameLayer::createGameScreen() {

    //add bg
    CCSprite * bg = CCSprite::create("bg.png");
    bg->setPosition(ccp(_screenSize.width * 0.5f, _screenSize.height * 0.5f));
    this->addChild(bg);

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("sprite_sheet.plist");
	_gameBatchNode = CCSpriteBatchNode::create("sprite_sheet.png");
	this->addChild(_gameBatchNode);

}

#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#include "SimpleAudioEngine.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace CocosDenshion;

class GameLayer : public CCLayer {
private:
	CCSize _screenSize;
	CCSpriteBatchNode * _gameBatchNode;
    
    void createGameScreen (void);
    
public:
    
    ~GameLayer(void);
    
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
    
    virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
   
    virtual void update (float dt);
};

#endif // __GAMELAYER_H__
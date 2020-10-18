#ifndef CONFIG_H
#define CONFIG_H

/****游戏配置数据****/
#define GAME_RATE 5 //每5毫秒更新一次元素位置

/****地图配置数据****/
#define MAP_RATES 1 //地图滚动速度
#define MAP_HEIGHT 768
#define MAP_WIDTH 512
#define MAP_PATH "://res/img_bg_level_3.jpg"
#define SOUND_BACKGROUND "://res/bg.wav" //背景音效

/****玩家飞机配置数据****/
#define HEROPLANE_PATH "://res/hero.png"
#define HERO_PLANE_HORIZONTAL_INCREMENT 20
#define HERO_PLANE_VERTICAL_INCREMENT 15
#define BULLET_TRIGGER_INTERVAL 40 //发射子弹的间隔
#define BULLETS_NUM 7 //弹匣中子弹数量
#define HERO_HP 15 //血量

/****子弹配置数据****/
#define BULLET_PATH "://res/bullet_11.png"
#define BULLET_SPEED 3 //子弹移动速度
#define BULLET_PATH_ENEMY "://res/bullet_4.png"

/****敌机配置数据****/
#define ENEMY_PLANE_INCREMENT 2
#define BOSS_INCREMENT 1
#define ENEMY_PATH "://res/img-plane_4.png"
#define ENEMY_PATH2 "://res/img-plane_7.png"
#define ENEMY_PATH3 "://res/hero2.png"
#define ENEMY_INTERVAL 200 //敌机出场间隔
#define ENEMY_WIDTH 68 //图片宽度
#define ENEMY_HEIGHT 100 //图片高度
#define ENEMIES_NUM 3 //敌机数量
#define ENEMY_HP 2 //敌机血量
#define BOSS_HP 20 //BOSS血量
#define ENEMY_BULLETS_NUM 2 //敌机弹匣中子弹数量
#define ENEMY_BULLET_TRIGGER_INTERVAL 160 //发射子弹的间隔

/****爆炸配置数据****/
#define BOMB_PATH ":/res/bomb-%1.png" //爆炸资源图片
#define BOMB_INTERVAL 40 //爆炸切图时间间隔
#define BOMB_MAX_INDEX 6 //最大索引
#define BOMB_NUM 3 //爆炸数量
#define SOUND_BOMB "://res/bomb.wav" //爆炸音效

#endif // CONFIG_H

//
// Created by Lokilanka on 2019/5/11.
//

#ifndef C_BIG_WORK_SYSFUNCTION_H
#define C_BIG_WORK_SYSFUNCTION_H

#include <genlib.h>
#include <stdlib.h>
#include <Linkedlist.h>

#define FALLINGINTERVAL 20
#define JUMPINGINTERVAL 10
#define AIDJUMPINTERVAL 300
#define OBSTACLEMOVEINTERVAL 100
#define ACCELERATEINTERVAL 5000
#define ITEMMOVINGINTERVAL 100
#define NOJUDGEINTERVAL 2000
#define JUDGEITEMINTERVAL 1
#define IMMORTALINTERVAL 3000
#define SHOWLIFEINTERVAL 1
#define MENUINTERVAL 1
#define TIMEINTERVAL 1000


typedef enum {
    AIDJUMPID,
    FALLINGID,
    JUMPID,
    OBSTACLEMOVEID,
    ACCELERATIONID,
    ITEMMOVINGID,
    NOJUDGEID,
    JUDGEITEMID,
    LIFEID,
    MENUID,
    TIMEID
} TimerIDD;

void CharEventProcess(char ch);

void MouseEventProcess(int x, int y, int button, int event);

/*
 * ���̻ص�����
 */
void KeyboardEventProcess(int key, int event);

/*
 * ��ʱ���ص�����
 */
void TimerEventProcess(int TID);

/*
 * ���±߽��жϺ���
 */
bool JudgeBorder();

/*
 * �ϰ�����ײ�жϺ���
 */
bool JudgeObstacle();

/*
 * ��Ʒ��ײ�жϺ���
 */
bool JudgeItem();

/*
 * ��ʼ����Ϸ
 */
void InitGame();

/*
 * ��Ϸʧ��
 */
void GameOver();

/*
 * ����
 */
void Retry();

/*
 * ��ͣ��Ϸ
 */
void PauseGame();

/*
 * ������Ϸ
 */
void Resume();

/*
 * ��Ϸ����
 */
void DataSave(PLAYERINFO *phead);

/*
 * ��Ϸ����
 */
PLAYERINFO *DataLoad();

/*
 * ������Ϸ��¼
 */
PLAYERINFO *UpdateData(PLAYERINFO *phead, int Score, char *name);

#endif //C_BIG_WORK_SYSFUNCTION_H

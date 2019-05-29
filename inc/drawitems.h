//
// Created by Lokilanka on 2019/5/11.
//

#ifndef C_BIG_WORK_DRAWITEMS_H
#define C_BIG_WORK_DRAWITEMS_H

#include <genlib.h>

#define PI 3.1415926545

/*
 * �����ϰ�������ö��
 */
typedef enum {
    TRIANGLE,
    PIPE,
    WARNING
} OBSTYPE;

typedef enum {
    BASKETBALL,
    CUREBAG,
    SPEEDDOWN,
    IMMORTAL
} ITEMTYPE;

/*
 * �ϰ������Խṹ��
 * ���ͣ����꣬���
 */
typedef struct obs {
    OBSTYPE obstacleType;
    double obstacleX;
    double obstacleY;
    double width;
} OBSTACLE;

typedef struct item {
    bool isitem;
    ITEMTYPE itemtype;
    double itemX;
    double itemY;
} ITEM;


/*ͼ����ƹ������õ����Դ�����*/

void LXLforward(double distance, double Angle);

/*
 *�ص�ǰ�����ߣ�����Ϊdistance����distanceΪ����ʱ����(LXL����ͼ��ʹ�ã�
 */

void LXLmove(double x, double y, double distance, double Angle);
/*
 *�ص�ǰ�����ƶ��ʣ������ߣ�������Ϊdistance����distanceΪ����ʱ����(LXL����ͼ��ʹ�ã�
 */

/*ͼ�꺯��*/

void DrawRoadobstacle(double x, double y, double width, double heigt);

void ClearPreroadobstacle(double x, double y, double width, double height);

/*
 *������·�ϣ�����x,yΪ������������Ķ��㣬��Ϊ���α߿�������һ���ߵ��е㣬�ú������ڳ�Ϊheight����Ϊwidth�ľ����У�����һ�������κ�ɫ��ɫ��ɫ����·��
 */

void DrawCurebag(double x, double y);

void ClearPrecurebag(double x, double y);

/*
 *ʮ�������ư�������x,yΪʮ�������С��������϶��㣬ʮ������Ϊ��ɫ����С��0.4*0.4�������α߿�֮��
 */

void DrawSpeeddown(double x, double y);

void ClearPrespeeddown(double x, double y);

/*
 *������������ɵļ��ٵ��ߣ�����x,yΪ����������ε����϶��㣬��ͷ����Ϊ������0.4*0.4�������α߿�֮��
 */

void DrawImmortal(double x, double y);

void ClearPreimmortal(double x, double y);

/*
 *�����ε��޵е��ߣ�����x,yΪ�����ε����϶��㣬��0.4*0.4�������α߿��У�ӡ��������ʦ������
 */

void DrawBasketball(double x, double y);

void ClearPrebasketball(double x, double y);

/*
 *��һ���뾶Ϊ0.2����������x,yΪ�����Բ�ģ���ɫΪ��ɫ���м��к�ɫ����
 */

void DrawCxk(double x, double y, int unstoppable);

void ClearpreCxk(double x, double y, int unstoppable);

void DrawCxkHead(double x, double y, int unstoppable);

void DrawCxkBody(double x, double y, int unstoppable);

void DrawCxkTie(double x, double y, int unstoppable);

void DrawCxkLeg(double x, double y, int unstoppable);

void DrawCxkTwo(double x, double y, int unstoppable);

void ClearpreCxkTwo(double x, double y, int unstoppable);

void DrawCxkBodyTwo(double x, double y, int unstoppable);

void DrawCxkTieTwo(double x, double y, int unstoppable);

void DrawCxkLegTwo(double x, double y, int unstoppable);

void DrawLife(double x, double y, int life);

void ClearpreLife(double x, double y, int life);

void DrawColumn(double x, double y, double width, double height);

void ClearPrecolumn(double x, double y, double width, double height);

/*
 * ��һ����Ϊheight����Ϊwidth����ɫ�ܵ��Ľ��棬x,yΪ�����ε����϶���
 */

void DrawWarningsign(double x, double y, double width, double height);

void ClearPrewarningsign(double x, double y, double width, double height);
/*
 * ��һ������߶�Ϊheight�����Ϊwidth�Ļƺ�ɫ��ʾ�ƣ�����ͼ�������Ϸ�Բ�Σ��м��ֱ�ߣ��·�������ɣ�x,yΪԲ�ε�Բ��
 */

void DrawBackground();
/*
 * ������Ϸ�ı���
 */

#endif //C_BIG_WORK_DRAWITEMS_H

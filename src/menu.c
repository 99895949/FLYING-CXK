#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "imgui.h"
#include <Linkedlist.h>
#include <sysfunction.h>
#include <menu.h>
#include <math.h>

static double winwidth = 10, winheight = 7;

extern char *NAME;
extern PLAYERINFO *data;
extern TIMESCORE;
extern SCORE;

int InMenu = 1;
int EnteringName = 0;
int InRank = 0;
int InHelpWindow = 0;
int InAboutWindow = 0;
int PlayingGame = 0;
int gameover = 0;


PLAYERINFO *head = NULL, *ptr = NULL;

void drawMenu() {
    SetPointSize(16);

    static char *menuListTool[] = {"Tool",
                                   "Start",
                                   "Rank",
                                   "Exit | Ctrl-E"};
    static char *menuListHelp[] = {"Help",
                                   "Help | Ctrl-H",
                                   "About",
                                   "Donate"};
    static char *selectedLabel = NULL;

    double fH = GetFontHeight();
    double x = 0;
    double y = winheight;
    double h = fH * 1.5;
    double w = TextStringWidth(menuListHelp[0]) * 2;
    double wlist = TextStringWidth(menuListTool[3]) * 1.2;
    int selection;

    selection = menuList(GenUIID(0), x, y - h, w, wlist, h, menuListTool,
                         sizeof(menuListTool) / sizeof(menuListTool[0]));
    if (selection > 0) selectedLabel = menuListTool[selection];
    if (selection == 1) { // need to modify
        EnteringName = 1;
        InMenu = 0;
        PlayingGame = !PlayingGame;
    }
    if (selection == 2) {
        InRank = 1;
        InMenu = 0;
    }
    if (selection == 3) {
        DataSave(data);
        ExitGraphics();
    }
    selection = menuList(GenUIID(0), x + w, y - h, w, wlist, h, menuListHelp,
                         sizeof(menuListHelp) / sizeof(menuListHelp[0]));
    if (selection > 0) selectedLabel = menuListHelp[selection];
    if (selection == 1) {
        InHelpWindow = 1;
        InMenu = 0;
    }
    if (selection == 2) {
        InAboutWindow = 1;
        InMenu = 0;
    }
}

void StartInterface() {

    SetPointSize(24);

    double fh = GetFontHeight();
    double x;
    double y = 6;

    SetPointSize(48);
    x = GetWindowWidth() / 2 - TextStringWidth("FLYING CXK") / 2;
    drawLabel(x, y, "FLYING CXK");

    char *Labels[] = {
            "CXK���ʵĳ�������Rap����������ջ�������˿",
            "�����������ڷ�����CXK�߳���������",
            "CXK��ô�������������ɵ����������Ƕ�����������",
            "��ʱ���ʹ��ϵ����㣬������ʦ��׼����ż����ϰ�����ֳ�չ����������׵�����ʵ��",
            "��ס�ڷ۵���......"
    };

    SetPointSize(20);
    SetPenColor("Black");

    for (int i = 0; i < 5; i++) {
        x = GetWindowWidth() / 2 - TextStringWidth(Labels[i]) / 2;
        y = y - fh * 1.5;
        drawLabel(x, y, Labels[i]);
    }
}

void drawButtons() {

    SetPointSize(28);
//    SetPenSize(4);

    double fH = GetFontHeight();
    double h = fH * 2;
    double w = TextStringWidth("PLAY") * 2;
    double x = winwidth / 2 - w / 2;
    double y = winheight * 2 / 7;

    if (Mybutton(GenUIID(0), x, y, w, h, "PLAY", 1)) {
        EnteringName = 1;
        InMenu = 0;
//      PlayingGame = 1;
    }

    if (Mybutton(GenUIID(0), x + 1.5 * w, y, w, h, "RANK", 1)) {
        InRank = 1;
        InMenu = 0;
    }

    if (Mybutton(GenUIID(0), x - 1.5 * w, y, w, h, "HELP", 1)) {
        InHelpWindow = 1;
        InMenu = 0;
    }

}

void ShowHelpWindow() {

    SetPenColor("Black");
    SetPointSize(20);
    drawLabel(2, 3.5, "����ָ�ϣ��ո�-��Ծ��Ctrl+E-�˳���Ϸ��F1-��ͣ��F2-����");

    if (PressESC()) {
        InHelpWindow = 0;
        InMenu = 1;
    }
}

void ShowAboutWindow() {

    SetPenColor("Black");
    SetPointSize(32);
    double fh = GetFontHeight();
    double x;
    double y = 5;

    SetPointSize(24);
    x = GetWindowWidth() / 2 - TextStringWidth("FLYING CXK�ǻ���libgraphics�Ĵ���������") / 2;
    drawLabel(x, y, "FLYING CXK�ǻ���libgraphics�Ĵ���������");

    SetPointSize(32);
    fh = GetFontHeight();

    x = GetWindowWidth() / 2 - TextStringWidth("����Ļ���") / 2;
    y = y - fh * 1.5;
    drawLabel(x, y, "����Ļ���");

    x = GetWindowWidth() / 2 - TextStringWidth("�����Ķ���") / 2;
    y = y - fh * 1.5;
    drawLabel(x, y, "�����Ķ���");

    x = GetWindowWidth() / 2 - TextStringWidth("�Ըе�kunkun") / 2;
    y = y - fh * 1.5;
    drawLabel(x, y, "�Ըе�kunkun");

    SetPointSize(24);

    x = GetWindowWidth() / 2 - TextStringWidth("��Ҫ�ģ����Ƕ�û��") / 2;
    y = y - fh * 1.5;
    drawLabel(x, y, "��Ҫ�ģ����Ƕ�û��");

    x = GetWindowWidth() / 2 - TextStringWidth("����׾��������һЦ") / 2;
    y = y - fh * 1.5;
    drawLabel(x, y, "����׾��������һЦ");


    if (PressESC()) {
        InAboutWindow = 0;
        InMenu = 1;
    }
}

void EnterName() {

    SetPointSize(32);

    double fH = GetFontHeight();
    double h = fH * 2;
    double x = winwidth / 2 - TextStringWidth("Enter Your Name") / 2;
    double y = winheight * 5 / 9;
    double w = TextStringWidth("____________________") + GetFontAscent();

    MovePen(x, y);
    SetPenColor("Black");
    DrawTextString("Enter Your Name");

    x = winwidth / 2 - w / 2;
    y = y - 1.5 * h;

//    SetPenSize(4);

    static char entername[20] = "";
    if (Textbox(x, y, w, h, entername, sizeof(entername)) != NULL) {

        NAME = Textbox(x, y, w, h, entername, sizeof(entername));
//        SetPenSize(1);
        EnteringName = 0;
        DisplayClear();

        InitGame();
    }
}

void drawGamingButtons() {
    char *Lables[] = {"Exit", "Resume", "Pause"};

    SetPointSize(16);

    double fH = GetFontHeight();

    double h = fH * 1.5;
    double w = TextStringWidth(Lables[1]) * 1.6;
    double x = 0;
    double y = winheight - h;

    if (Mybutton(GenUIID(0), x, y, w, h, Lables[0], 0)) { // Exit
        DataSave(data);
        ExitGraphics();
    }

    if (Mybutton(GenUIID(0), x + w, y, w, h, Lables[1], 0)) { // Resume
        Resume();
    }

    if (Mybutton(GenUIID(0), x + 2 * w, y, w, h, Lables[2], 0)) { // Pause
        PauseGame();
    }
}

void ShowRank(PLAYERINFO *phead) {

    DisplayClear();

    PLAYERINFO *cur = phead->next;

    SetPointSize(28);

    double RT_h = GetFontHeight() * 1.5;
    double RT_w1 = winwidth / 12;
    double RT_w2 = TextStringWidth("______________________") * 1.2;
    double RT_w3 = winwidth / 6;
    double RT_x = winwidth / 2 - (RT_w1 + RT_w2 + RT_w3) / 2;
    double RT_y = winheight * 3 / 4;

    char No[10][3] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

    SetPenColor("Black");

    SetPointSize(40);
    drawLabel(winwidth / 2 - TextStringWidth("RANK") / 2, RT_y + GetFontHeight() * 1.4, "RANK");

    SetPointSize(28);
    int i;
    for (i = 0; i < 10; i++) {
        if (cur && cur->score >= 0) {
            char *RankScore = NumberToChar(cur->score);
            drawBox(RT_x, RT_y - i * RT_h, RT_w1, RT_h, 0, No[i], 'M', "Black");
            drawBox(RT_x + RT_w1, RT_y - i * RT_h, RT_w2, RT_h, 0, cur->name, 'M', "Black");
            drawBox(RT_x + RT_w1 + RT_w2, RT_y - i * RT_h, RT_w3, RT_h, 0, RankScore, 'M', "Black");
            cur = cur->next;
        } else {
            drawBox(RT_x, RT_y - i * RT_h, RT_w1, RT_h, 0, NULL, 'M', "Black");
            drawBox(RT_x + RT_w1, RT_y - i * RT_h, RT_w2, RT_h, 0, NULL, 'M', "Black");
            drawBox(RT_x + RT_w1 + RT_w2, RT_y - i * RT_h, RT_w3, RT_h, 0, NULL, 'M', "Black");
        }
    }

    if (PressESC()) {
        DisplayClear();
        InRank = 0;
        InMenu = 1;
    }
}

void ShowScore(int score) {

    SetPointSize(16);

    double fH = GetFontHeight();
    double w = TextStringWidth("SCORE:00000");
    double x = winwidth - 1.1 * w - 1.2;
    double y = winheight - (0.3 - fH) / 2 - fH;

    char ShowScore[12] = "SCORE:";
    strcat(ShowScore, NumberToChar(score));

    MovePen(x, y);
    DrawTextString(ShowScore);
}

void ClearScore(int score) {
    SetPenColor("White");
    SetPointSize(16);

    double fH = GetFontHeight();
    double w = TextStringWidth("SCORE:00000");
    double x = winwidth - 1.1 * w - 1.2;
    double y = winheight - (0.3 - fH) / 2 - fH;

    char ShowScore[12] = "SCORE:";
    strcat(ShowScore, NumberToChar(score));

    MovePen(x, y);
    DrawTextString(ShowScore);
    SetPenColor("Black");
}

void ShowGameOver() {
    SetPointSize(24);

    double fh = GetFontHeight();
    double x;
    double y = 5.7;

    SetPointSize(48);
    x = GetWindowWidth() / 2 - TextStringWidth("��ò�") / 2;
    drawLabel(x, y, "��ò�");

    char *Labels[] = {
            "��ʹȫ���綼�ں���������Ҳ��վ��ȫ������һ��(=?��?=)",
            "�㲻Ҫ�ٺ�Cxk�ˣ���֪��kunkun�ж�Ŭ���𣿷����Ҳ�֪��",
            "��ֻ��һ��·���Ҷ�������ȥ��",
            "���������˼����������ȥ��,�˼Ҹ����ֲ���ʶ"
    };

    SetPointSize(20);
    SetPenColor("Black");

    for (int i = 0; i < 4; i++) {
        x = GetWindowWidth() / 2 - TextStringWidth(Labels[i]) / 2;
        y = y - fh * 1.5;
        drawLabel(x, y, Labels[i]);
    }

    SetPointSize(32);
//    SetPenSize(4);

    double fH = GetFontHeight();
    double h = fH * 1.5;
    double w = TextStringWidth("RETRY") * 2;

    x = winwidth / 2 - w / 2;
    y = winheight * 3 / 8;

    SetPenColor("Black");

    if (Mybutton(GenUIID(0), x, y, w, h, "RETRY", 1)) {
        gameover = 0;
        Retry();
//        DisplayClear();
    }

    if (Mybutton(GenUIID(0), x, y - h * 1.5, w, h, "EXIT", 1)) {
        DataSave(data);
        ExitGraphics();
    }

}

void display() {



    if (InMenu) {
        DisplayClear();
        drawMenu();
        drawButtons();
        StartInterface();
        data = DataLoad();
    }

    if (PlayingGame) {
        drawGamingButtons();
    }

    if (InHelpWindow) {
        DisplayClear();
        ShowHelpWindow();
    }

    if (InAboutWindow) {
        DisplayClear();
        ShowAboutWindow();
    }

    if (EnteringName) {
        DisplayClear();
        EnterName();
    }

    if (InRank) {
        ShowRank(data);
    }

    if (gameover) {
        DisplayClear();
        ShowGameOver();

    }
}

char *NumberToChar(int n) {
    int tempn = n, d, i, count = 0;
    char *num = (char *) malloc(6 * sizeof(char));

    while (tempn) {
        tempn = tempn / 10;
        count++;
    }
    for (i = 0; i < 5 - count; ++i) {
        num[i] = '0';
    }
    for (i = 4; i >= 5 - count; i--) {
        d = n % 10;
        num[i] = '0' + d;
        n /= 10;
    }
    num[5] = 0;
    return num;
}


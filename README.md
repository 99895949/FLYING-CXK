# Flappy xk's basketball
## 角色设计&场景设计
* 篮球(两个参数：横坐标， 纵坐标（半径==0.25）)
* 尖刺(四个参数：尖刺数量（0，3），长， 宽， 上下间隔)
* 血条显示(一个参数：血量（0，3）)
* 背景（）

## 功能实现
* ~~空格键跳跃~~
* ~~F1 retry F2 pause F3 resume~~
* 三种物品：加速， 补血， 穿墙 5s（图标正方形边长为0.25）（两个参数：横坐标， 纵坐标）
* 血量: 3
* 得分设计(显示)
* 场景变化速度随时间加快
* 触碰判断


## 菜单
* 新游戏
* 用户创建（记录保存， 链表）
* 排行榜
* ~~退出~~
* ~~暂停~~
* 帮助文档（介绍游戏操作和内容）

## 文件&分工
* 绘画 （场景角色血条）黄 **写到drawitems.h/.c里**
* 菜单 郭 **建立menu.h/.c写**
* 程序逻辑与组织（Main）薛
* 物品图标 李 **建立icons.h/.c写**


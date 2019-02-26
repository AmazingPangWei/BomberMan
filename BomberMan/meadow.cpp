#include "meadow.h"
#include <QDebug>
#include <boom.h>
Meadow::Meadow(QWidget *parent) :
    QWidget(parent)
{
    IfBoom=0;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    pix_up.load(":/new/prefix1/素材/爆炸特效（上）.png");
    pix_down.load(":/new/prefix1/素材/爆炸特效（下）.png");
    pix_left.load(":/new/prefix1/素材/爆炸特效（左）.png");
    pix_right.load(":/new/prefix1/素材/爆炸特效（右）.png");
    flag=0;
    drawBackGround();
    man= new Man(this);
    DrawMan();      //人必须在两种墙之前画出来，谁先画出来谁重叠时被覆盖
    DrawFeWall();   //先画出铁墙
    DrawWall();     //画出砖墙
    DrawTool();     //画出道具
    DrawBomb();     //画炸弹
    DrawMonster1(); //画小怪
    Press = 0;
    countTimer = new QTimer(this);
}
void Meadow::StartGame(){  //开始游戏
    countTimer->start(500);
    qDebug() << QString("jishijishijsijfishif");
    toalTime = 0;
    connect(countTimer, SIGNAL(timeout()), this, SLOT(countTime()));
}
void Meadow::countTime(){  //计时
 //   qDebug() << QString("jishijishijsijfishif");
    toalTime += 0.5;
}
void Meadow::StopGame(){   //停止游戏
    myThread.stop();  //小怪线程停止
    man->Dead();      //停止游戏，人不动
}
void Meadow::DrawMonster1(){ //画出小怪
    int wx, wy;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i = 0; i < 10; i++){
        wx = qrand() % MAX_X;
        wy = qrand() % MAX_Y;
        while(status[wx][wy] != 0 || (wx < 6 && wy < 6)){
            wx = qrand() % MAX_X;
            wy = qrand() % MAX_Y;
        }
        monster1[i] = new Monster1(this);
        monster1[i]->move(labels[wx][wy]->x(), labels[wx][wy]->y());
    }
    myThread.start();       //开始一个线程
    connect(&myThread, SIGNAL(Running(int)), this, SLOT(MonsterRunning(int)));
}
void Meadow::MonsterRunning(int i){ //小怪的运动
    if(toalCore >= 1000){   //小怪都死亡了，结束mythread线程
        myThread.stop();
    }

    for(int id = 0; id < 10; id++){
        if(monster1[id]->islive == 0){
            continue;
        }
        int count = 0;
        int x = monster1[id]->x() / 35;
        int y = monster1[id]->y() / 35;
        if(i % 25 == 0 && monster1[id]->running == 0){
//            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            monster1[id]->fang = qrand() % 4;
        }
        while(count <= 4){ //寻找运动的方向，最多找四次
            if((monster1[id]->running == 0 && monster1[id]->fang == 0 && x + 1 < 33 && status[x + 1][y] == 0)
                    || monster1[id]->running == 1){        //右
    //            x += 1;
                monster1[id]->running = 1; //封锁下右运动状态
                if(monster1[id]->count == 0){
                    monster1[id]->move(labels[x][y]->x() + 7, labels[x][y]->y());
                    monster1[id]->count = monster1[id]->count + 1;
                    break;
                }
    //            MyThread::msleep(1000);
                if(monster1[id]->count == 1){
                    monster1[id]->move(labels[x][y]->x() + 14, labels[x][y]->y());
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 2){
                    monster1[id]->move(labels[x][y]->x() + 21, labels[x][y]->y());
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 3){
                    monster1[id]->move(labels[x][y]->x() + 28, labels[x][y]->y());
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 4){
                    monster1[id]->move(labels[x][y]->x() + 35, labels[x][y]->y());
                    monster1[id]->count++;
                    monster1[id]->count = 0;
                    monster1[id]->running = 0; //解除运动状态
                    if(isCollide(man->x(), man->y(), monster1[id]->x(), monster1[id]->y())){
                                        man->Dead();
                                    }
                    break;
                }
            }
            else if((monster1[id]->running == 0 && monster1[id]->fang == 2 && y + 1 < 15 && status[x][y + 1] == 0)
                    || monster1[id]->running == 2){        //下
                monster1[id]->running = 2; //封锁运动状态
                if(monster1[id]->count == 0){
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() + 7);
                    monster1[id]->count = monster1[id]->count + 1;
                    break;
                }
                if(monster1[id]->count == 1){
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() + 14);
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 2){
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() + 21);
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 3){
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() + 28);
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 4){
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() + 35);
                    monster1[id]->count++;
                    monster1[id]->count = 0;
                    monster1[id]->running = 0; //解除运动状态
                    if(isCollide(man->x(), man->y(), monster1[id]->x(), monster1[id]->y())){
                                        man->Dead();
                                    }
                    break;
                }
            }
            else if((monster1[id]->running == 0 && monster1[id]->fang == 3 && x - 1 > 0 && status[x - 1][y] == 0)
                    || monster1[id]->running == 3){  //左
    //            x -= 1;
                monster1[id]->running = 3; //封锁运动状态
                if(monster1[id]->count == 0){
                    monster1[id]->move(labels[x][y]->x() - 7, labels[x][y]->y());
                    monster1[id]->count = monster1[id]->count + 1;
                    break;
                }
                if(monster1[id]->count == 1){
                    x++;
                    monster1[id]->move(labels[x][y]->x() - 14, labels[x][y]->y());
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 2){
                    x++;
                    monster1[id]->move(labels[x][y]->x() - 21, labels[x][y]->y());
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 3){
                    x++;
                    monster1[id]->move(labels[x][y]->x() - 28, labels[x][y]->y());
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 4){
                    x++;
                    monster1[id]->move(labels[x][y]->x() - 35, labels[x][y]->y());
                    monster1[id]->count++;
                    monster1[id]->count = 0;
                    monster1[id]->running = 0; //解除运动状态
                    if(isCollide(man->x(), man->y(), monster1[id]->x(), monster1[id]->y())){
                                        man->Dead();
                                    }
                    break;
                }
            }
            else if((monster1[id]->running == 0 && monster1[id]->fang == 1 && y - 1 > 0 && status[x][y - 1] == 0)
                    || monster1[id]->running == 4){  //上
                monster1[id]->running = 4; //封锁运动状态
    //            qDebug() << QString("monsterruning %1").arg(monster1[id]->count);
                if(monster1[id]->count == 0){
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() - 7);
                    monster1[id]->count = monster1[id]->count + 1;
    //                qDebug() << QString("monsterruning %1").arg(monster1[id]->count);
                    break;
                }
                if(monster1[id]->count == 1){
                    y++;
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() - 14);
                    monster1[id]->count++;
    //                qDebug() << QString("monsterruning %1").arg(monster1[id]->count);
                    break;
                }
                if(monster1[id]->count == 2){
                    y++;
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() - 21);
                    monster1[id]->count++;
    //                qDebug() << QString("monsterruning %1").arg(monster1[id]->count);
                    break;
                }
                if(monster1[id]->count == 3){
                    y++;
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() - 28);
                    monster1[id]->count++;
                    break;
                }
                if(monster1[id]->count == 4){
                    y++;
                    monster1[id]->move(labels[x][y]->x(), labels[x][y]->y() - 35);
                    monster1[id]->count++;
                    monster1[id]->count = 0;
                    monster1[id]->running = 0; //解除运动状态
                    if(isCollide(man->x(), man->y(), monster1[id]->x(), monster1[id]->y())){
                                        man->Dead();
                                    }
                    break;
                }
            }
            monster1[id]->fang = (monster1[id]->fang + 1) % 4; //以前的方向不行，就尝试下一种方向
            count++;
         }
    }
}
void Meadow::DrawFeWall(){ //画不可炸的铁墙
    for(int i = 0; i < MAX_X; i++){
        for(int j = 0; j < MAX_Y; j++){
            if(i == 0 || i == MAX_X - 1 || j == 0 || j == MAX_Y - 1 || (i % 2 == 0 && j % 2 == 0)){
                labels[i][j]->setStyleSheet("background: #dbd1d5");  //表示不可炸障碍物
                labels[i][j]->show();
                status[i][j] = 1; //1表示固定障碍物
                FeWall *feWall = new FeWall(this);
                feWall->move(labels[i][j]->x(), labels[i][j]->y());
                feWall->show();
            }
        }
    }
}
void Meadow::DrawWall(){   //画出墙
    int wx, wy;
    for(int i = 0; i < 60; i++){
        wx = qrand() % MAX_X;
        wy = qrand() % MAX_Y;
        while((status[wx][wy] != 0) || (wx == 1 && wy == 1) || (wx == 1 && wy == 2)
              || (wx == 2 && wy == 1)){
            wx = qrand() % MAX_X;
            wy = qrand() % MAX_Y;
        }
        mywall[i] = new Wall(this);
        GetWall[wx][wy]=i;
        status[wx][wy] = 2; //砖块墙
        mywall[i]->move(labels[wx][wy]->x(), labels[wx][wy]->y());
    }
}
void Meadow::drawBackGround(){  //画背景
    int s = 35;
    for(int x = 0; x < MAX_X; x++){
        for(int y = 0; y < MAX_Y; y++){
            QLabel *label = new QLabel(this);
           int x0 = x * s;
           int y0 = y * s;
           label->setGeometry(x0, y0, s - 1, s - 1);
           label->hide();
           labels[x][y] = label;
           status[x][y] = 0; //0表示空地
        }
    }

}
void Meadow::DrawBomb(){ //画炸弹
   for(int i = 0; i < 5; i++){
       bomb[i] = new Boom(this);
       connect(bomb[i], SIGNAL(over()), this, SLOT(BoomOver()));
       connect(bomb[i], SIGNAL(over1()),this, SLOT(BoomOver1()));
       connect(bomb[i], SIGNAL(OpenFire(int,int)), this, SLOT(slotsOpenFire(int,int)) ); //建立爆炸范围信号
       connect(bomb[i], SIGNAL(StopFire(int,int)), this, SLOT(slotsStopFire(int,int)) ); //建立停止爆炸信号
       bomb[i]->move(labels[0][0]->x(), labels[0][0]->y());
       bomb[i]->hide();
   }
}
void Meadow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_K && flag)
    {
        if(!list.isEmpty())
        {
            order front = list.front();
            bomb[front.index]->fire();
        }
    }
    if(e->key() == Qt::Key_J ){

        if(man->GetBoomNum()>=1)
        {
            int i = (man->x() + 17) / 35;   //炸弹放在人中心点所在的格子
            int j = (man->y() + 17) / 35;
            if(status[i][j]!= 3 && status[i][j] < 100)
            {
                man->SetBoom();      //人放下一个炸弹，拥有的炸弹数量会减少一个
                bomb[man->CountBomb]->show();   //将炸弹显示出来
                order temp;
                temp.i=i;
                temp.j=j;
                temp.index=man->CountBomb;
                list.push_back(temp);
                bomb[man->CountBomb]->move(labels[i][j]->x(), labels[i][j]->y());
                bomb[man->CountBomb]->start(status,i,j); //炸弹开始计时
                man->CountBomb++;
                man->CountBomb = man->CountBomb % 5; //人放的炸弹总数加一
            }
      }
    }
    if(e->key() == Qt::Key_Up || e->key() == Qt::Key_W)
    {
        if(e->isAutoRepeat())
        {
        if(Press == 0)
         {
            int spead = man->GetSpeed();
            if(ismove(man->x(), man->y() - spead) == 1)
            {
               man->UpMove();
               GetTool();
               Press++;
            }
        }
        else
            Press++;
        if(Press == 3)
            Press=0;
        }
        else
        {
            int spead = man->GetSpeed();
            if(ismove(man->x(), man->y() - spead) == 1)
            {
               man->UpMove();
               GetTool();
            }
           Press=0;
        }
    }
    if(e->key() == Qt::Key_Down || e->key() == Qt::Key_S)
    {
        if(e->isAutoRepeat())
        {
        if(Press == 0)
         {
            int spead = man->GetSpeed();
            if(ismove(man->x(), man->y() + spead) == 1)
            {
               man->DownMove();
               GetTool();
               Press++;
            }
        }
        else
            Press++;
        if(Press == 3)
            Press=0;
        }
        else
        {
            int spead = man->GetSpeed();
            if(ismove(man->x(), man->y() + spead) == 1)
            {
               man->DownMove();
               GetTool();
            }
           Press=0;
        }
    }
    if(e->key() == Qt::Key_Left || e->key() == Qt::Key_A)
    {
        if(e->isAutoRepeat())
        {
        if(Press == 0)
         {
            int spead = man->GetSpeed();
            if(ismove(man->x()-spead, man->y()) == 1)
            {
               man->LeftMove();
               GetTool();
               Press++;
            }
        }
        else
            Press++;
        if(Press == 3)
            Press=0;
        }
        else
        {
            int spead = man->GetSpeed();
            if(ismove(man->x()-spead, man->y()) == 1)
            {
               man->LeftMove();
               GetTool();
            }
           Press=0;
        }
    }
    if(e->key() == Qt::Key_Right|| e->key() == Qt::Key_D )
    {
        if(e->isAutoRepeat())
        {
        if(Press == 0)
         {
            int spead = man->GetSpeed();
            if(ismove(man->x()+spead, man->y()) == 1)
            {
               man->RightMove();
               GetTool();
               Press++;
            }
         }
          else
             Press++;
          if(Press == 3)
             Press=0;
        }
        else
        {
            int spead = man->GetSpeed();
            if(ismove(man->x()+spead, man->y()) == 1)
            {
               man->RightMove();
               GetTool();
               Press++;
            }
           Press=0;
        }
    }

    if(e->key() == Qt::Key_P)
        man->Stop();
}
int Meadow::ismove(int x, int y){ //人是否能移动
    if(man->IsLive() == 0){ //人的生命值小于一结束人的运动
        return 0;
    }
    if(x < 35 || y < 35 || x > 35 * 32 || y > 35 * 14)  //撞四周的墙
        return 0;
    for(int i = 0; i < MAX_X; i++){
        for(int j = 0; j < MAX_Y; j++){
            if(status[i][j] > 0 && status[i][j] <= 39 && status[i][j]!= 3){
                if((labels[i][j]->x() + 8 > x + man->width() ||               //右交    //是否撞障碍物  //允许误差6px
                        labels[i][j]->x() + labels[i][j]->width() < x  + 8 || //左交
                        labels[i][j]->y() + 8 > y + man->height() ||          //下交
                        labels[i][j]->y() + labels[i][j]->height() < y + 5)){ //上交的误差应不超过4,否则会隐藏掉半个头QAQ
                    //                    if(y < 33 || x < 33){   //控制第一行
                    //                        return 0;
                    //                    }
                    //                    if(x + man->width() > labels[i][j]->x() + 3  //至少有3px的误差
                    //                            && x + man->width() - 10 < labels[i][j]->x()
                    //                            && labels[i][j]->y() > y - 30 && labels[i][j]->y() < y + 30){
                    //                        man->move(labels[i][j]->x() - man->width(), y);  //右交
                    //                        qDebug() << 1;
                    //                        return 1;
                    //                    }
                    //                    if(labels[i][j]->x() + labels[i][j]->width() + 3 > x
                    //                            && labels[i][j]->x() + labels[i][j]->width() < 10 + x
                    //                            && labels[i][j]->y() > y - 30 && labels[i][j]->y() < y + 30){
                    //                        man->move(labels[i][j]->x() + labels[i][j]->width(), y);  //左交
                    //                        qDebug() << 2;
                    //                        return 1;
                    //                    }
                    //                    if(labels[i][j]->y() < y + man->height() + 3
                    //                            && labels[i][j]->y() + 10 > y + man->height()
                    //                            && labels[i][j]->x() > x - 30 && labels[i][j]->x() < x + 30){
                    //                        man->move(x, labels[i][j]->y() - man->height()); //下交
                    //                        qDebug() << 3;
                    //                        return 1;
                    //                    }
                                        if(labels[i][j]->y() + labels[i][j]->height() > y + 3
                                                && labels[i][j]->y() + labels[i][j]->height() < 10 + y
                                                && labels[i][j]->x() > x - 30 && labels[i][j]->x() < x + 30){
                                            man->move(x, labels[i][j]->y() + labels[i][j]->height()); //上交
                                            return 1;
                                        }
                }
                else{
                    return 0;
                }
            }
        }
    }
        return 1;
}
void Meadow::DrawMan()
{
    man->move(35,35);
    man->resize(35,35);
}
void Meadow::DrawTool() //画出道具
{
    int temp_1=0;
    int temp_2=0;
    int temp_3=0;
    for(int i=0;i<33;i++)
        for(int j=0;j<15;j++)
        {
            if(status[i][j] == 2)
            {
                int rand = qrand()%100;
                if(rand >= 1 && rand <= 5 && temp_1<5)//1~5产生增加炸弹的道具卡
                {
                    BoomUpCard[temp_1] = new BoomUp(this);
                    BoomUpCard[temp_1]->move(labels[i][j]->x(), labels[i][j]->y());
                    BoomUpCard[temp_1]->hide();
                    status[i][j] = 10+temp_1;
                    temp_1++;
                }
                else if(rand >= 20 && rand <=26 && temp_2<4)//20~26产生威力加强道具卡
                {
                    powerup[temp_2] = new PowerUp(this);
                    powerup[temp_2]->move(labels[i][j]->x(), labels[i][j]->y());
                    powerup[temp_2]->hide();
                    status[i][j] = 20+temp_2;
                    temp_2++;
                }
                else if(rand >=50 && rand <=51 && temp_3<2)//50~51产生定时炸弹道具卡
                {
                    timer[temp_3]=new BoomTimer(this);
                    timer[temp_3]->move(labels[i][j]->x(), labels[i][j]->y());
                    timer[temp_3]->hide();
                    status[i][j]=30+temp_3;
                    temp_3++;
                }
            }
        }
}
void Meadow::GetTool()  //得到道具
{
    int x = man->x()/35;
    int y = man->y()/35;
    int judge = status[x][y]-100;
    if(judge >= 10 && judge <=19)
    {
        man->BoomNumUp();
        BoomUpCard[judge-10]->hide();
        status[x][y]=0;
    }
    if(judge >= 20 && judge <= 29)
    {
        man->PowerUp();
        powerup[judge-20]->hide();
        status[x][y]=0;
    }
    if(judge >= 30 && judge <= 39)
    {
        timer[judge-30]->hide();
        for(int i=0;i<5;i++)
        {
            bomb[i]->GetTimer();
        }
        flag=1;
        status[x][y]=0;
    }
}
int Meadow::isCollide(int x1, int y1, int x2, int y2){ //碰撞检测
    if(x2 + 35 < x1 + 3 || x2 > x1 + 35 - 3 || y2 + 35 < y1 + 3 || y2 > y1 + 35 - 3){ //给3px的误差
        return 0;
    }
    return 1;
}
void Meadow::BoomOver()
{
    list.pop_front();
    man->BoomNumUp();
}
void Meadow::BoomOver1()
{
    man->BoomNumUp();
}

void Meadow::slotsOpenFire(int i, int j){ //显示爆炸效果
    int up = 1, down = 1, left = 1, right = 1;
    for(int k = 1; k <= man->GetPower() && status[i][j] == 3; k++){ //改变爆炸范围的状态
        if(status[i][j + k] == 1){ //障碍物，隔断爆炸
            down = 0;
        }
        if(status[i][j - k] == 1){
            up = 0;
        }
        if(status[i + k][j] == 1){
            right = 0;
        }
        if(status[i - k][j] == 1){
            left = 0;
        }
        if(status[i][j + k] == 0 && down){ //如果是空地向下爆炸
            status[i][j + k] = 4;
            labels[i][j + k]->setPixmap(pix_down);
            labels[i][j + k]->show();
            //贴图
        }
        if(status[i][j - k] == 0 && up){ //向上
            status[i][j - k] = 4;
            labels[i][j - k]->setPixmap(pix_up);
            labels[i][j - k]->show();
            //贴图
        }
        if(status[i + k][j] == 0 && right){ //向右
            status[i + k][j] = 4;
            labels[i + k][j]->setPixmap(pix_right);
            labels[i + k][j]->show();
            //贴图
        }
        if(status[i - k][j] == 0 && left){ //向左
            status[i - k][j] = 4;
            labels[i - k][j]->setPixmap(pix_left);
            labels[i - k][j]->show();
            //贴图
        }
        if(status[i][j + k] == 3){ //检测周围是否有炸弹，有则强制引爆
            for(QList<order>::iterator iter = list.begin();iter != list.end();iter++)
            {
                if((*iter).i ==i && (*iter).j == j + k)
                {
                    bomb[(*iter).index]->fire1();
                    list.erase(iter);
                    break;
                }
            }
        }
        if(status[i][j - k] == 3){
            for(QList<order>::iterator iter = list.begin();iter != list.end();iter++)
            {
                if((*iter).i ==i && (*iter).j == j - k)
                {
                    bomb[(*iter).index]->fire1();
                    list.erase(iter);
                    break;
                }
            }
        }
        if(status[i + k][j] == 3){
            for(QList<order>::iterator iter = list.begin();iter != list.end();iter++)
            {
                if((*iter).i ==i+k && (*iter).j == j)
                {
                    bomb[(*iter).index]->fire1();
                    list.erase(iter);
                    break;
                }
            }
        }
        if(status[i - k][j] == 3){
            for(QList<order>::iterator iter = list.begin();iter != list.end();iter++)
            {
                if((*iter).i ==i - k&& (*iter).j == j)
                {
                    bomb[(*iter).index]->fire1();
                    list.erase(iter);
                    break;
                 }
            }
        }
        if((status[i][j + k] >= 10 || status[i][j + k] == 2) && down){ //如果是可炸的墙
            down = 0; //砖墙，隔离爆炸；
            mywall[GetWall[i][j + k]]->hide();
            if(status[i][j + k] == 2){
                status[i][j + k] = 4;
//                return ;
            }
            if(status[i][j + k] >= 10 && status[i][j + k] < 20){ //炸弹增多
           //     qDebug()<<"庞玮";
               BoomUpCard[status[i][j + k] - 10]->show();
               status[i][j + k] += 100;//便于区分人得到卡的状态矩阵
            }
            if(status[i][j + k] >= 20 && status[i][j + k] < 30){ //威力加强
        //          qDebug()<<"庞玮";
                powerup[status[i][j + k] - 20]->show();
                status[i][j + k] += 100;//便于区分人得到卡的状态矩阵
            }
            if(status[i][j + k] >=30 && status[i][j + k]< 40){ //定时引爆
         //         qDebug()<<"庞玮";
                timer[status[i][j + k] - 30]->show();
                status[i][j + k] += 100;//便于区分人得到卡的状态矩阵
            }
//            status[i][j + k] = 4;
        }
        if((status[i][j - k] >= 10 || status[i][j - k] == 2) && up){ //向上
            up = 0;
            mywall[GetWall[i][j - k]]->hide();
            if(status[i][j - k] == 2){
                status[i][j - k] = 4;
//                return ;
            }
            if(status[i][j - k] >= 10 && status[i][j - k]< 20){ //炸弹增多
           //     qDebug()<<"庞玮";
               BoomUpCard[status[i][j - k] - 10]->show();
               status[i][j - k] += 100;//便于区分人得到卡的状态矩阵
            }
            if(status[i][j - k] >= 20 && status[i][j - k] < 30){ //威力加强
        //          qDebug()<<"庞玮";
                powerup[status[i][j - k] - 20]->show();
                status[i][j - k] += 100;//便于区分人得到卡的状态矩阵
            }
            if(status[i][j - k] >= 30 && status[i][j - k]< 40){ //定时引爆
         //         qDebug()<<"庞玮";
                timer[status[i][j - k] - 30]->show();
                status[i][j - k] += 100;//便于区分人得到卡的状态矩阵
            }

        }
        if((status[i + k][j] >= 10 || status[i + k][j] == 2) && right){ //向右
            right = 0;
            mywall[GetWall[i + k][j]]->hide();
            if(status[i + k][j] == 2){
                status[i + k][j] = 4;
//                return ;
            }
            if(status[i + k][j] >= 10 && status[i + k][j]<20){ //炸弹增多
           //     qDebug()<<"庞玮";
               BoomUpCard[status[i + k][j] - 10]->show();
               status[i + k][j] += 100;//便于区分人得到卡的状态矩阵
            }
            if(status[i + k][j] >= 20 && status[i + k][j] < 30){ //威力加强
        //          qDebug()<<"庞玮";
                powerup[status[i + k][j] - 20]->show();
                status[i + k][j] += 100;//便于区分人得到卡的状态矩阵
            }
            if(status[i + k][j] >=30 && status[i + k][j]<40){ //定时引爆
         //         qDebug()<<"庞玮";
                timer[status[i + k][j] - 30]->show();
                status[i + k][j] += 100;//便于区分人得到卡的状态矩阵
            }
        }
        if((status[i - k][j] >= 10 || status[i - k][j] == 2) && left){ //向左
            left = 0;
            mywall[GetWall[i - k][j]]->hide();
            if(status[i - k][j] == 2){
                status[i - k][j] = 4;
//                return ;
            }
            if(status[i - k][j] >= 10 && status[i - k][j]<20){ //炸弹增多
           //     qDebug()<<"庞玮";
               BoomUpCard[status[i - k][j] - 10]->show();
               status[i - k][j] += 100;//便于区分人得到卡的状态矩阵
            }
            if(status[i - k][j] >= 20 && status[i - k][j] < 30){ //威力加强
        //          qDebug()<<"庞玮";
                powerup[status[i - k][j] - 20]->show();
                status[i - k][j] += 100;//便于区分人得到卡的状态矩阵
            }
            if(status[i - k][j] >=30 && status[i - k][j]<40){ //定时引爆
         //         qDebug()<<"庞玮";
                timer[status[i - k][j] - 30]->show();
                status[i - k][j] += 100;//便于区分人得到卡的状态矩阵
            }
        }
    }
    status[i][j] = 4;
//    labels[i][j]->setStyleSheet("background: red");
    labels[i][j]->show();
    //假定威力最大为8，来减少循环次数
    for(int l = i - 7; l < i + 7; l++){
        for(int m = j - 7; m < j + 7; m++){
            if(l > 0 && l < MAX_X - 1 && m > 0 && m < MAX_Y - 1 && status[l][m] == 4){ //下标合法且是炸弹火焰
                if(isCollide(man->x(), man->y(), labels[l][m]->x(), labels[l][m]->y())){
                    man->Dead();  //人死亡
                    qDebug() << QString("人死亡人死亡人死亡人死亡 ");
                }
                for(int k = 0; k < MAX_guai; k++){
                    if(monster1[k]->islive == 1 && isCollide(monster1[k]->x(), monster1[k]->y(), labels[l][m]->x(), labels[l][m]->y())){
                        monster1[k]->Dead(); //怪死亡
                        toalCore += 100; //炸死每只怪得100分
                    }
                }
            }
        }
    }
}
void Meadow::slotsStopFire(int i, int j){ //清空爆炸效果
//    qDebug() << QString(" 1111111111111111111111 ");
    for(int k = 1; k <= man->GetPower(); k++){ //爆炸范围的状态

        if(status[i][j + k] == 4){ //向下  //解除爆炸范围
            status[i][j + k] = 0;

            labels[i][j + k]->clear();
            labels[i][j + k]->hide();
        }
        if(status[i][j - k] == 4){ //向上
            status[i][j - k] = 0;

            labels[i][j - k]->clear();
            labels[i][j - k]->hide();
            //贴图
        }
        if(status[i + k][j] == 4){ //向右
            status[i + k][j] = 0;
            labels[i + k][j]->clear();
            labels[i + k][j]->hide();
            //贴图
        }
        if(status[i - k][j] == 4){ //向左
            status[i - k][j] = 0;
            labels[i - k][j]->clear();
            labels[i - k][j]->hide();
            //贴图
        }
    }
    status[i][j] = 0;
    labels[i][j]->hide();
}
void Meadow::paintEvent(QPaintEvent *e){  //使子窗口可以调色
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


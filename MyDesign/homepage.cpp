#include "homepage.h"
#include <QTextCodec>
#include <QtWinExtras/QtWin>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);                          //设置无边框窗口
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));//设置编码为系统编码

    QIcon icon(":/image/music.ico");
    setWindowIcon(icon);

    setMaximumSize(300,500);
    setMinimumSize(300,500);

    /*
    if (QtWin::isCompositionEnabled()) {
        QtWin::extendFrameIntoClientArea(this, -1, -1, -1, -1);
        setAttribute(Qt::WA_TranslucentBackground, true);
        setAttribute(Qt::WA_NoSystemBackground, false);
        setStyleSheet("QWidget{ background: transparent; }");
    } else {
        QtWin::resetExtendedFrame(this);
        setAttribute(Qt::WA_TranslucentBackground, false);
        setStyleSheet(QString("QWidget{ background: %1; }").arg(QtWin::realColorizationColor().name()));
    }*/



    QPixmap pixmap = QPixmap(":/image/backG.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);


    //this->setStyleSheet("QListWidget{border-image:url(:/image/backG.png)}"); //all children are used


    /*
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_NoSystemBackground, false);
    setStyleSheet("QWidget{ background: transparent; }");
    */

    closeBtn = new QToolButton(this);
    minBtn = new QToolButton(this);

    QPixmap minpix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);

    closeBtn->setIcon(closePix);
    minBtn->setIcon(minpix);


    minBtn->setStyleSheet("background-color:transparent;");
    closeBtn->setStyleSheet("background-color:transparent;");

    PlayingMusic = new QLabel;
    LrcBtn = new QPushButton("Lrc");
    VoiceBtn = new QPushButton(this);
    StartBtn = new QPushButton(this);
    NextmusicBtn = new QPushButton(this);
    PrecedmusicBtn = new QPushButton(this);
    AddBtn = new QPushButton(this);
    StyleBtn = new QPushButton(this);
    SearchBtn = new QPushButton(this);
    TimeLabel = new QLabel("  00:00");
    SearchEdit = new QLineEdit(this);

    LineEditModel = new QStandardItemModel(0,1,this);
    LineEditComp = new QCompleter(LineEditModel,this);
    //LineEditComp->activated("0");
    SearchEdit->setCompleter(LineEditComp);

    //PlayStyleBtn->setStyleSheet("background-color:transparent;");

    //SearchBtn->setEnabled(true);

    LrcBtn->setMinimumSize(26,26);
    LrcBtn->setMaximumSize(26,26);
    AddBtn->setMinimumSize(26,26);
    AddBtn->setMaximumSize(26,26);
    PrecedmusicBtn->setMinimumSize(26,26);
    PrecedmusicBtn->setMaximumSize(26,26);
    NextmusicBtn->setMinimumSize(26,26);
    NextmusicBtn->setMaximumSize(26,26);
    StartBtn->setMinimumSize(26,26);
    StartBtn->setMaximumSize(26,26);
    StyleBtn->setMaximumSize(26,26);
    StyleBtn->setMinimumSize(26,26);
    SearchBtn->setMinimumSize(24,24);
    SearchBtn->setMaximumSize(24,24);
    TimeLabel->setMinimumSize(60,20);
    SearchEdit->setMinimumSize(150,24);
    SearchEdit->setMaximumSize(150,24);


    MusicList = new QMediaPlaylist(this);
    MusicSlider = new QSlider(Qt::Horizontal);
    Player = new QMediaPlayer;
    MusicListWG = new QListWidget;


    Player->setPlaylist(MusicList);
    Player->setVolume(30);
    MusicSlider->setSliderPosition(30);


    VoiceBtn->setStyleSheet("QPushButton{border-image:url(:/image/Loudly.png);}"
                            "QPushButton:hover{border-image:url(:/image/Loudlys.png);}"
                            "QPushButton:pressed{border-image:url(:/image/Loudlyss.png);}");

    //LrcBtn->setStyleSheet();


    AddBtn->setStyleSheet("QPushButton{border-image:url(:/image/Add.png);}"
                          "QPushButton:hover{border-image:url(:/image/Adds.png);}"
                          "QPushButton:pressed{border-image:url(:/image/Addss.png);}");

    PrecedmusicBtn->setStyleSheet("QPushButton{border-image:url(:image/Front.png);}"
                                  "QPushButton:hover{border-image:url(:/image/Fronts.png);}"
                                  "QPushButton:pressed{border-image:url(:/image/Frontss.png);}");

    StartBtn->setStyleSheet("QPushButton{border-image:url(:/image/Start.png);}"
                            "QPushButton:hover{border-image:url(:/image/Starts.png)}"
                            "QPushButton:pressed{border-image:url(:/image/Startss.png);}");

    NextmusicBtn->setStyleSheet("QPushButton{border-image:url(:/image/Next.png);}"
                                "QPushButton:hover{border-image:url(:/image/Nexts.png);}"
                                "QPushButton:pressed{border-image:url(:/image/Nextss.png);}");


    SearchBtn->setStyleSheet("QPushButton{border-image:url(:/image/Search.png);}"
                             "QPushButton:hover{border-image:url(:/image/Searchs.png);}"
                             "QPushButton:pressed{border-image:url(:/image/Searchss.png);}");

    StyleBtn->setStyleSheet("QPushButton{border-image:url(:/image/Random.png);}"
                            "QPushButton:hover{border-image:url(:/image/Randoms.png);}"
                            "QPushButton:pressed{border-image:url(:/image/Randomss.png);}");

    mainLayout = new QVBoxLayout(this);
    TitleLayout = new QHBoxLayout;
    musicInfLayout = new QHBoxLayout;
    controlLayout = new QHBoxLayout;
    searchLayout = new QHBoxLayout;

    TitleLayout->addStretch(1);
    TitleLayout->addWidget(PlayingMusic);
    TitleLayout->addStretch(4);
    TitleLayout->addWidget(minBtn);
    TitleLayout->addWidget(closeBtn);
    TitleLayout->setSpacing(1);
    TitleLayout->setMargin(2);
    musicInfLayout->addWidget(LrcBtn);
    musicInfLayout->addWidget(MusicSlider);
    musicInfLayout->setSpacing(20);
    musicInfLayout->addWidget(VoiceBtn);
    musicInfLayout->setMargin(5);

    controlLayout->addWidget(AddBtn);
    controlLayout->addWidget(PrecedmusicBtn);
    controlLayout->addWidget(StartBtn);
    controlLayout->addWidget(NextmusicBtn);
    controlLayout->addStretch(1);
    controlLayout->addWidget(TimeLabel);

    controlLayout->addWidget(StyleBtn);
    controlLayout->setMargin(5);

    searchLayout->addWidget(SearchBtn);
    searchLayout->addWidget(SearchEdit);

    searchLayout->addStretch(3);
    searchLayout->setMargin(5);

    mainLayout->addLayout(TitleLayout);
    mainLayout->addLayout(musicInfLayout);
    mainLayout->addLayout(controlLayout);
    mainLayout->addLayout(searchLayout);


    mainLayout->addWidget(MusicListWG);

    mainLayout->setMargin(0);
    mainLayout->setSpacing(5);



    connect(closeBtn, &QPushButton::clicked, this, &QWidget::close);
    connect(minBtn, &QPushButton::clicked, this, &QWidget::showMinimized);
    connect(AddBtn, &QPushButton::clicked, this, &HomePage::AddMusicSlot);
    connect(StartBtn, &QPushButton::clicked, this, &HomePage::StopMusicSlot);
    connect(NextmusicBtn, &QPushButton::clicked, this, &HomePage::NextMusicSlot);
    connect(PrecedmusicBtn, &QPushButton::clicked, this, &HomePage::PreMusicSlot);

    connect(MusicListWG, &QListWidget::itemDoubleClicked, this, &HomePage::ClickMusicSlot);
    connect(SearchBtn, &QPushButton::clicked, this, &HomePage::SeekMusicSlot);
    connect(StyleBtn, &QPushButton::clicked, this, &HomePage::SetStyleSlot);


    connect(Player, &QMediaPlayer::durationChanged, this, &HomePage::DurationChangeSlot);
    connect(Player, &QMediaPlayer::positionChanged, this, &HomePage::updatePositionSlot);
    connect(MusicSlider, &QAbstractSlider::valueChanged, this, &HomePage::setPositionSlot);


    connect(SearchEdit,SIGNAL(textChanged(const QString&)),this,SLOT(FuzzyMatchSlot(const QString&)));
    connect(LineEditComp,SIGNAL(activated(const QString&)),this,SLOT(compSlot(const QString&)));

    //connect(LineEditComp,static_cast<void(QCompleter:: *)(const QString &)>(&QCompleter::activated),this,&HomePage::compSlot);



}

HomePage::~HomePage()
{

}

void HomePage::mouseMoveEvent(QMouseEvent *event)//鼠标移动事件
{
    if(MousePress)                               //若鼠标按下左键
    {
        QPoint movePos = event->globalPos();     //获取鼠标全局的位置
        this->move(movePos-MouseMove);           //窗口跟随鼠标移动
    }
}

void HomePage::mousePressEvent(QMouseEvent *event)//鼠标按下事件
{
    if(event->button() == Qt::LeftButton)         //鼠标按下左键那么mousPress为真
    {
        MousePress = true;
        MouseMove = event->pos();                 //鼠标移动获取当前的点击位置
    }
}

void HomePage::mouseReleaseEvent(QMouseEvent *)   //鼠标松开事件
{
    MousePress = false;                           //鼠标松开,MousePress为假

}

void HomePage::AddMusicSlot()
{
    QStringList Stringlist = QFileDialog::getOpenFileNames(this, "Open file", QDir::currentPath(),tr("(*.mp3)"));//获取打卡文本的名字

    if (Stringlist.size() == 0)
    {
        return;
    }

    for(int i=0;i<Stringlist.size();i++)
    {

        //demo   http://blog.sina.com.cn/s/blog_74a7e56e0101agit.html#cmt_2849464
        QString path = QDir::toNativeSeparators(Stringlist.at(i));
        if(!path.isEmpty())
        {
        MusicList->addMedia(QUrl::fromLocalFile(path));  //加载显示到listwidegt  类似委托那个mvc
        //MusicList->setCurrentIndex(1);                   //设置当前项为1

        //去除路径把名字显示到listwidget
        }
    }
        for (int index = 0; index < Stringlist.size(); index++)
        {

            QListWidgetItem  *Item = new QListWidgetItem;
            Item->setSizeHint(QSize(20,30));
            QString MusicName = Stringlist.at(index);
            Item->setText(MusicName.remove(0,Stringlist.at(index).lastIndexOf('/')+1));
            MusicListWG->addItem(Item);
        }
        //PlayingMusic->setText(MusicListWG->currentItem()->text());
        Player->play();    //播放music
        StartBtn->setText("stop");

//qDebug()<<MusicListWG->count(); //一共8行输出8个
}


void HomePage::StopMusicSlot()
{
  if(MusicList->mediaCount() == 0)
      return;

  if(StartBtn->text() == "stop")
  {
      StartBtn->setText("play");
      Player->pause();
  }
  else if(StartBtn->text() == "play")
  {
      StartBtn->setText("stop");
      Player->play();
  }
  //qDebug()<<Player->metaData(QMediaMetaData::Duration);
}

void HomePage::NextMusicSlot()
{
    if(MusicList->mediaCount() == 1)
        Player->play();
    else if(MusicList->mediaCount() == 0)
        return;
    else
    {
        int index = MusicList->currentIndex();
        MusicList->setCurrentIndex(index+1);
        MusicListWG->setCurrentRow(index+1);
        Player->play();
    }
}

void HomePage::PreMusicSlot()
{
    if(MusicList->mediaCount() == 1)
        Player->play();
    else if(MusicList->mediaCount() == 0)
        return;
    else
    {
        int index = MusicList->currentIndex();
        MusicList->setCurrentIndex(index-1);
        MusicListWG->setCurrentRow(index-1);
        Player->play();
    }
}

void HomePage::SetVolumeSlot()
{
    int Volume = MusicSlider->sliderPosition();
    Player->setVolume(Volume);
}

void HomePage::ClickMusicSlot()
{
    int index = MusicListWG->currentRow();
    MusicList->setCurrentIndex(index);
    PlayingMusic->setText(MusicListWG->currentItem()->text());
    Player->play();
}

void HomePage::SeekMusicSlot()
{
    QString MusicName = SearchEdit->text();
    if(MusicName.isEmpty())
        return;
    /*
    int index = 1;
    for(index = 1;index < MusicListWG->count();index++);
    {
        if(MusicListWG->item(index)->text() == MusicName)
        {
            MusicListWG->setCurrentRow(index);
            return;
        }
    }*/
}

void HomePage::SetStyleSlot()
{
    /* 此类有一个函数，void    setPlaybackMode(PlaybackMode mode)，而
    enum    PlaybackMode { CurrentItemOnce, CurrentItemInLoop, Sequential, Loop, Random }
    */
    //qDebug()<<"hello";
    //Player->setPlaybackRate(QMediaPlaylist::Loop);//seep up
    MusicList->setPlaybackMode(QMediaPlaylist::Random);//zijisuijibofang anxiashoubuhui
    //Player->setPlaybackRate(QMediaPlaylist::Random);//seep up
    //Player->setPlaybackRate(QMediaPlaylist::Sequential);
    //Player->setPlaybackRate(QMediaPlaylist::CurrentItemInLoop);
    //qDebug()<<StyleBtn->styleSheet();
    //http://blog.sina.com.cn/s/blog_a6fb6cc90101evr8.html

}
void HomePage:: DurationChangeSlot(qint64 duration)
{
  MusicSlider->setRange(0,duration);
}


void HomePage::updatePositionSlot(qint64 position)
{
    MusicSlider->setValue(position);

    QTime duration(0, position / 60000, qRound((position % 60000) / 1000.0));
    TimeLabel->setText(duration.toString(tr("  mm:ss")));
}

void HomePage::setPositionSlot(int position)
{
    if (qAbs(Player->position() - position) > 99)
        Player->setPosition(position);
}

void HomePage::FuzzyMatchSlot(const QString& str)
{
    //QString musicName = SearchEdit->text();
    QStringList musiclist;


    LineEditModel->removeRows(0,LineEditModel->rowCount());

    for(int index=0;index<MusicListWG->count();index++)
    {
        if(MusicListWG->item(index)->text().contains(str,Qt::CaseInsensitive))
        {
            musiclist<< MusicListWG->item(index)->text();
        }
    }

    for(int i = 0; i < musiclist.size(); i++)
    {
        LineEditModel->insertRow(0);
        LineEditModel->setData(LineEditModel->index(0,0),str + musiclist.at(i));//str +"  "+
    }
   //emit LineEditComp->activated(str);
}



void HomePage::compSlot(const QString& str)
{
    SearchEdit->clear();
    qDebug()<<"hello";
    SearchEdit->setText(str);
}

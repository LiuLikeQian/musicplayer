#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSlider>
#include <QLineEdit>
#include <QMouseEvent>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QDir>
#include <QFileDialog>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimedia/qmediaplayercontrol.h>
#include <QtMultimediaWidgets/QVideoWidget>

#include <QListWidget>
#include <QListWidgetItem>
#include <QMediaMetaData>
#include <QAbstractSlider>

#include <QTime>

#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QCompleter>
#include <QStandardItemModel>

class HomePage : public QWidget
{
    Q_OBJECT

public:
    HomePage(QWidget *parent = 0);
    ~HomePage();
signals:


private:
    QPoint MouseMove;  //鼠标移动距离
    bool MousePress;   //鼠标按下

    void mousePressEvent(QMouseEvent *);   //鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *); //鼠标释放事件
    void mouseMoveEvent(QMouseEvent *);    //鼠标移动事件

    QToolButton *closeBtn;
    QToolButton *minBtn;
    QPushButton *LrcBtn;
    QPushButton *VoiceBtn;
    QPushButton *StartBtn;
    QPushButton *NextmusicBtn;
    QPushButton *PrecedmusicBtn;
    QPushButton *AddBtn;
    QPushButton *StyleBtn;
    QPushButton *SearchBtn;
    QLabel *TimeLabel;
    QLineEdit *SearchEdit;
    QLabel *PlayingMusic;
    QStandardItemModel *LineEditModel;
    QCompleter *LineEditComp;

    QMediaPlaylist *MusicList;
    QMediaPlayer *Player;
    QSlider *MusicSlider;
    QListWidget *MusicListWG;

    QVBoxLayout *mainLayout;
    QHBoxLayout *musicInfLayout;
    QHBoxLayout *controlLayout;
    QHBoxLayout *searchLayout;
    QHBoxLayout *TitleLayout;



private slots:
    void AddMusicSlot();
    void StopMusicSlot();
    void NextMusicSlot();
    void PreMusicSlot();
    void SetVolumeSlot();
    void ClickMusicSlot();
    void SeekMusicSlot();
    void SetStyleSlot();
    void DurationChangeSlot(qint64);
    void updatePositionSlot(qint64);
    void setPositionSlot(int);

    void FuzzyMatchSlot(const QString&);
    void compSlot(const QString&);

};

#endif // HOMEPAGE_H

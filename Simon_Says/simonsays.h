#ifndef SIMONSAYS_H
#define SIMONSAYS_H

#include <QMainWindow>
#include <QVector>
#include <QStyle>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class SimonSays; }
QT_END_NAMESPACE

class SimonSays : public QMainWindow
{
    Q_OBJECT

public:
    SimonSays(QWidget *parent = nullptr);
    ~SimonSays();

private slots:

    void on_GreenButton_clicked();

    void on_BlueButton_clicked();

    void on_YellowButton_clicked();

    void on_RedButton_clicked();

    void on_StartButton_clicked();

    void pattern_Show();

    void failure();

    void wait();

private:
    Ui::SimonSays *ui;
    QVector<int> m_pattern;
    int m_patternCount;
};
#endif // SIMONSAYS_H

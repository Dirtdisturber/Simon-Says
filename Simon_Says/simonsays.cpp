#include "simonsays.h"
#include "ui_simonsays.h"
#include <QStyle>
#include <QDateTime>
#include <QApplication>

#include <QMessageBox>
#include <QInputDialog>

//Easier to see whats going on by using Enum
enum buttons{RED, BLUE, GREEN, YELLOW, START};

SimonSays::SimonSays(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimonSays)
{
    //Seeds randomly every time on setup
    qsrand(QDateTime::currentMSecsSinceEpoch());
    ui->setupUi(this);
}

SimonSays::~SimonSays()
{
    delete ui;
}

void SimonSays::pattern_Show()
{
    //This adds in a random next sequence and resets the pattern count for the tests
    m_patternCount = 0;
    m_pattern.append(qrand() % 4);
    //This Color Changes each of the buttons to show it again as it walks through list
    for (int i = 0; i < m_pattern.count(); i ++)
    {
        switch(m_pattern[i])
        {
        case RED:
            //Color Change Bright Red
             ui->RedButton->setStyleSheet("background-color: rgb(255, 0, 0)");
            SimonSays::wait();
            //Change Back
             ui->RedButton->setStyleSheet("background-color: rgb(225, 0, 0)");
            break;
        case BLUE:
            //Color Change Bright Blue
            ui->BlueButton->setStyleSheet("background-color: rgb(0, 0, 255)");
            SimonSays::wait();
            //Change Back
            ui->BlueButton->setStyleSheet("background-color: rgb(0, 0, 225)");
            break;
        case GREEN:
            //Color Change Bright Green
            ui->GreenButton->setStyleSheet("background-color: rgb(0, 255, 0)");
            SimonSays::wait();
            //Change Back
            ui->GreenButton->setStyleSheet("background-color: rgb(0, 225, 0)");
            break;
        case YELLOW:
            //Color Change Bright Yellow
            ui->YellowButton->setStyleSheet("background-color: rgb(255, 255, 0)");
            SimonSays::wait();
            //Change Back
            ui->YellowButton->setStyleSheet("background-color: rgb(225, 100, 0)");
            break;
        }
    }

}

void SimonSays::on_BlueButton_clicked()
{
    //Checks if you clicked right button in Sequence
    if (!(m_pattern[m_patternCount++] == BLUE))
        failure();

    //Checks if end of Sequence if so starts the next
    if (m_patternCount == m_pattern.count())
        SimonSays::pattern_Show();
}


void SimonSays::on_YellowButton_clicked()
{
    //Checks if you clicked right button in Sequence
    if (!(m_pattern[m_patternCount++] == YELLOW))
        failure();

    //Checks if end of Sequence if so starts the next
    if (m_patternCount == m_pattern.count())
        SimonSays::pattern_Show();
}


void SimonSays::on_RedButton_clicked()
{
    //Checks if you clicked right button in Sequence
    if (!(m_pattern[m_patternCount++] == RED))
        failure();
    //Checks if end of Sequence if so starts the next
    if (m_patternCount == m_pattern.count())
        SimonSays::pattern_Show();
}

void SimonSays::on_GreenButton_clicked()
{
    //Checks if you clicked right button in Sequence
    if (!(m_pattern[m_patternCount++] == GREEN))
        failure();

    //Checks if end of Sequence if so starts the next
    if (m_patternCount == m_pattern.count())
        SimonSays::pattern_Show();
}

void SimonSays::on_StartButton_clicked()
{
    m_pattern.clear();
    SimonSays::pattern_Show();
}

void SimonSays::failure()
{
    //Show Some Failure Screen I just have it force quit right now
    QMessageBox::warning(this, tr("Simon Says"), tr("Incorrect"));
    QApplication::quit();
}

//Simple Waitfunction so Users can actually see the colors as their happening
void SimonSays::wait()
{
    QTime time= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < time)
    {}
}


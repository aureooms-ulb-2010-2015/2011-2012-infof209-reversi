#include <QApplication>
//#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QScrollArea>
#include <QListWidget>
#include <QMainWindow>
#include <QIcon>
#include <QDesktopWidget>

#include "GUI_Reversi_Board_Grid.h"
#include "GUI_Reversi_Board.h"
#include "GUI_Game_Container.h"
#include "GUI_Game_Warper.h"
#include "GUI_Reversi_Piece.h"
#include "GUI_Reversi_Box.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    const int width = QApplication::desktop()->width();
    const int height = QApplication::desktop()->height();
    const QRect rect = QApplication::desktop()->rect();

    const int left = rect.left();
    const int right = rect.right();
    const int bottom = rect.bottom();
    const int top = rect.top();

    // Création d'un widget qui servira de fenêtre
    QMainWindow* window = new QMainWindow();
    window->setMinimumWidth(320);
    window->setMaximumWidth(610);
    window->setMinimumHeight(320);
    window->setMaximumHeight(610);
    window->setGeometry((width-620)/2,(height-620)/2,610,610);
    //window->setStyleSheet("QMainWindow { background-color: blue; }");
    //GUI_Game_Warper* warper = new GUI_Game_Warper();
    //window->setCentralWidget(warper);
    GUI_Game_Container* container = new GUI_Game_Container();
    window->setCentralWidget(container);
    //warper->setWidget(container);
    //container->setMinimumWidth(300);
    //window->setWidgetResizable(true);

    QGridLayout* windowGrid = new QGridLayout(container);
    //window->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy(Qt::Min));

    GUI_Reversi_Board* reversiBoard = new GUI_Reversi_Board();
    reversiBoard->setStyleSheet("QWidget { background-color: #145E0D; }");
    windowGrid->addWidget(reversiBoard);



    GUI_Reversi_Board_Grid* reversiBoardGrid = new GUI_Reversi_Board_Grid();

    reversiBoard->setLayout(reversiBoardGrid);

    for(unsigned short int i = 0; i<8 ; i++){
        for(unsigned short int j = 0; j<8; j++){
            GUI_Reversi_Box* reversiBoardBox = new GUI_Reversi_Box();
            GUI_Reversi_Piece* reversiBoardBoxContent = new GUI_Reversi_Piece(reversiBoardBox);
            QObject::connect(reversiBoardBox,SIGNAL(clicked()),reversiBoardBoxContent,SLOT(reverse_slot()));
            reversiBoardGrid->addWidget(reversiBoardBox,i,j);
        }
    }

    // Affichage de la fenêtre
    //window->setLayout(windowGrid);
    window->show();

    return app.exec();
}

#include "GUI_Reversi_Piece.h"
#include <QtGlobal>
#include <QPainter>
#include <QResizeEvent>

QString GUI_Reversi_Piece::BLACK = "C:/Users/user/Qt Projets/reversi/black.png";
QString GUI_Reversi_Piece::WHITE = "C:/Users/user/Qt Projets/reversi/white.png";

GUI_Reversi_Piece::GUI_Reversi_Piece(){

    this->setGeometry(0,0,this->parentWidget()->width(),this->parentWidget()->height());
    QPixmap pawn;
    this->__state = qrand()%2;
    (this->__state)?(this->__img_file = GUI_Reversi_Piece::WHITE):
                (this->__img_file = GUI_Reversi_Piece::BLACK);
    pawn.load(this->__img_file);
    this->setPixmap(pawn);
    this->refresh();
}

GUI_Reversi_Piece::GUI_Reversi_Piece(QWidget* parent) : QLabel(parent){


    this->setGeometry(0,0,this->parentWidget()->width(),this->parentWidget()->height());
    QPixmap pawn;
    this->__state = qrand()%2;
    (this->__state)?(this->__img_file = GUI_Reversi_Piece::WHITE):
                (this->__img_file = GUI_Reversi_Piece::BLACK);
    pawn.load(this->__img_file);
    this->setPixmap(pawn);
    this->refresh();

}


GUI_Reversi_Piece& GUI_Reversi_Piece::reverse(){
    if(this->__state == 0){
        this->__state = 1;
        this->__img_file = GUI_Reversi_Piece::WHITE;
        this->refresh();
    }
    else if(this->__state == 1){
        this->__state = 0;
        this->__img_file = GUI_Reversi_Piece::BLACK;
        this->refresh();
    }
    return *this;
}

GUI_Reversi_Piece& GUI_Reversi_Piece::refresh(){
    QPixmap pawn1(this->__img_file);
    QPixmap pixmap(pawn1.scaled(55,55));
    this->setPixmap(pixmap);
    return *this;
}

void GUI_Reversi_Piece::reverse_slot(){
    this->reverse();
}

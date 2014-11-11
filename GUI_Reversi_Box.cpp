#include "GUI_Reversi_Box.h"
#include "GUI_Reversi_Piece.h"
GUI_Reversi_Box::GUI_Reversi_Box(){
    this->setFixedSize(55,55);
    this->setStyleSheet("QWidget { background-color: #16690F; }");
    this->clickable();
}


GUI_Reversi_Box& GUI_Reversi_Box::clickable(){
    this->setCursor(Qt::PointingHandCursor);
    return *this;
}

void GUI_Reversi_Box::mousePressEvent(QMouseEvent *event){
    emit this->clicked();
}

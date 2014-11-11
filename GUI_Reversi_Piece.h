#ifndef GUI_REVERSI_PIECE_H
#define GUI_REVERSI_PIECE_H

#include <QLabel>
#include <QObject>

class GUI_Reversi_Piece : public QLabel{
    Q_OBJECT
private:
    static QString BLACK;
    static QString WHITE;
    QString __img_file;
    unsigned short int __state;

public:
    GUI_Reversi_Piece();
    GUI_Reversi_Piece(QWidget* parent);
    GUI_Reversi_Piece& reverse();
    GUI_Reversi_Piece& refresh();

public slots:
    void reverse_slot();
};

#endif // GUI_REVERSI_PIECE_H

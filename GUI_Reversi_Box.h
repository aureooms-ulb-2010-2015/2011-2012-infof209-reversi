#ifndef GUI_REVERSI_BOX_H
#define GUI_REVERSI_BOX_H

#include <QWidget>

class GUI_Reversi_Box : public QWidget
{
    Q_OBJECT
public:
    GUI_Reversi_Box();
    GUI_Reversi_Box& clickable();

protected:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked();
};

#endif // GUI_REVERSI_BOX_H

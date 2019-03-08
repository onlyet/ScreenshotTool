#ifndef FRAMEVIEW_H
#define FRAMEVIEW_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include "Region.h"

class FrameView : public QWidget
{
	Q_OBJECT

public:
	FrameView(QWidget *parent);
	~FrameView();
    
	// 将截图区域分成九个矩形
	void CutIn9Parts();
    
protected:
	virtual void paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    virtual void leaveEvent(QEvent* event);

	// 判断点是否在截图区域内，返回矩形index
    int HitTest(const QPoint& pos);
    
signals:
    void RegionHoverd(int region);
    void RegionPressed(int region);
    void ViewDblClicked();

private:
	QPixmap m_pixmap;
	QRect m_rectParts[9];
    int m_padding;
};

#endif // FRAMEVIEW_H

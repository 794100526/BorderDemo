#include "MyBorderContainer.h"

//鼠标点击事件
void MyBorderContainer::MyBorder::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_bKeepDrag = true;
        m_mousePointOld = ev->globalPos();
    }
    return QWidget::mousePressEvent(ev);
}

//鼠标移动事件
void MyBorderContainer::MyBorder::mouseMoveEvent(QMouseEvent *ev)
{
   if(m_bKeepDrag)
   {
       const QPoint position = ev->globalPos() - m_mousePointOld; //the position of mainfrmae + (current_mouse_position - last_mouse_position)
           //move(position.x(), position.y());
       //emit moveEventSig(position);
       do
       {
           //判断距离回调是否被注册
           if (MouseMoveCallBack == nullptr)
           {
               break;
           }
           //执行回调通知事件
           (*MouseMoveCallBack)(position, MyType, MyContex);
       } while (0);
       m_mousePointOld = ev->globalPos();
   }
   return QWidget::mouseMoveEvent(ev);
}

//鼠标释放事件
void MyBorderContainer::MyBorder::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    m_bKeepDrag = false;
    return QWidget::mouseReleaseEvent(ev);
}

//设置回调函数
void MyBorderContainer::MyBorder::setMousMoveCallBack(CallBack callBack, BorderType type, void * contex)
{
    MouseMoveCallBack = callBack;
    MyType = type;
    MyContex = contex;
}

#ifndef GAUGESPEED_H
#define GAUGESPEED_H

/**
 * 速度仪表盘控件 作者:feiyangqingyun(QQ:517216493) 2016-10-17
 * 本控件来源于网络(原作者:青春岁月(http://www.qtcn.org/bbs/read-htm-tid-55604-ds-1.html#tpc))
 * 1:可设置各种颜色
 * 2:可启用动画效果显示
 * 3:可设置起始旋转角度及结束旋转角度
 * 4:可设置单位和标题
 * 5:可设置大刻度数量和小刻度数量
 * 6:增加一些完整性校验及改进部分算法
 */

#include <QWidget>

class GaugeSpeed: public QWidget
{
	Q_OBJECT
public:
	explicit GaugeSpeed(QWidget *parent = 0);
	~GaugeSpeed();

protected:
	void paintEvent(QPaintEvent *);
	void drawCrown(QPainter *painter);
	void drawBg(QPainter *painter);
	void drawScale(QPainter *painter);
	void drawScaleNum(QPainter *painter);
	void drawTitle(QPainter *painter);
	void drawValue(QPainter *painter);
	void drawIndicator(QPainter *painter);

private slots:
	void updateValue();

private:
	double value;           //目标值
	double maxValue;        //最小值
	double minValue;        //最大值
	int precision;          //精确度,小数点后几位

	QString unit;           //单位
	QString title;          //标题

	int scaleMajor;         //大刻度数量
	int scaleMinor;         //小刻度数量
	int startAngle;         //开始旋转角度
	int endAngle;           //结束旋转角度

	bool animation;         //是否启用动画显示
	double animationStep;   //动画显示时步长

	QColor crownColorStart; //外边框渐变开始颜色
	QColor crownColorEnd;   //外边框渐变结束颜色
	QColor foreground;      //前景色
	QColor background;      //背景色
	QColor pointerColor;    //指针颜色

    bool reverse;           //是否倒退
	double currentValue;    //当前值
	QTimer *timer;          //定时器绘制动画

public:
	double getValue() const
	{
		return value;
	}
	double getMinValue() const
	{
		return minValue;
	}
	double getMaxValue() const
	{
		return maxValue;
	}
	int getPrecision() const
	{
		return precision;
	}

	QString getUnit()const
	{
		return unit;
	}
	QString getTitle() const
	{
		return title;
	}

	int getScaleMajor() const
	{
		return scaleMajor;
	}
	int getScaleMinor() const
	{
		return scaleMinor;
	}
	int getStartAngle() const
	{
		return startAngle;
	}
	int getEndAngle() const
	{
		return endAngle;
	}

	bool getAnimation()const
	{
		return animation;
	}
	double getAnimationStep()const
	{
		return animationStep;
	}

	QColor getCrownColorStart()const
	{
		return crownColorStart;
	}
	QColor getCrownColorEnd()const
	{
		return crownColorEnd;
	}

	QColor getForeground()const
	{
		return foreground;
	}
	QColor getBackground()const
	{
		return background;
	}
	QColor getPointerColor()const
	{
		return pointerColor;
	}

public slots:
	//设置最大最小值-范围值
	void setRange(double minValue, double maxValue);
	void setRange(int minValue, int maxValue);

	//设置目标值
	void setValue(double value);
	void setValue(int value);

	//设置精确度
	void setPrecision(int precision);
	//设置单位
	void setUnit(QString unit);
	//设置标题
	void setTitle(QString title);

	//设置主刻度数量
	void setScaleMajor(int scaleMajor);
	//设置小刻度数量
	void setScaleMinor(int scaleMinor);
	//设置开始旋转角度
	void setStartAngle(int startAngle);
	//设置结束旋转角度
	void setEndAngle(int endAngle);

	//设置是否启用动画显示
	void setAnimation(bool animation);
	//设置动画显示的步长
	void setAnimationStep(double animationStep);

	//设置外边框渐变颜色
	void setCrownColor(QColor crownColorStart, QColor crownColorEnd);
	//设置前景色
	void setForeground(QColor foreground);
	//设备背景色
	void setBackground(QColor background);
	//设置指针颜色
	void setPointerColor(QColor pointerColor);

signals:
	void valueChanged(double value);
};

#endif //GAUGESPEED_H

#include "gaugespeed.h"
#include "qpainter.h"
#include "qmath.h"
#include "qtimer.h"
#include "qdebug.h"

GaugeSpeed::GaugeSpeed(QWidget *parent) : QWidget(parent)
{
	value = 0;
	minValue = 0;
	maxValue = 100;
	precision = 0;

	unit = "km/h";
	title = "时速表";

	scaleMajor = 10;
	scaleMinor = 10;
	startAngle = 60;
	endAngle = 60;

	animation = false;
	animationStep = 0.5;

	crownColorStart = QColor(255, 255, 255);
	crownColorEnd = QColor(166, 166, 166);
	foreground = QColor(255, 255, 255);
	background = QColor(65, 65, 65);
	pointerColor = QColor(160, 160, 160);

	reverse = false;
	currentValue = 0;
	timer = new QTimer(this);
	timer->setInterval(10);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));

	setFont(QFont("Arial", 7));
}

GaugeSpeed::~GaugeSpeed()
{
	if (timer->isActive()) {
		timer->stop();
	}
}

void GaugeSpeed::paintEvent(QPaintEvent *)
{
	int width = this->width();
	int height = this->height();

	//绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
    QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	painter.translate(width / 2, height / 2);

	int side = qMin(width, height);
	painter.scale(side / 200.0, side / 200.0);

	//绘制外边框
	drawCrown(&painter);
	//绘制背景
	drawBg(&painter);
	//绘制刻度线
	drawScale(&painter);
	//绘制刻度值
	drawScaleNum(&painter);
	//绘制标题
	drawTitle(&painter);
	//绘制当前值
	drawValue(&painter);
	//绘制指针
	drawIndicator(&painter);
}

void GaugeSpeed::drawCrown(QPainter *painter)
{
	int radius = 99;
	painter->save();
	painter->setPen(Qt::NoPen);
	QLinearGradient crownGradient(0, -radius, 0, radius);
	crownGradient.setColorAt(0, crownColorStart);
	crownGradient.setColorAt(1, crownColorEnd);
	painter->setBrush(crownGradient);
	painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
	painter->restore();
}

void GaugeSpeed::drawBg(QPainter *painter)
{
	int radius = 92;
	painter->save();
	painter->setPen(Qt::NoPen);
	painter->setBrush(background);
	painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
	painter->restore();
}

void GaugeSpeed::drawScale(QPainter *painter)
{
	int radius = 72;
	painter->save();
	painter->setPen(foreground);

	painter->rotate(startAngle);
	int steps = (scaleMajor * scaleMinor);
	double angleStep = (360.0 - startAngle - endAngle) / steps;

	QPen pen = painter->pen();
	pen.setCapStyle(Qt::RoundCap);

	for (int i = 0; i <= steps; i++) {
		if (i % scaleMinor == 0) {
			pen.setWidthF(1.5);
			painter->setPen(pen);
			painter->drawLine(0, radius - 10, 0, radius);
		} else {
			pen.setWidthF(0.5);
			painter->setPen(pen);
			painter->drawLine(0, radius - 5, 0, radius);
		}

		painter->rotate(angleStep);
	}

	painter->restore();
}

void GaugeSpeed::drawScaleNum(QPainter *painter)
{
	int radius = 82;
	painter->save();
	painter->setPen(foreground);

	double startRad = (360 - startAngle - 90) * (M_PI / 180);
	double deltaRad = (360 - startAngle - endAngle) * (M_PI / 180) / scaleMajor;

	for (int i = 0; i <= scaleMajor; i++) {
		double sina = sin(startRad - i * deltaRad);
		double cosa = cos(startRad - i * deltaRad);
		double value = 1.0 * i * ((maxValue - minValue) / scaleMajor) + minValue;

		QString strValue = QString("%1").arg((double)value, 0, 'f', precision);
		double textWidth = fontMetrics().width(strValue);
		double textHeight = fontMetrics().height();
		int x = radius * cosa - textWidth / 2;
		int y = -radius * sina + textHeight / 4;
		painter->drawText(x, y, strValue);
	}

	painter->restore();
}

void GaugeSpeed::drawTitle(QPainter *painter)
{
	painter->save();
	painter->setPen(foreground);
	painter->setFont(QFont("Microsoft Yahei", 10));
	double textWidth = painter->fontMetrics().width(title);
	painter->drawText(-textWidth / 2, -30, title);
	painter->restore();
}

void GaugeSpeed::drawValue(QPainter *painter)
{
	painter->save();
	painter->setPen(foreground);
	painter->setFont(QFont("Arial", 9));
	QString strValue = QString("%1 %2").arg(currentValue, 0, 'f', precision).arg(unit);
	double textWidth = painter->fontMetrics().width(strValue);
	painter->drawText(-textWidth / 2, 42, strValue);
	painter->restore();
}

void GaugeSpeed::drawIndicator(QPainter *painter)
{
	painter->save();
	QPolygon pts;
	pts.setPoints(3, -2, 0, 2, 0, 0, 60);

	painter->rotate(startAngle);
	double degRotate = (360.0 - startAngle - endAngle) / (maxValue - minValue) * (currentValue - minValue);

	//画指针
	painter->rotate(degRotate);
	QRadialGradient haloGradient(0, 0, 60, 0, 0);
	haloGradient.setColorAt(0, pointerColor.lighter(100));
	haloGradient.setColorAt(1, pointerColor);
	painter->setPen(foreground);
	painter->setBrush(haloGradient);
	painter->drawConvexPolygon(pts);
	painter->restore();

	//画中心点
	painter->save();
	QConicalGradient coneGradient(0, 0, -90.0);
	coneGradient.setColorAt(0.0, background);
	coneGradient.setColorAt(0.5, foreground);
	coneGradient.setColorAt(1.0, background);
	painter->setPen(Qt::NoPen);
	painter->setBrush(coneGradient);
	painter->drawEllipse(-5, -5, 10, 10);
	painter->restore();
}

void GaugeSpeed::updateValue()
{
	if (!reverse) {
		if (currentValue >= value) {
			timer->stop();
		} else {
			currentValue += animationStep;
		}
	} else {
		if (currentValue <= value) {
			timer->stop();
		} else {
			currentValue -= animationStep;
		}
	}

	update();
}

void GaugeSpeed::setRange(double minValue, double maxValue)
{
	//如果最小值大于或者等于最大值则不设置
	if (minValue >= maxValue) {
		return;
	}

	this->minValue = minValue;
	this->maxValue = maxValue;

	//如果目标值不在范围值内,则重新设置目标值
	if (value < minValue || value > maxValue) {
		setValue(value);
	}

	update();
}

void GaugeSpeed::setRange(int minValue, int maxValue)
{
	setRange((double)minValue, (double)maxValue);
}

void GaugeSpeed::setValue(double value)
{
	//值小于最小值或者值大于最大值或者值和当前值一致则无需处理
	if (value < minValue || value > maxValue || value == this->value) {
		return;
	}

	if (value > this->value) {
		reverse = false;
	} else if (value < this->value) {
		reverse = true;
	}

	this->value = value;
	emit valueChanged(value);

	if (!animation) {
		currentValue = this->value;
		update();
	} else {
		timer->start();
	}
}

void GaugeSpeed::setValue(int value)
{
	setValue((double)value);
}

void GaugeSpeed::setPrecision(int precision)
{
	//最大精确度为 3
	if (precision <= 3) {
		this->precision = precision;
		update();
	}
}

void GaugeSpeed::setUnit(QString unit)
{
	this->unit = unit;
	update();
}

void GaugeSpeed::setTitle(QString title)
{
	this->title = title;
	update();
}

void GaugeSpeed::setScaleMajor(int scaleMajor)
{
	this->scaleMajor = scaleMajor;
	update();
}

void GaugeSpeed::setScaleMinor(int scaleMinor)
{
	this->scaleMinor = scaleMinor;
	update();
}

void GaugeSpeed::setStartAngle(int startAngle)
{
	this->startAngle = startAngle;
	update();
}

void GaugeSpeed::setEndAngle(int endAngle)
{
	this->endAngle = endAngle;
	update();
}

void GaugeSpeed::setAnimation(bool animation)
{
	this->animation = animation;
	update();
}

void GaugeSpeed::setAnimationStep(double animationStep)
{
	this->animationStep = animationStep;
	update();
}

void GaugeSpeed::setCrownColor(QColor crownColorStart, QColor crownColorEnd)
{
	this->crownColorStart = crownColorStart;
	this->crownColorEnd = crownColorEnd;
	update();
}

void GaugeSpeed::setForeground(QColor foreground)
{
	this->foreground = foreground;
	update();
}

void GaugeSpeed::setBackground(QColor background)
{
	this->background = background;
	update();
}

void GaugeSpeed::setPointerColor(QColor pointerColor)
{
	this->pointerColor = pointerColor;
	update();
}

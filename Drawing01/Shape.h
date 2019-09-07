#pragma once
enum ElementType { NOTSET, SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };

class CShape : public CObject
{
public:
	CShape();
	virtual ~CShape();
	virtual void Draw(CDC*pDC) = 0;//绘制图元
	virtual bool IsMatched(CPoint pnt) = 0;//点是否落在图形内部
	virtual void Serialize(CArchive& ar) = 0;
	virtual void SetValue(ElementType t, int x, int y, int width, int height) = 0;//设置数据成员virtual void GetValue(ElementType &t,int &x,int &y,int &width,int &height)=0;//获取数据成员的值
	void SetPen(COLORREF bcolor, int btype, int bwidth);
	void GetPen(COLORREF &bcolor, int &btype, int &bwidth);
	void SetBrush(COLORREF fcolor, int ftype);
	void GetBrush(COLORREF &fcolor, int &ftype);
	virtual void GetValue(ElementType &t, int &x, int &y, int &width, int &height) = 0;//获取数据成员的值
protected:
	ElementType Type;//图元类型
	int OrgX;//原点坐标
	int OrgY;
	COLORREF   BorderColor;//边界颜色
	int BorderType;//边界线型--实线、虚线、虚点线等
	int BorderWidth;//边界宽度
	COLORREF  FillColor;//填充颜色
	int FillType;//填充类型--实心、双对角、十字交叉等
};

class CSquare : public CShape//正方形类CSquare
{
public:
	CSquare();
	CSquare(int x, int y, int w);
	void Draw(CDC*pDC);//绘制正方形
    bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	void SetValue(ElementType t, int x, int y, int width, int height);
	
	void GetValue(ElementType &t, int &x, int &y, int &width, int &height);
	
private:
	int width;//边长
    DECLARE_SERIAL(CSquare)//声明类CSquare支持序列化
	
};

class CRectangle : public CShape
{
public:
	CRectangle();
	CRectangle(int x, int y, int w, int h);
	void Draw(CDC*pDC);//绘制正方形
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	virtual void SetValue(ElementType t, int x, int y, int width, int height);//设置长方形对象中的部分数据成员（与画笔和画刷无关的）的值
	virtual void GetValue(ElementType &t, int &x, int &y, int &width, int &height);
	

private:
	int width;
	int height;
	COLORREF   BorderColor;//边界颜色
	int BorderType;//边界线型--实线、虚线、虚点线等
	int BorderWidth;//边界宽度
	COLORREF  FillColor;//填充颜色
	int FillType;//填充类型--实心、双对角、十字交叉
	DECLARE_SERIAL(CRectangle)//声明类CSquare支持序列化
};

class CTriangle : public CShape//三角形类CSquare
{
public:
	CTriangle();
	CTriangle(int x, int y, int w);
	void Draw(CDC*pDC);//绘制三角形
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化三角形图元
	~CTriangle();

	void SetValue(ElementType t, int x, int y, int width, int length);
	void GetValue(ElementType &t, int &x, int &y, int &width, int &length);
	


private:
	int width;//
	int length;
	DECLARE_SERIAL(CTriangle)//声明类CTriangle支持序列化
};

class Circle : public CShape//圆形类
{
public:
	Circle();
	Circle(int x, int y, int r);
	void Draw(CDC*pDC);//绘制圆形
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化圆形图元
	~Circle();

	void SetValue(ElementType t, int x, int y, int width, int length);
	void GetValue(ElementType &t, int &x, int &y, int &width, int &length);
	

private:
	int radius;//半径
	int width;
	int length;
	
	DECLARE_SERIAL(Circle)//声明类Circle支持序列化
};

class CEllipse : public CShape//椭圆类
{
public:
	CEllipse();
	CEllipse(int x, int y, int w, int l);
	void Draw(CDC*pDC);//绘制椭圆形
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化椭圆形图元
	~CEllipse();

	void SetValue(ElementType t, int x, int y, int width, int length);
	void GetValue(ElementType &t, int &x, int &y, int &width, int &length);
	
private:
	int width;//长和宽
	int length;

	DECLARE_SERIAL(CEllipse)//声明类CSquare支持序列化
};

class CText : public CShape//文本类
{
public:
	CText();
	CText(int x, int y, int h, int a, CString t);
	void Draw(CDC*pDC);//绘制文本
	bool IsMatched(CPoint pnt);//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化文本图元
	~CText();
	void SetValue(ElementType t, int x, int y, int width, int length);
	void GetValue(ElementType &t, int &x, int &y, int &width, int &length);
	
	void SetText(int m_text);
	void GetText(int m_text);
private:
	int height;//
	int angle;
	CString text;
	int width;
	int length;
	
	DECLARE_SERIAL(CText)//声明类CText支持序列化
};